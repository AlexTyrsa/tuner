#include "QNotation.h"

QNotation::QNotation()
{

}

QOctave *QNotation::selOctave() const
{
    std::shared_ptr<COctaveI> note = selectedOctave();

    if(note)
        return dynamic_cast<QOctave*>(note.get());
    else
        return nullptr;
}

QNote *QNotation::selNote() const
{
    std::shared_ptr<CNoteI> note = selectedNote();

    if(note)
        return dynamic_cast<QNote*>(note.get());
    else
        return nullptr;
}

QQmlListProperty<QOctave> QNotation::getOctavesQML()
{
    return QQmlListProperty<QOctave>(this, this, &QNotation::itemsCount, &QNotation::itemAt);
}

void QNotation::stateChanged()
{
    CNotation::stateChanged();

    emit changed();
}

qsizetype QNotation::itemsCount(QQmlListProperty<QOctave> *inProperty)
{
    return reinterpret_cast<QNotation*>(inProperty->data)->size();
}

QOctave *QNotation::itemAt(QQmlListProperty<QOctave> *inProperty, qsizetype inIndex)
{
    std::shared_ptr<COctaveI> octave = reinterpret_cast<QNotation*>(inProperty->data)->octave_index(inIndex);

    return dynamic_cast<QOctave*>(octave.get());
}

