/**
 * \file Atom.cpp
 */
#include <sstream>

/**
 * Constructor for Atom class.
 * \param initialValue AtomType
 * The data that the Atom will hold
 */
template <class AtomType>
Atom<AtomType>::Atom(AtomType initialValue)
{
    payload = initialValue;
}

/**
 * Destructor for Atom class.
 */
template <class AtomType>
Atom<AtomType>::~Atom()
{
    //dtor
}

/**
 * Provide a readable representation (string) of the data that the Atom holds
 * \return Returns a string made by the payload
 */
template <class AtomType>
std::string Atom<AtomType>::toString()
{
    std::ostringstream ss;
    ss << payload;
    return ss.str();
}
