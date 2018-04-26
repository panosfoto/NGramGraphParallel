/**
 * \file Atom.h
 */
#ifndef ATOM_H
#define ATOM_H

#include <string>

/**
 * \Class Atom A class that represents an atom, the smallest entity of a DivisibleObject.
 *
 * Templates are used, so that it may contain whichever type of data is chosen each time.
 * \note When adding new classes, make sure to add/update corresponding template specialization
 */
template <class AtomType>
class Atom
{
    public:
        /** Default constructor */
        Atom(AtomType);
        /** Default destructor */
        virtual ~Atom();

        /**
         * Returns the Atom's data
         * \return payload AtomType payload is the data that the Atom holds
         */
        AtomType getPayload() { return payload; };

        std::string toString();
    protected:
        /** \var payload
         * Payload is the data that the Atom holds
         */
        AtomType payload;
};

#endif // ATOM_H
