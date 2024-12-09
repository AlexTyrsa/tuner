#pragma once

#include "../notation/CNotation.h"

#include "QNote.h"
#include "QOctave.h"

#include <QObject>
#include <QQmlListProperty>

class QNotation : public QObject,
                  public CNotation
{
    Q_OBJECT

public:
    Q_PROPERTY(QOctave* selectedOctave READ selOctave NOTIFY changed)
    Q_PROPERTY(QNote*   selectedNote   READ selNote   NOTIFY changed)
    Q_PROPERTY(QQmlListProperty<QOctave> octaves READ getOctavesQML CONSTANT)

public:
    QNotation();

    QOctave* selOctave() const;
    QNote*   selNote() const;

    QQmlListProperty<QOctave> getOctavesQML();

    Q_INVOKABLE void requestSelectOctave(int inId) override;

signals:
    void changed();

protected slots:
    void stateChanged() override;

private:
    static qsizetype itemsCount(QQmlListProperty<QOctave>* inProperty);
    static QOctave *itemAt(QQmlListProperty<QOctave>* inProperty, qsizetype inIndex);

};
