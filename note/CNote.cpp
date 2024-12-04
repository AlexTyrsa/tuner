#include "CNote.h"

CNote::CNote(const std::string &inName, int inFreq) : mName(inName), mFreq(inFreq), mSelected(false), mHighlighted(false)
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

bool CNote::selected() const
{
    return mSelected;
}

bool CNote::highlighted() const
{
    return mHighlighted;
}

void CNote::setSelected(bool inSelected)
{
    if(selected() != inSelected)
    {
        mSelected = inSelected;

        stateChanged();
    }
}

void CNote::setHighlighted(bool inHighlighted)
{
    if(highlighted() != inHighlighted)
    {
        mHighlighted = inHighlighted;

        stateChanged();
    }
}

void CNote::stateChanged()
{

}
