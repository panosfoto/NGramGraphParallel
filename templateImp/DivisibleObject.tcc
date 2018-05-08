/**
 * \file DivisibleObject.tcc
 */

template <class DivisibleObjectType>
DivisibleObject<DivisibleObjectType>::DivisibleObject(DivisibleObjectType object)
{
    this->payload = object;
    splitPayloadToAtoms();
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
void DivisibleObject<DivisibleObjectType>::splitPayloadToAtoms()
{
    //TODO: not implemented
}
