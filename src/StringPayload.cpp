/**
 * \file StringPayload.cpp
 */

#include "StringPayload.hpp"

StringPayload::StringPayload()
{
    //ctor
}

StringPayload::StringPayload(std::string payloadValue)
{
    payload = payloadValue;
}

StringPayload::~StringPayload()
{
    //dtor
}

std::string StringPayload::toString()
{
    return payload;
}
