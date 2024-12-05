#pragma once

#include <string>
#include <memory>

class CNoteI;

class COctaveI
{
public:
    virtual std::string name() const = 0;

    virtual std::shared_ptr<CNoteI> note(int inIndex) const = 0;
    virtual std::shared_ptr<CNoteI> nearest(int inFreq, int inDelta) const = 0;

    virtual std::size_t size() const = 0;
    virtual bool empty() const = 0;

    virtual int freqFrom() const = 0;
    virtual int freqTo() const = 0;

    virtual ~COctaveI() = default;

};
