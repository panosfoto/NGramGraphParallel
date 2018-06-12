/**
 * \file Atom.tcc
 */

#include <sstream>


template <typename AtomType>
Atom<AtomType>::Atom(AtomType initialValue)
{
    data = initialValue;
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
    ss << data;
    return ss.str();
}



template <typename AtomType>
bool Atom<AtomType>::operator==(const Atom& other) const
{
    return this->data == other.data;
}



template <typename AtomType>
void Atom<AtomType>::operator=(const Atom& aSource)
{
    this->data = aSource.data;
}



namespace std {

    template <typename AtomType>
    struct hash<Atom<AtomType>>
    {
        std::size_t operator()(const Atom<AtomType>& a) const
        {
            return hash<AtomType>()(a.getData());
        }
    };

}
