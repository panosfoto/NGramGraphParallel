/**
 * \file ProximityGraph.hpp
 */

#ifndef PROXIMITYGRAPH_HPP
#define PROXIMITYGRAPH_HPP

// project headers
#include "UniqueVertexGraph.hpp"


// defines
#define CORRELATIONWINDOW_DEFAULT_VALUE 3


/**
 * \Class An abstract class that represents a weighted proximity graph with unique vertices.
 * A ProximityGraph needs a proximity measure and a “whole” item that can be broken down into Atoms.
 * For a given correlation window it can examine all the vertex pairs and connect the appropriate ones with a weighted edge.
 */
template <typename AtomType>
class ProximityGraph : public UniqueVertexGraph<AtomType>
{
    public:
        /** Default constructor. CorrelationWindow is set to CORRELATIONWINDOW_DEFAULT_VALUE. */
        ProximityGraph();



        /** Constructor that initializes the CorrelationWindow variable */
        ProximityGraph(unsigned int CorrelationWindowValue);



        /** Default destructor */
        virtual ~ProximityGraph();



        /** Accessor for CorrelationWindow variable.
         */
        unsigned int getCorrelationWindow() { return CorrelationWindow; }



        /** Mutator for CorrelationWindow variable.
         * \param CorrelationWindowValue The new value for the CorrelationWindow variable.
         */
        void setCorrelationWindow(unsigned int CorrelationWindowValue) { CorrelationWindow = CorrelationWindowValue; }



        /**
         * Returns the size of the payload, according to the payload type and divider type.\n
         * For example, if the payload is a string (e.g. a text) and the divider splits it to character n-grams, this function will return the length of the string.
         * If the divider splits the string to word n-grams, the return value will be the number of words in the text.
         * \return The size of the payload.
         */
        virtual unsigned int getPayloadSize() = 0;



        /**
         * Creates the graph used internally by the ProximityGraph, according to the CorrelationWindow.
         */
        virtual void createGraph() = 0;



    protected:

        /**
         * \var CorrelationWindow The maximum distance of terms to be considered as correlated. Default is 3.
         *
         */
        unsigned int CorrelationWindow;
};


// template implementation file
#include "ProximityGraph.tcc"


#endif // PROXIMITYGRAPH_HPP
