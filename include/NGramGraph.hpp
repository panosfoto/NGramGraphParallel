/**
 * \file NGramGraph.hpp
 */

#ifndef NGRAMGRAPH_H
#define NGRAMGRAPH_H

#include "StringToCharDivider.hpp"
#include <boost/graph/directed_graph.hpp>
#include <vector>

#define MINSIZE_DEFAULT_VALUE 3
#define MAXSIZE_DEFAULT_VALUE 3
#define CORRELATIONWINDOW_DEFAULT_VALUE 3


// OBSOLETE: (?)
// struct ngg_vertex_property
// {
//     // e.g. Atom
//     // TODO : implement
// };
//
// struct ngg_edge_property
// {
//     // e.g. weight (if only weight, maybe replace with boost's EdgeWeightProperty? )
//     // TODO : implement
// };
// DONE: Use Atom instead of vertex property.
// DONE: Use int instead of edge property.



/**
 * \Class A class that represents a N-gram graph.
 *
 * A N-gram graph is an entity that holds a Divider entity and some graphs (depending on the arguments passed during construction).
 * The Divider splits the data it holds into Atoms, and with those Atoms the N-gram graph creates the graphs that will represent itself.
 * The graphs' vertices are the Atoms, and the edges are the number of the n-grams' co-occurrences (within a given window).
 * AtomType is the type of data that will be used (e.g. std::string for documents).
 */
template <typename AtomType>
class NGramGraph
{
    public:
        /** Constructor
         * Creates a new instance of NGramGraph
         * MinSize, MaxSize and CorrelationWindow variables are all initialized to <var_name>_DEFAULT_VALUE defines (currently 3)
         */
        NGramGraph();



        /**
         * Creates a new instance of NGramGraph
         * MinSize, MaxSize and CorrelationWindow variables are initialized to the values provided ( i<var_name>
         * \param iMinSize The minimum n-gram size
         * \param iMaxSize The maximum n-gram size
         * \param iCorrelationWindow The maximum distance of terms to be considered as correlated.
         */
        NGramGraph(unsigned int iMinSize, unsigned int iMaxSize, unsigned int iCorrelationWindow);



        /**
         * Destructor
         */
        virtual ~NGramGraph();



        /**
         * \var divider The data that the graph holds and splits to Atoms (n-grams) to create the graph(s).
         *
         */
        StringToCharDivider divider;



    protected:
        // Define Graph type
        typedef boost::directed_graph<Atom<AtomType>, int> Graph;
        /**
         * \var NGramGraphArray A vector containing the graphs of the various n-gram sizes.
         *
         */
        vector<Graph> NGramGraphArray;



        /**
         * \var MinSize The size of the smallest n-grams. Default is 3.
         *
         */
        unsigned int MinSize = MINSIZE_DEFAULT_VALUE;



        /**
         * \var MaxSize The size of the biggest n-grams. Default is 3.
         *
         */
        unsigned int MaxSize = MAXSIZE_DEFAULT_VALUE;



        /**
         * \var CorrelationWindow The maximum distance of terms to be considered as correlated. Default is 3.
         *
         */
        unsigned int CorrelationWindow = CORRELATIONWINDOW_DEFAULT_VALUE;



        /**
         * Initializes the graphs used internally by the NGramGraph, creating a number of graphs according to the values parameter variables (MinSize, MaxSize).
         */
        void initGraphs();
};


#include "NGramGraph.tcc"

#endif // NGRAMGRAPH_H
