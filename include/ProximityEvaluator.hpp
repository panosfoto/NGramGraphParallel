/**
 * \file ProximityEvaluator.hpp
 *
 * \author Panagiotis Fotopoulos
 *
 * \copyright Copyright 2018 NCSR Demokritos Greece \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. \n
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
        virtual bool areClose(Atom<AtomType> atomA, Atom<AtomType> atomB) = 0;
};


#endif // PROXIMITYEVALUATOR_H
