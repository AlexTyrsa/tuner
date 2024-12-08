#include "CSampleProcessorKFFT.h"

#include "kiss_fft.h"
#include "kiss_fftr.h"

#include <vector>

#include <iostream>

CSampleProcessorKFFT::CSampleProcessorKFFT() : mLevel(0.0), mFreq(0), mSampleRate(0)
{

}

void CSampleProcessorKFFT::setSamples(const float *inSamples, std::size_t inSampleCount)
{
    kiss_fftr_cfg forwardConfig;
    std::vector<kiss_fft_cpx> spectrum(inSampleCount);
    std::size_t spectrumSize = inSampleCount / 2 + 1;

    forwardConfig = kiss_fftr_alloc(inSampleCount, 0, NULL, NULL);

    kiss_fftr(forwardConfig, inSamples, spectrum.data());

    float maxMag = 0;

    for(int i = 0; i < spectrumSize; ++i)
    {
        float mag = hypotf(spectrum[i].r, spectrum[i].i);
        float freq = i*(int)sampleRate() / inSampleCount;

        if(mag > maxMag)
        {
            maxMag = mag;
            mFreq = freq;
        }
    }

    free(forwardConfig);

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

int CSampleProcessorKFFT::sampleRate() const
{
    return mSampleRate;
}

void CSampleProcessorKFFT::setSampleRate(int inSampleRate)
{
    mSampleRate = inSampleRate;
}

CSampleProcessorKFFT::~CSampleProcessorKFFT()
{
    kiss_fft_cleanup();
}

void CSampleProcessorKFFT::ready()
{
    std::cout << level() << " " << freq() << std::endl;
}
