#pragma once

#include <string>
#include <memory>

class COctaveI;
class CNoteI;

class CNotationI
{
public:
    virtual std::shared_ptr<COctaveI> octave_index(int inIndex) const = 0;
    virtual std::shared_ptr<COctaveI> octave_id(int inId) const = 0;

    virtual void requestSelectOctave(int inId) = 0;
    virtual void requestSelectNote(int inOctaveId, int inNoteId) = 0;

    virtual std::shared_ptr<COctaveI> selectedOctave() const = 0;
    virtual std::shared_ptr<CNoteI> selectedNote() const = 0;

    virtual std::size_t size() const = 0;
    virtual bool empty() const = 0;

    virtual ~CNotationI() = default;

};