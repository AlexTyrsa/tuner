#pragma once

#include "CNoteI.h"

class CNote : public CNoteI
{
public:
    CNote(ENoteId inId, EOctaveId inOctaveId, const std::string& inName, int inFreq);

    std::string name() const override;
    int  freq() const override;
    ENoteId id() const override;
    EOctaveId octave() const override;

    bool selected() const override;
    void setSelected(bool inSelected) override;

protected:
    virtual void selectChanged();

private:
    const ENoteId mId;
    const EOctaveId mOctaveId;
    const std::string mName;
    const int mFreq;

    bool mSelected;

};
