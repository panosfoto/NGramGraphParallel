/**
 * \file Divider.hpp
 */

#ifndef DIVIDER_H
#define DIVIDER_H

#include "Atom.hpp"
#include <vector>

using namespace std;


/**
 * \Class An abstract class working as an interface that describes a Divider, a class holds an object (payload) on demand divides (splits) it into Atoms.\n
 * Usage: Every N-gram graph holds a Divider instance. The graph can order the Divider to split the payload it holds to atoms, retrieve the atoms, and create a node for every atom created.
 * \note No payload defined variable in the abstract superclass. Sub-classes must  define their own payload variable, according to the type they are working with.
 */
template <typename AtomType>
class Divider
{
    public:
        /** \brief Accessor for atoms variable
         * \return The DivisibleObject's atoms vector
         */
        vector<Atom<AtomType>> getAtoms(){ return atoms; }



        /**
         * Provide a readable representation (string) of the data (payload) that the Divider holds.
         * \return Returns a string representing the Divider's payload.
         */
        virtual std::string toString() = 0;



        /**
         * Provide a readable representation (string) of the data that the Divider's Atoms hold.
         * \return Returns a vector containing the string representation of each Atom.
         */
        virtual vector<std::string> atomsToString() = 0;



        /**
         * Splits the DivisibleObject's payload to Atoms with AtomSize size, filling the atoms vector.
         * \note Must be type-based overwritten (template specialization) to do the splitting according to the type used.
         */
        virtual void splitPayloadToAtoms() = 0;



    protected:
        /** \var atoms
         * A vector that holds the smallest pieces (atoms) of payload after it has been split.
         */
        vector<Atom<AtomType>> atoms;



};


#endif // DIVIDER_H
