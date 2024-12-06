#include "CNote.h"

CNote::CNote(ENoteId inId, EOctaveId inOctaveId, const std::string &inName, int inFreq) : mId(inId), mOctaveId(inOctaveId), mName(inName), mFreq(inFreq), mSelected(false), mHighlighted(false)
{

}

std::string CNote::name() const
{
    return mName;
}

int CNote::freq() const
{
    return mFreq;
}

ENoteId CNote::id() const
{
    return mId;
}

EOctaveId CNote::octave() const
{
    return mOctaveId;
}

bool CNote::selected() const
{
    return mSelected;
}

void CNote::setSelected(bool inSelected)
{
    if(selected() != inSelected)
    {
        mSelected = inSelected;

        selectChanged();
    }
}

void CNote::selectChanged()
{

}
