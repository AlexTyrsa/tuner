#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QStandardPaths>
#include <QDir>

#include "factory/CFactoryJSON.h"

#include "qt_bundle/QNote.h"
#include "qt_bundle/QOctave.h"
#include "qt_bundle/QNotation.h"

#include "qt_bundle/QSampleProcessor.h"
#include "qt_bundle/QDataHolder.h"

#include "controller/CTunerController.h"

const char* cDataFileName = "data.json";

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationDomain("tuner_testapp");
    app.setApplicationName("tuner_testapp");

    QDir dataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    dataDir.mkpath(dataDir.absolutePath());
    QDir::setCurrent(dataDir.absolutePath());

    std::shared_ptr<CFactory> factory = std::make_shared<CFactoryJSON>("1.0");
    factory->setNoteCreator(CNoteI::create<QNote>);
    factory->setOctaveCreator(COctaveI::create<QOctave>);
    factory->setNotationCreator(CNotationI::create<QNotation>);

    std::shared_ptr<CNotationI> notation;

    QFile dataFile(cDataFileName);

    if(dataFile.exists() && dataFile.size() != 0)
    {
        QString data;
        dataFile.open(QIODevice::ReadOnly);
        data = dataFile.readAll();

        notation = factory->deserialize(data.toStdString());

        dataFile.close();
    }else
        notation = factory->createDefault();

    std::shared_ptr<CSampleProcessor> sampleProcessor = std::make_shared<QSampleProcessor>();
    std::shared_ptr<QDataHolder> data = std::make_shared<QDataHolder>(notation, sampleProcessor);

    std::shared_ptr<CTunerController> controller = std::make_shared<CTunerController>(data);
    controller->start();

    qmlRegisterType<QNote>("QTuneLib", 1, 0, "QNote");
    qmlRegisterType<QOctave>("QTuneLib", 1, 0, "QOctave");
    qmlRegisterType<QNotation>("QTuneLib", 1, 0, "QNotation");
    qmlRegisterType<QSampleProcessor>("QTuneLib", 1, 0, "QSampleProcessor");
    qmlRegisterType<QDataHolder>("QTuneLib", 1, 0, "QDataHolder");
    qmlRegisterSingletonInstance("QTuneLib", 1, 0, "TuneData", data.get());

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    int result = app.exec();

    dataFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    dataFile.write(factory->serialize(notation).c_str());

    return result;
}
