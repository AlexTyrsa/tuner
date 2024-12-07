#pragma once

#include "../CNoteDefs.h"

#include <memory>
#include <functional>
#include <string>

class CNoteI;
class COctaveI;
class CNotationI;

class CFactory
{
public:
    CFactory(const std::string& inVersion);

    std::string version() const;

    void setNoteCreator(std::function<std::shared_ptr<CNoteI>(ENoteId,EOctaveId,const std::string&, int)> inCreateNote);
    void setOctaveCreator(std::function<std::shared_ptr<COctaveI>(EOctaveId,const std::string&)> inCreateOctave);
    void setNotationCreator(std::function<std::shared_ptr<CNotationI>()> inCreateNotation);

    virtual std::string serialize(std::shared_ptr<CNotationI> inNotation) = 0;
    virtual std::shared_ptr<CNotationI> deserialize(const std::string& inData) = 0;
    virtual std::shared_ptr<CNotationI> createDefault();

    virtual ~CFactory() = default;

protected:
    std::shared_ptr<CNoteI> createNote(ENoteId inId, EOctaveId inOctaveId, const std::string& inName, int inFreq);
    std::shared_ptr<COctaveI> createOctave(EOctaveId inOctaveId, const std::string& inName);
    std::shared_ptr<CNotationI> createNotation();

private:
    const std::string mVersion;

    std::function<std::shared_ptr<CNoteI>(ENoteId,EOctaveId,const std::string&, int)> mCreateNote;
    std::function<std::shared_ptr<COctaveI>(EOctaveId,const std::string&)> mCreateOctave;
    std::function<std::shared_ptr<CNotationI>()> mCreateNotation;

};
