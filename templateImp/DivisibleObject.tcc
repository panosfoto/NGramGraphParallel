/**
 * \file DivisibleObject.tcc
 */

template <class DivisibleObjectType>
DivisibleObject::DivisibleObject(DivisibleObject object)
{
    //ctor
}

template <class DivisibleObjectType>
DivisibleObject::~DivisibleObject()
{
    //dtor
}

template <class DivisibleObjectType>
DivisibleObject::DivisibleObject(const DivisibleObject& other)
{
    //copy ctor
}

template <class DivisibleObjectType>
DivisibleObject& DivisibleObject::operator=(const DivisibleObject& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
