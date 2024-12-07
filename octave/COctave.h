#pragma once

#include "COctaveI.h"

#include <vector>

class COctave: public COctaveI
{
public:
    COctave(EOctaveId inId, const std::string& inName);

    std::string name() const override;
    EOctaveId id() const override;

    std::shared_ptr<CNoteI> note_index(int inIndex) const override;
    std::shared_ptr<CNoteI> note_id(int inId) const override;
    std::shared_ptr<CNoteI> nearest(int inFreq) const override;

    bool selected() const override;
    void setSelected(bool inSelected) override;

    void requestSelectNote(int inId) override;
    std::shared_ptr<CNoteI> selectedNote() const override;
    void clearNoteSelection() override;
    bool haveSelectedNote() const override;

    std::size_t size() const override;
    bool empty() const override;

    int freqFrom() const override;
    int freqTo() const override;

    void addNote(std::shared_ptr<CNoteI> inNote) override;

protected:
    virtual void stateChanged();

private:
    const EOctaveId mId;
    const std::string mName;
    std::vector<std::shared_ptr<CNoteI>> mNotes;

    bool mSelected;

};
