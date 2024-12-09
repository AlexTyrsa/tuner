#include "QDataHolder.h"

QDataHolder::QDataHolder(std::shared_ptr<CNotationI> inNotation, std::shared_ptr<CSampleProcessor> inSampleProcessor) : CDataHolder(inNotation, inSampleProcessor)
{

}

QNotation *QDataHolder::getNotation() const
{
    std::shared_ptr<CNotationI> notat = notation();

    return dynamic_cast<QNotation*>(notat.get());
}

QSampleProcessor *QDataHolder::getSampleProcessor() const
{
    std::shared_ptr<CSampleProcessor> proc = sampleProcessor();

    return dynamic_cast<QSampleProcessor*>(proc.get());
}
