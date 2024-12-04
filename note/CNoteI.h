#pragma once

#include <string>

class CNoteI
{
public:
    virtual std::string name() const = 0;
    virtual int freq() const = 0;
    virtual bool selected() const = 0;
    virtual bool highlighted() const = 0;

    virtual void setSelected(bool inSelected) = 0;
    virtual void setHighlighted(bool inHighlighted) = 0;

    virtual ~CNoteI() = default;

protected:
    virtual void stateChanged() = 0;

};
