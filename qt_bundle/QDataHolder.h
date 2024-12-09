#pragma once

#include "../data_holder/CDataHolder.h"

#include "QNotation.h"
#include "QSampleProcessor.h"

#include <QObject>

class QDataHolder : public QObject,
                    public CDataHolder
{
    Q_OBJECT

public:
    Q_PROPERTY(QNotation* notation READ getNotation CONSTANT)
    Q_PROPERTY(QSampleProcessor* sampleProcessor READ getSampleProcessor CONSTANT)

public:
    QDataHolder(std::shared_ptr<CNotationI> inNotation, std::shared_ptr<CSampleProcessor> inSampleProcessor);

    QNotation *getNotation() const;
    QSampleProcessor* getSampleProcessor() const;

};
