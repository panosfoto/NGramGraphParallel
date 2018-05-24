/**
 * \file Atom.hpp
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
        // Parameter-less constructor added to avoid errors with boost property initialization:
        // Atom used as template parameter, and by default it calls a parameter less constructor.
        // TODO : check if there is a way to bypass this (e.g. providing an empty string ("") as default parameter).
        /**
         * Constructor for Atom class.
         * \note Payload is not initialized with this constructor, setPayload() should be used to avoid undefined behavior by uninitialized payloads.
         */
        Atom() {}


        /**
         * Constructor for Atom class.
         * \param initialValue The data that the Atom will hold
         *
         */
        Atom(AtomType initialValue);


        /** Default destructor for Atom class */
        virtual ~Atom();


        /**
         * Returns the Atom's data.
         * \return payload payload is the data that the Atom holds.
         */
        AtomType getPayload() const { return payload; };


        /**
         * Updates the Atom's data.
         * \param newPayload The new data that the Atom will be holding.
         */
        void setPayload(AtomType newPayload) { payload = newPayload; };


        /**
         * Provide a readable representation (string) of the data that the Atom holds
         * \return Returns a string made by the payload.
         */
        std::string toString();


        /**
         * Compares the Atom with another Atom instance.
         * \param other A reference to an Atom instance to be compared with.
         * \return A boolean value: True if the two Atoms are identical, otherwise False.
         * \note Should be type-based overwritten (template specialization) to compare correctly depending on type used.
         */
        bool operator==(const Atom& other) const;


        /**
         * Assignment operator for Atom instances.
         * \param aSource A reference to the source Atom instance, whose values will be assigned to this.
         * \note Should be type-based overwritten (template specialization) to assign correctly depending on type used.
         */
        void operator=(const Atom& aSource);


    protected:
        /** \var payload
         * Payload is the data that the Atom holds
         */
        AtomType payload;
};


#include "Atom.tcc"


#endif // ATOM_H
