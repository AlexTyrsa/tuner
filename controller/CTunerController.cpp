#include "CTunerController.h"

#include "../notation/CNotation.h"
#include "../sample_processor/CSampleProcessor.h"
#include "../data_holder/CDataHolder.h"

CTunerController::CTunerController(std::shared_ptr<CDataHolder> inData) : mData(inData)
{

}

std::shared_ptr<CDataHolder> CTunerController::data() const
{
    return mData;
}

void CTunerController::handleAudioData(const float *inData, qint64 inLen)
{
    data()->sampleProcessor()->setSamples(inData, inLen);
}
