/**
 * \file ProximityGraph.hpp
 */

#ifndef PROXIMITYGRAPH_HPP
#define PROXIMITYGRAPH_HPP

// project headers
#include "UniqueVertexGraph.hpp"
#include "ProximityEvaluator.hpp"
#include "Splitter.hpp"



/**
 * \Class A class that represents a weighted proximity graph with unique vertices.
 * A ProximityGraph needs a ProximityEvaluator, a Splitter and a payload, “whole” item that can be broken down into Atoms, which will be the vertices of the graph.
 * It uses the Splitter to split the payload into Atoms, and then uses the ProximityEvaluator to identify which Atoms should be connected.
 */
template <typename AtomType>
class ProximityGraph : public UniqueVertexGraph<AtomType>
{
    public:
        /** Default constructor. */
        ProximityGraph();



        /** Default destructor */
        virtual ~ProximityGraph();



        /** Mutator for evaluator variable.
         * \param newEvaluator The new ProximityEvaluator for the ProximityGraph.
         */
        void setProximityEvaluator(ProximityEvaluator<AtomType> *newEvaluator) { evaluator = newEvaluator; }



        /** Mutator for splitter variable.
         * \param newSplitter The new splitter for the ProximityGraph.
         */
        void setSplitter(Splitter<AtomType> *newSplitter) { splitter = newSplitter; }



        /**
         * Creates the graph used internally by the ProximityGraph, according to the CorrelationWindow.
         */
        virtual void createGraph() = 0;



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
        Splitter<AtomType> *splitter;
};


// template implementation file
#include "ProximityGraph.tcc"


#endif // PROXIMITYGRAPH_HPP
