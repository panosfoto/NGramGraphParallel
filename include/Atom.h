/**
 * \file Atom.h
 */

#ifndef ATOM_H
#define ATOM_H

#include <string>


/**
 * \Class A class that represents an atom, the smallest entity of a DivisibleObject.
 *
 * Templates are used, so that it may contain whichever type of data is chosen each time.
 * \note When adding new classes, make sure to add/update corresponding template specialization
 */
template <typename AtomType>
class Atom
{
    public:
        /**
         * Constructor for Atom class.
         * \param initialValue The data that the Atom will hold
         *
         */
        Atom(AtomType initialValue);


        /** Default destructor for Atom class */
        virtual ~Atom();


        /**
         * Returns the Atom's data
         * \return payload AtomType payload is the data that the Atom holds
         */
        AtomType getPayload() { return payload; };


        /**
         * Provide a readable representation (string) of the data that the Atom holds
         * \return Returns a string made by the payload
         */
        std::string toString();


        /**
         * Compares the Atom with another Atom instance
         * \param other A reference to an Atom instance to be compared with
         * \return A boolean value: True if the two Atoms are identical, otherwise False
         * \note Should be type-based overwritten (template specialization) to compare correctly depending on type used.
         */
        bool operator==(const Atom& other);


    protected:
        /** \var payload
         * Payload is the data that the Atom holds
         */
        AtomType payload;
};

#include "Atom.tcc"

#endif // ATOM_H
