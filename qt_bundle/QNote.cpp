#include "QNote.h"

QNote::QNote(ENoteId inId, EOctaveId inOctaveId, const std::string &inName, int inFreq) : CNote(inId, inOctaveId, inName, inFreq)
{

}

QString QNote::getName() const
{
    return name().c_str();
}

void QNote::selectChanged()
{
    CNote::selectChanged();

    emit changed();
}
