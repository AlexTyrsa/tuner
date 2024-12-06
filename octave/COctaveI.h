#pragma once

#include "../CNoteDefs.h"

#include <string>
#include <memory>

class CNoteI;

class COctaveI
{
public:
    virtual std::string name() const = 0;
    virtual EOctaveId id() const = 0;

    virtual std::shared_ptr<CNoteI> note_index(int inIndex) const = 0;
    virtual std::shared_ptr<CNoteI> note_id(int inId) const = 0;
    virtual std::shared_ptr<CNoteI> nearest(int inFreq) const = 0;

    virtual bool selected() const = 0;
    virtual void setSelected(bool inSelected) = 0;

    virtual void requestSelectNote(int inId) = 0;
    virtual std::shared_ptr<CNoteI> selectedNote() const = 0;
    virtual void clearNoteSelection() = 0;
    virtual bool haveSelectedNote() const = 0;

    virtual std::size_t size() const = 0;
    virtual bool empty() const = 0;

    virtual int freqFrom() const = 0;
    virtual int freqTo() const = 0;

    virtual ~COctaveI() = default;

public:
    template <typename COctaveT>
    static std::shared_ptr<COctaveI> create(EOctaveId inOctaveId, const std::string& inName)
    {
        return std::make_shared<COctaveT>(inOctaveId, inName);
    }

};
