#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QStandardPaths>
#include <QDir>

#include "factory/CFactoryJSON.h"
#include "note/CNote.h"
#include "notation/CNotation.h"
#include "octave/COctave.h"

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
    factory->setNoteCreator(CNoteI::create<CNote>);
    factory->setOctaveCreator(COctaveI::create<COctave>);
    factory->setNotationCreator(CNotationI::create<CNotation>);

    std::shared_ptr<CNotationI> notation;

    QFile dataFile(cDataFileName);

    if(dataFile.exists() && dataFile.size() != 0)
    {
        QString data;
        dataFile.open(QIODevice::ReadOnly);
        data = dataFile.readAll();

        notation = factory->deserialize(data.toStdString());
        //notation = factory->createDefault();

        dataFile.close();
    }else
        notation = factory->createDefault();

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    int result = app.exec();

    dataFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    dataFile.write(factory->serialize(notation).c_str());

    return result;
}
