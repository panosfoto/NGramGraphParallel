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
bool Atom<AtomType>::operator==(const Atom& other) const
{
    return this->payload == other.payload;
}



template <typename AtomType>
void Atom<AtomType>::operator=(const Atom& aSource)
{
    this->payload = aSource.payload;
}



namespace std {

    template <typename AtomType>
    struct hash<Atom<AtomType>>
    {
        std::size_t operator()(const Atom<AtomType>& a) const
        {
            return hash<AtomType>()(a.getPayload());
        }
    };

}
