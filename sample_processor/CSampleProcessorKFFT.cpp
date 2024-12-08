#include "CSampleProcessorKFFT.h"

CSampleProcessorKFFT::CSampleProcessorKFFT() : mLevel(0.0), mFreq(0)
{

}

void CSampleProcessorKFFT::setSamples(float *inSamples, std::size_t inSampleCount)
{

    ready();
}

float CSampleProcessorKFFT::level() const
{
    return mLevel;
}

int CSampleProcessorKFFT::freq() const
{
    return mFreq;
}

void CSampleProcessorKFFT::ready()
{

}
