/**
 * \file ProximityGraph.hpp
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

#ifndef PROXIMITYGRAPH_HPP
#define PROXIMITYGRAPH_HPP


// project headers
#include "UniqueVertexGraph.hpp"
#include "ProximityEvaluator.hpp"
#include "Payload.hpp"
#include "Splitter.hpp"

// defines
#define EDGE_WEIGHT_DEFAULT_VALUE 1.0



/**
 * \Class A class that represents a weighted proximity graph with unique vertices.
 * A ProximityGraph needs a ProximityEvaluator, a Splitter and a payload, “whole” item that can be broken down into Atoms, which will be the vertices of the graph.
 * It uses the Splitter to split the payload into Atoms, and then uses the ProximityEvaluator to identify which Atoms should be connected.
 */
template <typename PayloadType, typename AtomType>
class ProximityGraph : public UniqueVertexGraph<AtomType>
{
    public:
        /** Default constructor. */
        ProximityGraph();



        /** Constructor that initializes the evaluator, the splitter and the payload.
         * \param newEvaluator The new ProximityEvaluator for the ProximityGraph.
         * \param newSplitter The new splitter for the ProximityGraph.
         * \param newPayload The new payload (data) that the graph will hold.
         */
        ProximityGraph(ProximityEvaluator<AtomType> *newEvaluator, Splitter<PayloadType, AtomType> *newSplitter, Payload<PayloadType> *newPayload);



        /** Default destructor */
        virtual ~ProximityGraph();



        /** Mutator for evaluator variable.
         * \param newEvaluator The new ProximityEvaluator for the ProximityGraph.
         */
        void setProximityEvaluator(ProximityEvaluator<AtomType> *newEvaluator) { evaluator = newEvaluator; }



        /** Mutator for splitter variable.
         * \param newSplitter The new splitter for the ProximityGraph.
         */
        void setSplitter(Splitter<PayloadType, AtomType> *newSplitter) { splitter = newSplitter; }



        /** Mutator for payload variable.
         * \param newPayload The new payload (data) that the graph will hold.
         */
        void setPayload(Payload<PayloadType> *newPayload) { payload = newPayload; }



        /**
         * Creates the graph used internally by the ProximityGraph, according to the CorrelationWindow.
         */
        virtual void createGraph();



    protected:

        /**
         * \var evaluator The proximity evaluator that will be used in createGraphs to evaluate which Atoms will be connected.
         *
         */
        ProximityEvaluator<AtomType> *evaluator;



        /**
         * \var splitter The splitter that will be used to break the payload into Atoms.
         *
         */
        Splitter<PayloadType, AtomType> *splitter;



        /**
         * \var payload The data that the graph holds, which will be split into Atoms.
         *
         */
        Payload<PayloadType> *payload;
};


// template implementation file
#include "templateImp/ProximityGraph.tcc"


#endif // PROXIMITYGRAPH_HPP
