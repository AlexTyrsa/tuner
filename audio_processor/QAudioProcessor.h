#pragma once

#include <QAudioSource>
#include <QIODevice>

class QAudioProcessor : public QIODevice
{
    Q_OBJECT

public:
    QAudioProcessor(QObject* parent = nullptr);

    void start();

protected:
    virtual void handleAudioData(const float* inData, qint64 inLen) = 0;

private:
    qint64 readData(char *data, qint64 maxlen);
    qint64 bytesAvailable() const;
    qint64 writeData(const char *data, qint64 len);

private:
    QAudioSource* mAudioIn;

};
