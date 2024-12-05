#pragma once

#include "COctaveI.h"

#include <vector>

class COctave: public COctaveI
{
public:
    COctave(const std::string& inName);

    std::string name() const override;

    std::shared_ptr<CNoteI> note(int inIndex) const override;
    std::shared_ptr<CNoteI> nearest(int inFreq, int inDelta) const override;

    std::size_t size() const override;
    bool empty() const override;

    int freqFrom() const override;
    int freqTo() const override;

    void addNote(std::shared_ptr<CNoteI> inNote);

private:
    std::string mName;
    std::vector<std::shared_ptr<CNoteI>> mNotes;

};
