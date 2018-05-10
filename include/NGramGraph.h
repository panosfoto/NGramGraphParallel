/**
 * \file NGramGraph.h
 */

#ifndef NGRAMGRAPH_H
#define NGRAMGRAPH_H

#include "DivisibleObject.h"
#include <boost/graph/directed_graph.hpp>
#include <vector>

// implementation discussion: templates vs subclasses
// Maybe templates require the user or another class to pre-process the data to build a suitable class/type for the template, whereas in a subclass approach it would feel more "native".
// Does the latter, though, go against the "Single-responsibility Principle" from S.O.L.I.D. Principles?
// Also, is this the correct description for a n-gram graph?

struct ngg_vertex_property
{
    // e.g. Atom
    // TODO : implement
};

struct ngg_edge_property
{
    // e.g. weight (if only weight, maybe replace with boost's EdgeWeightProperty? )
    // TODO : implement
};



typedef boost::directed_graph<ngg_vertex_property, ngg_edge_property> Graph;



/**
 * \Class A class that represents a N-gram graph.
 *
 * A N-gram graph is an entity that holds a DivisibleObject entity and some graphs (depending on the arguments passed during construction).
 * It splits the DivisibleObject int Atoms, and with those Atoms creates the graphs that will represent the N-gram graph entity.
 * The graphs' vertices are the Atoms, and the edges are the number of the n-grams' co-occurrences (within a given window).
 * PayloadType is the type of data that will be used (e.g. std::string for documents).
 */
template <typename PayloadType>
class NGramGraph
{
    public:
        /** Default constructor */
        NGramGraph();



        /** Default destructor */
        virtual ~NGramGraph();



    protected:
        /**
         * \var payload The data that the graph holds and splits to Atoms (n-grams) to create the graph(s).
         *
         */
        DivisibleObject<PayloadType> payload;



        /**
         * \var NGramGraphArray A vector containing the graphs of the various n-gram sizes.
         *
         */
        vector<Graph> NGramGraphArray;



        /**
         * \var MinSize The size of the smallest n-grams. Default is 3.
         *
         */
        int MinSize = 3;



        /**
         * \var MaxSize The size of the biggest n-grams. Default is 3.
         *
         */
        int MaxSize = 3;



        /**
         * \var CorrelationWindow The correlation windows used when creating the graph. Default is 3.
         *
         */
        int CorrelationWindow = 3;
};


#include "NGramGraph.h"

#endif // NGRAMGRAPH_H
