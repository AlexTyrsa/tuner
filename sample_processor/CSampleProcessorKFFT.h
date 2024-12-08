#include "CSampleProcessor.h"

class CSampleProcessorKFFT : public CSampleProcessor
{
public:
    CSampleProcessorKFFT();

    void setSamples(const float * inSamples, std::size_t inSampleCount) override;
    float level() const override;
    int freq() const override;

protected:
    void ready() override;

private:
    float mLevel;
    int mFreq;

};
