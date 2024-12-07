#include "COctave.h"

#include "../note/CNoteI.h"

#include <cassert>

COctave::COctave(EOctaveId inId, const std::string &inName) : mId(inId), mName(inName)
{

}

std::string COctave::name() const
{
    return mName;
}

EOctaveId COctave::id() const
{
    return mId;
}

std::shared_ptr<CNoteI> COctave::note_index(int inIndex) const
{
    assert(inIndex >= 0 && inIndex < size());

    if(inIndex >= 0 && inIndex < size())
        return mNotes[inIndex];
    else
        return std::shared_ptr<CNoteI>();
}

std::shared_ptr<CNoteI> COctave::note_id(int inId) const
{
    assert(inId >= ENoteId_Begin && inId < ENoteId_End);

    std::vector<std::shared_ptr<CNoteI>>::const_iterator result = std::find_if(mNotes.cbegin(), mNotes.cend(), [inId](std::shared_ptr<CNoteI> note)->bool
    {
        return note->id() == inId;
    });

    if(result != mNotes.cend())
        return *result;
    else
        return std::shared_ptr<CNoteI>();
}

std::shared_ptr<CNoteI> COctave::nearest(int inFreq) const
{
    assert(inFreq >= 0);

    return std::shared_ptr<CNoteI>();
}

bool COctave::selected() const
{
    return mSelected;
}

void COctave::setSelected(bool inSelected)
{
    if(selected() != inSelected)
    {
        mSelected = inSelected;

        stateChanged();
    }
}

void COctave::requestSelectNote(int inId)
{
    assert(inId >= ENoteId_Begin && inId < ENoteId_End);

    for(int i = 0; i < size(); ++i)
    {
        std::shared_ptr<CNoteI> note = note_index(i);
        if(note->id() == inId)
            note->setSelected(true);
        else
            note->setSelected(false);
    }
}

std::shared_ptr<CNoteI> COctave::selectedNote() const
{
    std::vector<std::shared_ptr<CNoteI>>::const_iterator result = std::find_if(mNotes.cbegin(), mNotes.cend(), [](std::shared_ptr<CNoteI> note)->bool
    {
        return note->selected();
    });

    if(result != mNotes.cend())
        return *result;
    else
        return std::shared_ptr<CNoteI>();
}

void COctave::clearNoteSelection()
{
    std::for_each(mNotes.begin(), mNotes.end(), [](std::shared_ptr<CNoteI> note)->void
    {
        note->setSelected(false);
    });
}

bool COctave::haveSelectedNote() const
{
    return selectedNote() !=  nullptr;
}

std::size_t COctave::size() const
{
    return mNotes.size();
}

bool COctave::empty() const
{
    return size() == 0;
}

int COctave::freqFrom() const
{
    if(!empty())
        return mNotes.front()->freq();
    else
        return 0;
}

int COctave::freqTo() const
{
    if(!empty())
        return mNotes.back()->freq();
    else
        return 0;
}

void COctave::addNote(std::shared_ptr<CNoteI> inNote)
{
    assert(inNote);

    if(inNote)
    {
        mNotes.push_back(inNote);

        int index = size() - 1;
        while(index > 0 && mNotes[index]->freq() < mNotes[index - 1]->freq())
        {
            std::swap(mNotes[index], mNotes[index - 1]);
            --index;
        }
    }
}

void COctave::stateChanged()
{

}
