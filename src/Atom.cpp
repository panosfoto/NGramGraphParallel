#include "Atom.hpp"


//
// template specialization for string atoms


// TODO : resolve multiple definition error
/*
template <>
bool Atom<std::string>::operator==(const Atom& other) const
{
    return this->payload.compare(other.payload) == 0;
}

template <>
std::string Atom<std::string>::toString()
{
    return payload;
}
*/


//
// template specialization for integer atoms

template <>
bool Atom<int>::operator==(const Atom& other) const
{
    return this->payload == other.payload;
}
