#pragma once

#include "../audio_processor/QAudioProcessor.h"
//#include "../data_holder/CDataHolder.h"

class CDataHolder;

class CTunerController : public QAudioProcessor
{
    Q_OBJECT

public:
    CTunerController(std::shared_ptr<CDataHolder> inData);

    std::shared_ptr<CDataHolder> data() const;

protected:
    void handleAudioData(const float* inData, qint64 inLen) override;

private:
    std::shared_ptr<CDataHolder> mData;

};
