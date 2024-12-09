#include "QSampleProcessor.h"

QSampleProcessor::QSampleProcessor()
{

}

void QSampleProcessor::ready()
{
    CSampleProcessorKFFT::ready();

    emit changed();
}
