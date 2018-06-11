/**
 * \file NGramGraph.hpp
 */

#ifndef NGRAMGRAPH_H
#define NGRAMGRAPH_H

// project headers
#include "ProximityGraph.hpp"
#include "StringSplitter.hpp"

// defines
#define NGRAMSIZE_DEFAULT_VALUE 3
#define CORRELATIONWINDOW_DEFAULT_VALUE 3



/**
 * \Class A class that represents a N-gram graph.
 *
 * A N-gram graph is a ProximityGraph for strings that are split into N-grams.
 * The graph's Atoms are N-grams, and they are connected iff they are close enough (according to the CorrelationWindow) inside the string.
 */
class NGramGraph : public ProximityGraph<std::string, std::string>
{
    public:
        /** Default constructor.
         * CorrelationWindow is set to CORRELATIONWINDOW_DEFAULT_VALUE.
         * NGramSize is set to NGRAMSIZE_DEFAULT_VALUE.
         */
        NGramGraph();



        /** Constructor that initializes the CorrelationWindow and NGramSize variables.
         *  \param CorrelationWindowValue The new value for the CorrelationWindow variable.
         *  \param NGramSizeValue The new value for the NGramSize variable.
         */
        NGramGraph(ProximityEvaluator<std::string> *newProximityEvaluator, StringSplitter *newSplitter, StringPayload *newPayload, unsigned int CorrelationWindowValue);



        /** Default destructor */
        virtual ~NGramGraph();



        /** Accessor for CorrelationWindow variable.
         * \return The current value of the CorrelationWindow variable.
         */
        unsigned int getCorrelationWindow() { return CorrelationWindow; }



        /** Mutator for CorrelationWindow variable.
         * \param CorrelationWindowValue The new value for the CorrelationWindow variable.
         */
        void setCorrelationWindow(unsigned int CorrelationWindowValue) { CorrelationWindow = CorrelationWindowValue; }



        /**
         * Creates the graph used internally by the ProximityGraph, according to the CorrelationWindow.
         */
        void createGraph();



    protected:

        /**
         * \var CorrelationWindow The maximum distance of terms to be considered as correlated. Default is 3.
         *
         */
        unsigned int CorrelationWindow;



        /** Creates (or updates) an edge from vHead vertex to each vertex in the neighbors vector.
         * \param vHead The vertex from which the edges begin.
         * \param neighbors A vector containing the vertices who will be the tails of the edges.
         */
        void createEdgesToNeighbors(Graph(std::string)::vertex_descriptor vHead, vector<typename Graph(std::string)::vertex_descriptor> neighbors);



// DEPRECATED: Using the splitter->atomSize variable instead
//        /**
//         * \var NGramSize The size of the n-grams. Default is 3.
//         *
//         */
//        unsigned int NGramSize;
};

#endif // NGRAMGRAPH_H
