/**
 * \file Atom.tcc
 */

#include <sstream>


template <typename AtomType>
Atom<AtomType>::Atom(AtomType initialValue)
{
    payload = initialValue;
}



template <typename AtomType>
Atom<AtomType>::~Atom()
{
    //dtor
}



template <typename AtomType>
std::string Atom<AtomType>::toString()
{
    std::ostringstream ss;
    ss << payload;
    return ss.str();
}



template <typename AtomType>
bool Atom<AtomType>::operator==(const Atom& other)
{
    return this->payload == other.payload;
}



template <>
bool Atom<std::string>::operator==(const Atom& other)
{
    return this->payload.compare(other.payload) == 0;
}
