/**
 * \file StringAtom.cpp
 */

#include "StringAtom.hpp"

StringAtom::StringAtom(std::string s) : Atom<std::string> (s)
{
    //ctor
}

StringAtom::~StringAtom()
{
    //dtor
}

bool StringAtom::operator==(const StringAtom& other) const
{
    return this->data.compare(other.data) == 0;
}
