#include "CNotation.h"

#include "../octave/COctave.h"

#include <cassert>

CNotation::CNotation()
{

}

std::shared_ptr<COctaveI> CNotation::octave_index(int inIndex) const
{
    assert(inIndex >= 0 && inIndex < size());

    if(inIndex >= 0 && inIndex < size())
        return mOctaves[inIndex];
    else
        return std::shared_ptr<COctaveI>();
}

std::shared_ptr<COctaveI> CNotation::octave_id(int inId) const
{
    assert(inId >= EOctaveId_Begin && inId < EOctaveId_End);

    std::vector<std::shared_ptr<COctaveI>>::const_iterator result = std::find_if(mOctaves.cbegin(), mOctaves.cend(), [inId](std::shared_ptr<COctaveI> note)->bool
    {
        return note->id() == inId;
    });

    if(result != mOctaves.cend())
        return *result;
    else
        return std::shared_ptr<COctaveI>();
}

void CNotation::requestSelectOctave(int inId)
{
    assert(inId >= ENoteId_Begin && inId < ENoteId_End);

    for(int i = 0; i < size(); ++i)
    {
        std::shared_ptr<COctaveI> octave = octave_index(i);
        if(octave->id() == inId)
            octave->setSelected(true);
        else
            octave->setSelected(false);
    }

    stateChanged();
}

void CNotation::requestSelectNote(int inOctaveId, int inNoteId)
{
    assert(inNoteId >= ENoteId_Begin && inNoteId < ENoteId_End);
    assert(inOctaveId >= EOctaveId_Begin && inOctaveId < EOctaveId_End);

    for(int i = 0; i < size(); ++i)
    {
        std::shared_ptr<COctaveI> octave = octave_index(i);
        if(octave->id() == inOctaveId)
            octave->requestSelectNote(inNoteId);
        else
            octave->clearNoteSelection();
    }

    stateChanged();
}

std::shared_ptr<COctaveI> CNotation::selectedOctave() const
{
    std::vector<std::shared_ptr<COctaveI>>::const_iterator result = std::find_if(mOctaves.cbegin(), mOctaves.cend(), [](std::shared_ptr<COctaveI> octave)->bool
    {
        return octave->selected();
    });

    if(result != mOctaves.cend())
        return *result;
    else
        return std::shared_ptr<COctaveI>();
}

std::shared_ptr<CNoteI> CNotation::selectedNote() const
{
    for(int i = 0; i < size(); ++i)
    {
        std::shared_ptr<CNoteI> note = octave_index(i)->selectedNote();
        if(note)
            return note;
    }

    return std::shared_ptr<CNoteI>();
}

std::shared_ptr<CNoteI> CNotation::nearest(int inFreq) const
{
    assert(inFreq >= 0);

    for(std::vector<std::shared_ptr<COctaveI>>::const_iterator i = mOctaves.cbegin(); i != mOctaves.end(); ++i)
    {
        std::shared_ptr<CNoteI> note = (*i)->nearest(inFreq);

        if(note)
            return note;
    }

    return std::shared_ptr<CNoteI>();
}

std::size_t CNotation::size() const
{
    return mOctaves.size();
}

bool CNotation::empty() const
{
    return size() == 0;
}

void CNotation::addOctave(std::shared_ptr<COctaveI> inOctave)
{
    assert(inOctave);

    if(inOctave)
    {
        mOctaves.push_back(inOctave);

        int index = size() - 1;
        while(index > 0 && mOctaves[index]->freqFrom() < mOctaves[index - 1]->freqFrom())
        {
            std::swap(mOctaves[index], mOctaves[index - 1]);
            --index;
        }
    }
}

void CNotation::stateChanged()
{

}
