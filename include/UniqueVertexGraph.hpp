/**
 * \file UniqueVertexGraph.hpp
 */

#ifndef UNIQUEVERTEXGRAPH_HPP
#define UNIQUEVERTEXGRAPH_HPP

#include <boost/graph/directed_graph.hpp>
#include <unordered_map>

#include "Atom.hpp"


#define EDGE_WEIGHT_TYPE double


template <typename AtomType>
class UniqueVertexGraph
{
    public:
        /** Default constructor */
        UniqueVertexGraph();
        /** Default destructor */
        virtual ~UniqueVertexGraph();



        // TODO : Add Exception documentation
        /** Adds a new vertex to the graph. If a vertex holding the same Atom already exists, it doesn't add a new one, but instead throws an Exception.
         * \param aAtom The Atom that will be added to the graph.
         * \throws TryingToAddExistingVertexException
         */
        void addVertex(AtomType aAtom);



        // TODO : Add Exception documentation
        /** Adds a new edge to the graph, directed from aAtomHead to aAtomTail.
         * If an edge connecting the same Atoms already exists, it doesn't add a new one, but instead updates the weight of the edge.
         * \param aHead The Atom that is the head of the edge that will be added to the graph.
         * \param aTail The Atom that is the tail of the edge that will be added to the graph.
         * \param edgeWeight The weight of the edge that will be added/updated to the graph.
         */
        void addEdge(AtomType aHead, AtomType aTail, EDGE_WEIGHT_TYPE edgeWeight);



    protected:
        typedef boost::property<boost::edge_weight_t, EDGE_WEIGHT_TYPE> EdgeWeightProperty;
        typedef boost::directed_graph<boost::no_property, EdgeWeightProperty> Graph;

        /**
         * \var graph The graph of the UniqueVertexGraph.
         * Implemented with Boost Graph Library as a directed graph with weighted edges.
         */
        Graph graph;



        /**
         * \var UniqueVertices A hashtable containing pairs <Atom, Vertex> used to uniquely identify each vertex
         */
        std::unordered_map<Atom<AtomType>, Graph::vertex_descriptor> UniqueVertices;
};


#include "UniqueVertexGraph.tcc"


#endif // UNIQUEVERTEXGRAPH_HPP
