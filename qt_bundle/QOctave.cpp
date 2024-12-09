#include "QOctave.h"

QOctave::QOctave(EOctaveId inId, const std::string &inName) : COctave(inId, inName)
{

}

QString QOctave::getName() const
{
    return name().c_str();
}

QNote *QOctave::selNote() const
{
    std::shared_ptr<CNoteI> note = selectedNote();

    if(note)
        return dynamic_cast<QNote*>(note.get());
    else
        return nullptr;
}

QQmlListProperty<QNote> QOctave::getItemsQML()
{
    return QQmlListProperty<QNote>(this, this, &QOctave::itemsCount, &QOctave::itemAt);
}

void QOctave::stateChanged()
{
    COctave::stateChanged();

    emit changed();
}

qsizetype QOctave::itemsCount(QQmlListProperty<QNote> *inProperty)
{
    return reinterpret_cast<QOctave*>(inProperty->data)->size();
}

QNote *QOctave::itemAt(QQmlListProperty<QNote> *inProperty, qsizetype inIndex)
{
    std::shared_ptr<CNoteI> note = reinterpret_cast<QOctave*>(inProperty->data)->note_index(inIndex);

    return dynamic_cast<QNote*>(note.get());
}
