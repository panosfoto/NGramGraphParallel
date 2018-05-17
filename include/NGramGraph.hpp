/**
 * \file NGramGraph.hpp
 */

#ifndef NGRAMGRAPH_H
#define NGRAMGRAPH_H

#include "StringToCharDivider.hpp"

#include <boost/graph/directed_graph.hpp>
#include <boost/property_map/property_map.hpp>

#include <vector>

#define MINSIZE_DEFAULT_VALUE 3
#define MAXSIZE_DEFAULT_VALUE 3
#define CORRELATIONWINDOW_DEFAULT_VALUE 3


// OBSOLETE: (?)
// struct ngg_edge_property
// {
//     // e.g. weight (if only weight, maybe replace with boost's EdgeWeightProperty? )
//     // TODO : implement
// };
// DONE: Use int instead of edge property.

// Create atom property for vertices (each vertex will hold an Atom).
// Below property installation is needed so that we can also refer to vertices based on their Atom, instead of just by their vertex descriptor.
enum vertex_atom_t { vertex_atom };
namespace boost {
  BOOST_INSTALL_PROPERTY(vertex, atom);
}



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
    // Define vertex property: With this property (vertex_atom), each vertex is associated with its Atom.
    // We can then refer to a vertex by its Atom, by getting its vertex descriptor by querying a property map with its Atom.
    typedef boost::property<vertex_atom_t, Atom<AtomType>> atom_property;

    // Define atomGraph type: Vertices' property is the atom_property (atoms), Edges' property is their weight (an integer).
    typedef boost::directed_graph<atom_property, int> atomGraph;

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
         * Fills the graphs used internally by the NGramGraph, for all the levels specified in the MinSize, MaxSize range.
         */
        void createGraphs();



        /**
         * Searches for a vertex that holds the given Atom in the graph.
         * On success, returns true and assigns the found vertex to the result_vertex parameter.
         * On failure, returns false and doesn't change the result_vertex parameter.
         * \param gGraph The graph to use.
         * \param atom_param The Atom we're looking for.
         * \param vReturnVertex A vertex reference, which will be filled with the vertex descriptor in case the target vertex is found.
         * \return True if the vertex was found, otherwise False.
         */
        bool findVertex(atomGraph gGraph, Atom<AtomType> aAtomParam, typename atomGraph::vertex_descriptor & vReturnVertex);



        /**
         * Searches for a vertex that holds the given Atom in the graph.
         * If it finds it, returns the found vertex.
         * If it doesn't, it adds a new vertex holding the given Atom, and then returns it.
         * \param gGraph The graph to use.
         * \param atom_param The Atom we want to add (and are searching for).
         * \return The vertex descriptor for the newly added or found vertex.
         */
        typename atomGraph::vertex_descriptor addOrFindVertex(atomGraph gGraph, Atom<AtomType> aAtomParam);



        // TODO : update documentation about weight modification in case the edge already exists
        /**
         * Creates and edge in [gGraph] connecting [vStartVertex] to each vertex in the [vec_vNeighbors] vector of vertices.
         * If the edge already exists, its weight is modified.
         * \param gGraph The graph to use.
         * \param vStartVertex A vertex descriptor for the vertex from which all edges begin.
         * \param vec_vNeighbors A vector with the vertex descriptors of all the vertices to which the vertex will be connected (or already is.)
         */
        void addEdges(atomGraph gGraph, typename atomGraph::vertex_descriptor vStartVertex, vector<typename atomGraph::vertex_descriptor> vec_vNeighbors);



        /**
         * \var divider The data that the graph holds and splits to Atoms (n-grams) to create the graph(s).
         *
         */
        StringToCharDivider divider;



    protected:
        /**
         * \var NGramGraphArray A vector containing the graphs of the various n-gram sizes.
         *
         */
        vector<atomGraph> graphArray;



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
