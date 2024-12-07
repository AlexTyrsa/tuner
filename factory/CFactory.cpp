#include "CFactory.h"

#include <cassert>

CFactory::CFactory(const std::string& inVersion) : mVersion(inVersion)
{

}

std::string CFactory::version() const
{
    return mVersion;
}

void CFactory::setNoteCreator(std::function<std::shared_ptr<CNoteI> (ENoteId, EOctaveId, const std::string &, int)> inCreateNote)
{
    mCreateNote = inCreateNote;
}

void CFactory::setOctaveCreator(std::function<std::shared_ptr<COctaveI> (EOctaveId, const std::string &)> inCreateOctave)
{
    mCreateOctave = inCreateOctave;
}

void CFactory::setNotationCreator(std::function<std::shared_ptr<CNotationI> ()> inCreateNotation)
{
    mCreateNotation = inCreateNotation;
}

std::shared_ptr<CNoteI> CFactory::createNote(ENoteId inNoteId, EOctaveId inOctaveId, const std::string& inName, int inFreq)
{
    assert(!mCreateNote);

    if(mCreateNote)
        return mCreateNote(inNoteId, inOctaveId, inName, inFreq);
    else
        return std::shared_ptr<CNoteI>();
}

std::shared_ptr<COctaveI> CFactory::createOctave(EOctaveId inOctaveId, const std::string &inName)
{
    assert(!mCreateOctave);

    if(mCreateOctave)
        return mCreateOctave(inOctaveId, inName);
    else
        return std::shared_ptr<COctaveI>();
}

std::shared_ptr<CNotationI> CFactory::createNotation()
{
    assert(!mCreateNotation);

    if(mCreateNotation)
        return mCreateNotation();
    else
        return std::shared_ptr<CNotationI>();
}
