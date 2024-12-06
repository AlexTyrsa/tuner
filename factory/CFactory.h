#pragma once

#include "../CNoteDefs.h"

#include <memory>
#include <functional>

class CNoteI;
class COctaveI;
class CNotationI;

class CFactory
{
public:
    CFactory();

    void setNoteCreator(std::function<std::shared_ptr<CNoteI>(ENoteId,EOctaveId,const std::string&, int)> inCreateNote);
    void setOctaveCreator(std::function<std::shared_ptr<COctaveI>(EOctaveId,const std::string&)> inCreateOctave);
    void setNotationCreator(std::function<std::shared_ptr<CNotationI>()> inCreateNotation);

    virtual std::shared_ptr<CNotationI> create() = 0;

    virtual ~CFactory() = default;

protected:
    std::shared_ptr<CNoteI> createNote(ENoteId inId, EOctaveId inOctaveId, const std::string& inName, int inFreq);
    std::shared_ptr<COctaveI> createOctave(EOctaveId inOctaveId, const std::string& inName);
    std::shared_ptr<CNotationI> createNotation();

private:
    std::function<std::shared_ptr<CNoteI>(ENoteId,EOctaveId,const std::string&, int)> mCreateNote;
    std::function<std::shared_ptr<COctaveI>(EOctaveId,const std::string&)> mCreateOctave;
    std::function<std::shared_ptr<CNotationI>()> mCreateNotation;

};
