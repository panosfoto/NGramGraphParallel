/**
 * \file DivisibleObject.h
 */

#ifndef DIVISIBLEOBJECT_H
#define DIVISIBLEOBJECT_H


/**
 * \Class DivisibleObject A class that represents an object that can be split into Atoms
 *
 */
template <class DivisibleObjectType>
class DivisibleObject
{
    public:
        /**
         * Constructor for DivisibleObject class.
         * \param object The original object that will be split into Atoms.
         *
         */
        DivisibleObject(DivisibleObjectType object);

        /**
         * Destructor for DivisibleObject class.
         *
         */
        virtual ~DivisibleObject();

        /**
         * Copy constructor for DivisibleObject class.
         * \param other The original DivisibleObject which will be copied.
         *
         */
        DivisibleObject(const DivisibleObject& other);

        /**
         * Assignment operator for DivisibleObject class.
         * \param other The DivisibleObject which will be copied.
         *
         */
        DivisibleObject& operator=(const DivisibleObject& other);

    protected:
};

#include "DivisibleObject.tcc"

#endif // DIVISIBLEOBJECT_H
