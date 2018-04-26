#include "Atom.h"

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
