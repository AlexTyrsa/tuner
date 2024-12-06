#pragma once

#include "../CNoteDefs.h"

#include <string>
#include <memory>

class CNoteI
{
public:
    virtual std::string name() const = 0;
    virtual int freq() const = 0;
    virtual ENoteId id() const = 0;
    virtual EOctaveId octave() const = 0;

    virtual bool selected() const = 0;
    virtual bool highlighted() const = 0;

    virtual void setSelected(bool inSelected) = 0;
    virtual void setHighlighted(bool inHighlighted) = 0;

    virtual ~CNoteI() = default;

public:
    template <typename CNoteT>
    static std::shared_ptr<CNoteI> create(ENoteId inId, EOctaveId inOctaveId, const std::string& inName, int inFreq)
    {
        return std::make_shared<CNoteT>(inId, inOctaveId, inName, inFreq);
    }

};
