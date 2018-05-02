/**
 * \file Atom.cpp
 */
#include <sstream>

template <class AtomType>
Atom<AtomType>::Atom(AtomType initialValue)
{
    payload = initialValue;
}

template <class AtomType>
Atom<AtomType>::~Atom()
{
    //dtor
}

template <class AtomType>
std::string Atom<AtomType>::toString()
{
    std::ostringstream ss;
    ss << payload;
    return ss.str();
}
