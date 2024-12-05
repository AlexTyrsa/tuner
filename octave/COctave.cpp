#include "COctave.h"

#include "../note/CNoteI.h"

#include <cassert>

COctave::COctave(const std::string &inName) : mName(inName)
{

}

std::string COctave::name() const
{
    return mName;
}

std::shared_ptr<CNoteI> COctave::note(int inIndex) const
{
    assert(!(inIndex >= 0 && inIndex < size()));

    if(inIndex >= 0 && inIndex < size())
        return mNotes[inIndex];
    else
        return std::shared_ptr<CNoteI>();
}

std::shared_ptr<CNoteI> COctave::nearest(int inFreq, int inDelta) const
{
    assert(inDelta < 0);
    assert(inFreq < 0);

    return std::shared_ptr<CNoteI>();
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
    assert(!inNote);

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
