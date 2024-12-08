#pragma once

#include <memory>

class CNotationI;
class CSampleProcessor;

class CDataHolder
{
public:
    CDataHolder(std::shared_ptr<CNotationI> inNotation, std::shared_ptr<CSampleProcessor> inSampleProcessor);

    std::shared_ptr<CNotationI> notation() const;
    std::shared_ptr<CSampleProcessor> sampleProcessor() const;

private:
    std::shared_ptr<CNotationI> mNotation;
    std::shared_ptr<CSampleProcessor> mSampleProcessor;

};
