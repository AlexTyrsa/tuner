#pragma once

#include <cstddef>

class CSampleProcessor
{
public:
    virtual void setSamples(const float * inSamples, std::size_t inSampleCount) = 0;
    virtual float level() const = 0;
    virtual int freq() const = 0;

    virtual ~CSampleProcessor() = default;

protected:
    virtual void ready() = 0;

};
