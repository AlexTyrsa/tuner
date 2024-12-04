#pragma once

#include "CNoteI.h"

class CNote : public CNoteI
{
public:
    CNote(const std::string& inName, int inFreq);

    std::string name() const override;
    int freq() const override;
    bool selected() const override;
    bool highlighted() const override;

    void setSelected(bool inSelected) override;
    void setHighlighted(bool inHighlighted) override;

protected:
    virtual void stateChanged() override;

private:
    std::string mName;
    int mFreq;
    bool mSelected;
    bool mHighlighted;

};
