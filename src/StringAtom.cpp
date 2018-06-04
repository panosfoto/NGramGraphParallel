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
    return this->payload.compare(other.payload) == 0;
}
