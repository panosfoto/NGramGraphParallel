#include "Atom.hpp"



// template specialization for string atoms
template <>
bool Atom<std::string>::operator==(const Atom& other)
{
    return this->payload.compare(other.payload) == 0;
}

// template specialization for integer atoms
template <>
bool Atom<int>::operator==(const Atom& other)
{
    return this->payload == other.payload;
}
