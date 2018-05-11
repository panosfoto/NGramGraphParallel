#include "Atom.h"



// template specialization for string atoms
template <>
bool Atom<std::string>::operator==(const Atom& other)
{
    return this->payload.compare(other.payload) == 0;
}

bool Atom<int>::operator==(const Atom& other)
{
    return this->payload == other.payload;
}
