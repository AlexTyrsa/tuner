#pragma once

#include "CNotationI.h"

#include <vector>

class CNotation : public CNotationI
{
public:
    CNotation();

    std::shared_ptr<COctaveI> octave_index(int inIndex) const override;
    std::shared_ptr<COctaveI> octave_id(int inId) const override;

    void requestSelectOctave(int inId) override;
    void requestSelectNote(int inOctaveId, int inNoteId) override;

    std::shared_ptr<COctaveI> selectedOctave() const override;
    std::shared_ptr<CNoteI> selectedNote() const override;

    std::size_t size() const override;
    bool empty() const override;

    void addOctave(std::shared_ptr<COctaveI> inOctave);

private:
    std::vector<std::shared_ptr<COctaveI>> mOctaves;

};
