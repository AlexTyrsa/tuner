#include "QAudioProcessor.h"

#include <QMediaDevices>
#include <QAudioDevice>

QAudioProcessor::QAudioProcessor(QObject *parent) : QIODevice(parent)
{
    QAudioDevice info = QMediaDevices::defaultAudioInput();

    QAudioFormat format;
    format.setSampleRate(cSampleRate);
    format.setChannelCount(1);
    format.setSampleFormat(QAudioFormat::Float);

    mAudioIn = new QAudioSource(info, format, this);
    mAudioIn->setVolume(1.0);
}

void QAudioProcessor::start()
{
    this->open(QIODeviceBase::WriteOnly);
    mAudioIn->start(this);
}

QAudioProcessor::~QAudioProcessor()
{
    mAudioIn->stop();
}

void QAudioProcessor::handleAudioData(const float *inData, qint64 inLen)
{

}

qint64 QAudioProcessor::writeData(const char *data, qint64 len)
{
    const float* floatBuf = reinterpret_cast<const float*>(data);
    const qint64 floatBufLen = len / sizeof(float);

    handleAudioData(floatBuf, floatBufLen);

    return floatBufLen * sizeof(float);
}

qint64 QAudioProcessor::readData(char *data, qint64 maxlen)
{
    return 0;
}

qint64 QAudioProcessor::bytesAvailable() const
{
    return 0;
}

