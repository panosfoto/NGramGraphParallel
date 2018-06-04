/**
 * \file Splitter.hpp
 */

#ifndef SPLITTER_H
#define SPLITTER_H


// system headers
#include <vector>

// project headers
#include "Atom.hpp"

// defines
#define ATOMSIZE_DEFAULT_VALUE 3


using namespace std;


/**
 * \Class An abstract class working as an interface that describes a Splitter, a class that can split a payload into Atoms.\n
 * Usage: Every proximity graph holds a Splitter. The graph can order the Splitter to split its payload into atoms and create a node for every atom created.
 * \note No payload defined variable in this abstract superclass. Sub-classes must define their own payload variable, according to the type they are going to work with.
 */
template <typename AtomType>
class Splitter
{
    public:
        /**
         * Default constructor. atomSize set to ATOMSIZE_DEFAULT_VALUE.
         */
        Splitter(){ atomSize = ATOMSIZE_DEFAULT_VALUE; }



        /**
         * Constructor that initializes atomSize.
         * \param atomSizeValue The new value for the atomSize variable.
         */
        Splitter(unsigned int atomSizeValue){ atomSize = atomSizeValue; }



        /** Mutator for atomSize variable.
         * \param setValue The new atom size that the StringToCharDivider will split its payload to.
         */
        void setAtomSize(unsigned int newAtomSizeValue){ this->atomSize = newAtomSizeValue; }



        /** Accessor for atomSize variable.
         * \return Current atom size that the StringToCharDivider will split its payload to.
         */
        unsigned int getAtomSize(){ return atomSize; }



        /**
         * Provide a readable representation (string) of the data (payload) that the Splitter holds.
         * \return A string representing the Splitter's payload.
         */
        virtual std::string toString() = 0;



        /**
         * Splits the payload to Atoms, and returns the result in a vector.
         * \return A vector with the Atoms to which the payload was split.
         */
        virtual vector<Atom<AtomType>> splitPayloadToAtoms() = 0;



    protected:
        /** \var atomSize
         * The length of each atom.\n
         * Defaults to ATOMSIZE_DEFAULT_VALUE.
         */
        unsigned int atomSize;
};


#endif // SPLITTER_H
