/**
 * \file ProximityEvaluator.hpp
 */

#ifndef PROXIMITYEVALUATOR_H
#define PROXIMITYEVALUATOR_H


// project headers
#include "Atom.hpp"


/**
 * \Class An abstract class that describes a class that can evaluate if two Atoms are close.\n
 * Usage: Every ProximityGraph holds a ProximityEvaluator. When the ProximityGraph creates its graph, the ProximityEvaluator is used to identify which Atoms will be connected.
 */
template <typename AtomType>
class ProximityEvaluator
{
    public:
        /** Evaluates whether the 2 given atoms are "close". \n
         * Subclasses will define "close" depending on AtomType and desired functionality.
         *  \param atomA The first atom.
         *  \param atomB The second atom.
         */
        bool areClose(Atom<AtomType> atomA, Atom<AtomType> atomB) = 0;
};


#endif // PROXIMITYEVALUATOR_H
