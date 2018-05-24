/**
 * \file UniqueVertexGraph.hpp
 */

#ifndef UNIQUEVERTEXGRAPH_HPP
#define UNIQUEVERTEXGRAPH_HPP

// system headers
#include <boost/graph/directed_graph.hpp>
#include <unordered_map>

// project headers
#include "Atom.hpp"


// defines
#define EDGE_WEIGHT_TYPE double


// typedefs
typedef boost::property<boost::edge_weight_t, EDGE_WEIGHT_TYPE> EdgeWeightProperty;
typedef boost::directed_graph<boost::no_property, EdgeWeightProperty> Graph;
typedef boost::property_map<Graph, boost::edge_weight_t>::type EdgeWeightMap;


template <typename AtomType>
class UniqueVertexGraph
{
    public:
        /**
         * Constructor for the UniqueVertexGraph class.
         */
        UniqueVertexGraph();



        /** Default destructor */
        virtual ~UniqueVertexGraph();



        // TODO : Add Exception documentation
        /** Adds a new vertex to the graph. If a vertex holding the same Atom already exists, it doesn't add a new one, but instead throws an Exception.
         * \param aAtom The Atom that will be added to the graph.
         * \throws TryingToAddExistingVertexException
         */
        void addVertex(Atom<AtomType> aAtom);



        // TODO : Add Exception documentation
        /** Adds a new edge to the graph, directed from aAtomHead to aAtomTail.
         * If an edge connecting the same Atoms already exists, it doesn't add a new one, but instead updates the weight of the edge.
         * \param aHead The Atom that is the head of the edge that will be added to the graph.
         * \param aTail The Atom that is the tail of the edge that will be added to the graph.
         * \param edgeWeight The weight of the edge that will be added/updated to the graph.
         */
        void addEdge(Atom<AtomType> aHead, Atom<AtomType> aTail, EDGE_WEIGHT_TYPE edgeWeight);



    protected:

        /**
         * \var graph The graph of the UniqueVertexGraph.
         * Implemented with Boost Graph Library as a directed graph with weighted edges.
         */
        Graph graph;



        /**
         * \var UniqueVertices A hashtable containing pairs <Atom, Vertex> used to uniquely identify each vertex.
         */
        std::unordered_map<Atom<AtomType>, Graph::vertex_descriptor> UniqueVertices;



        /**
         * \var edgeWeightMap A (boost::property_map) map used to retrieve the weight of the edges.
         */
        EdgeWeightMap edgeWeightMap;
};


#include "UniqueVertexGraph.tcc"


#endif // UNIQUEVERTEXGRAPH_HPP
