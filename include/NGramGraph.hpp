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
#define EDGE_WEIGHT_DEFAULT_VALUE 1.0


/**
 * \Class A class that represents a N-gram graph.
 *
 * A N-gram graph is an entity that holds a Divider entity and a graph.
 * The StringToCharDivider splits the data it holds into N-gram Atoms,
 * and with those N-grams the N-gram graph creates the graph.
 * The graph's vertices are the Atoms, and the edges indicate neighboring Atoms (according to the CorrelationWindow).
 */
class NGramGraph : public ProximityGraph<std::string>
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
        NGramGraph(unsigned int CorrelationWindowValue, unsigned int NGramSizeValue);



        /** Default destructor */
        virtual ~NGramGraph();



        /**
         * Returns the size of the payload, according to the payload type and divider type.\n
         * For example, if the payload is a string (e.g. a text) and the divider splits it to character n-grams, this function will return the length of the string.
         * If the divider splits the string to word n-grams, the return value will be the number of words in the text.
         * \return The size of the payload.
         */
        unsigned int getPayloadSize();



        /** Accessor for payload variable.
         */
        std::string getPayload() { return divider.getPayload(); }



        /** Mutator for payload variable.
         * \param newPayload The new value for the payload variable.
         */
        void setPayload(std::string newPayload) { divider.setPayload(newPayload); }



        /** Accessor for NGramSize variable.
         */
        unsigned int getNGramSize() { return divider.getAtomSize(); }



        /** Mutator for NGramSize variable.
         * \param newNGramSize The new value for the NGramSize variable.
         */
        void setNGramSize(unsigned int newNGramSize) { divider.setAtomSize(newNGramSize); }



        /**
         * Creates the graph used internally by the ProximityGraph, according to the CorrelationWindow.
         */
        void createGraph();



    protected:

        /**
         * \var divider The data that the graph holds and splits to Atoms (n-grams) to create the graph(s).
         *
         */
        StringSplitter divider;



        /** Creates (or updates) an edge from vHead vertex to each vertex in the neighbors vector.
         * \param vHead The vertex from which the edges begin.
         * \param neighbors A vector containing the vertices who will be the tails of the edges.
         */
        void createEdgesToNeighbors(Graph(std::string)::vertex_descriptor vHead, vector<typename Graph(std::string)::vertex_descriptor> neighbors);



// DEPRECATED: Using the divider.atomSize variable instead
//        /**
//         * \var NGramSize The size of the n-grams. Default is 3.
//         *
//         */
//        unsigned int NGramSize;
};

#endif // NGRAMGRAPH_H
