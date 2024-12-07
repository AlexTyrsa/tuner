#pragma once

#include "CFactory.h"

class CFactoryJSON : public CFactory
{
public:
    CFactoryJSON(const std::string& inVersion);

    std::string serialize(std::shared_ptr<CNotationI> inNotation) override;
    std::shared_ptr<CNotationI> deserialize(const std::string& inData) override;

};
