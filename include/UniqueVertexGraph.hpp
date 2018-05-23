/**
 * \file UniqueVertexGraph.hpp
 */

#ifndef UNIQUEVERTEXGRAPH_HPP
#define UNIQUEVERTEXGRAPH_HPP

#include <boost/graph/directed_graph.hpp>
#include <unordered_map>

#include "Atom.hpp"


template <typename AtomType>
class UniqueVertexGraph
{
    public:
        /** Default constructor */
        UniqueVertexGraph();
        /** Default destructor */
        virtual ~UniqueVertexGraph();



        // TODO : Add Exception documentation
        /** Adds a new vertex to the graph. If a vertex holding the same Atom already exists it doesn't add a new one, but instead throws an Exception.
         * \param aAtom The Atom that will be added to the graph.
         * \throws AddingExistingVertexException
         */
        void addVertex(AtomType aAtom);



    protected:
        typedef boost::property<boost::edge_weight_t, float> EdgeWeightProperty;
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
