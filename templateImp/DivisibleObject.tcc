/**
 * \file DivisibleObject.tcc
 */

template <class DivisibleObjectType>
DivisibleObject::DivisibleObject(DivisibleObjectType object)
{
    this->payload = object;
    splitPayloadToAtoms();
}

template <class DivisibleObjectType>
DivisibleObject::DivisibleObject(const DivisibleObject& sourceDivisibleObject)
{
    //copy ctor
    //TODO: not implemented
}

template <class DivisibleObjectType>
DivisibleObject::~DivisibleObject()
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
DivisibleObject::operator==(const DivisibleObject& rhDivisibleObject)
{
    //TODO: not implemented
    return true;
}

template <class DivisibleObjectType>
void DivisibleObject::splitPayloadToAtoms()
{
    //TODO: not implemented
}
