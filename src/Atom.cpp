#include "Atom.h"
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

// explicit instantiations:
// other possible way is to include the .cpp file in the end of the header
template class Atom<int>;
template class Atom<std::string>;
