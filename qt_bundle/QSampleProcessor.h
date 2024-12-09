#pragma once

#include "sample_processor/CSampleProcessorKFFT.h"

#include <QObject>

class QSampleProcessor : public QObject,
                         public CSampleProcessorKFFT
{
    Q_OBJECT

public:
    Q_PROPERTY(float level READ level NOTIFY changed)
    Q_PROPERTY(int   freq READ freq NOTIFY changed)

public:
    QSampleProcessor();

protected:
    void ready() override;

signals:
    void changed();

};

