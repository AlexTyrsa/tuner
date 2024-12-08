#include "CDataHolder.h"

CDataHolder::CDataHolder(std::shared_ptr<CNotationI> inNotation, std::shared_ptr<CSampleProcessor> inSampleProcessor) : mNotation(inNotation), mSampleProcessor(inSampleProcessor)
{

}

std::shared_ptr<CNotationI> CDataHolder::notation() const
{
    return mNotation;
}

std::shared_ptr<CSampleProcessor> CDataHolder::sampleProcessor() const
{
    return mSampleProcessor;
}
