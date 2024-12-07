#include "CFactoryJSON.h"

#include "CFactoryDefaults.h"

std::string CFactoryJSON::serialize(std::shared_ptr<CNotationI> inNotation)
{
    return std::string();
}

std::shared_ptr<CNotationI> CFactoryJSON::deserialize(const std::string &inData)
{
    return std::shared_ptr<CNotationI>();
}

std::shared_ptr<CNotationI> CFactoryJSON::createDefault()
{
    return std::shared_ptr<CNotationI>();
}
