/**
 * \file DivisibleObject.tcc
 */

#include <sstream>
using namespace std;

template <class DivisibleObjectType>
DivisibleObject<DivisibleObjectType>::DivisibleObject(DivisibleObjectType object)
{
    this->payload = object;
}

template <class DivisibleObjectType>
DivisibleObject<DivisibleObjectType>::DivisibleObject(const DivisibleObject& sourceDivisibleObject)
{
    //copy ctor
    //TODO: not implemented
}

template <class DivisibleObjectType>
DivisibleObject<DivisibleObjectType>::~DivisibleObject()
{
    //dtor
    //TODO: not implemented
}
/*
template <class DivisibleObjectType>
DivisibleObject& DivisibleObject::operator=(const DivisibleObject& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
*/
template <class DivisibleObjectType>
bool DivisibleObject<DivisibleObjectType>::operator==(const DivisibleObject& rhDivisibleObject)
{
    //TODO: not implemented
    return true;
}

template <class DivisibleObjectType>
void DivisibleObject<DivisibleObjectType>::splitPayloadToAtoms(unsigned int AtomSize)
{
    // This function should always be specialized, so the generic function throws an error
    cerr << "Error: splitPayloadToAtoms() not specialized for this class/type." << endl;
    //exit(-1);
}

// template specialization for string payload/atoms
template <>
void DivisibleObject<string>::splitPayloadToAtoms(unsigned int AtomSize)
{
    if (AtomSize > payload.length())
    {
        cerr << "splitPayloadToAtoms(): Error: atom size provided is greater than the length of the payload. Payload could not be split." << endl;
        return;
    }
    string tempString;
    Atom<string> *tempAtom;
    //test implementation
    for(unsigned int i = 0 ; i < payload.length()-AtomSize+1 ; ++i)
    {
        tempString.clear();
        for(unsigned int j = 0 ; j < AtomSize ; ++j)
        {
            tempString.push_back(payload[i+j]);
        }
        tempString.push_back('\0');
        tempAtom = new Atom<string>(tempString);
        atoms.push_back(*tempAtom);
    }
}

template <class DivisibleObjectType>
string DivisibleObject<DivisibleObjectType>::toString()
{
    ostringstream ss;
    ss << payload;
    return ss.str();
}

template <class DivisibleObjectType>
vector<string> DivisibleObject<DivisibleObjectType>::atomsToString()
{
    vector<string> returnVector;
    for(typename vector<Atom<DivisibleObjectType>>::iterator it = atoms.begin() ; it != atoms.end() ; ++it)
    {
        returnVector.push_back((*it).toString());
    }
    return returnVector;
}
