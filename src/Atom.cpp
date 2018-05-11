#include "Atom.hpp"


//
// template specialization for string atoms

template <>
bool Atom<std::string>::operator==(const Atom& other)
{
    return this->payload.compare(other.payload) == 0;
}

// TODO : resolve multiple definition error
/*
template <>
std::string Atom<std::string>::toString()
{
    return payload;
}
*/


//
// template specialization for integer atoms

template <>
bool Atom<int>::operator==(const Atom& other)
{
    return this->payload == other.payload;
}
