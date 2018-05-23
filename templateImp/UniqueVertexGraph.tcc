/**
 * \file UniqueVertexGraph.tcc
 */

#include "UniqueVertexGraph.hpp"



template <typename AtomType>
UniqueVertexGraph<AtomType>::UniqueVertexGraph()
{
    //ctor
}



template <typename AtomType>
UniqueVertexGraph<AtomType>::~UniqueVertexGraph()
{
    //dtor
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::addVertex(AtomType aAtom)
{
    if (UniqueVertices.find(aAtom) == UniqueVertices.end())
        UniqueVertices[aAtom] = graph.add_vertex();
//    else  // vertex already exists, so throw exception
//        // throw Exception
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::addEdge(AtomType aHead, AtomType aTail, EDGE_WEIGHT_TYPE edgeWeight)
{
    typename Graph::vertex_descriptor vHead, vTail;
    typename std::unordered_map<Atom<AtomType>, Graph::vertex_descriptor>::const_iterator umIt;

    // locate the vertices
    umIt = UniqueVertices.find(aHead);
    if (umIt == UniqueVertices.end())
    {
        // add new vertex or throw Exception
    }
    vHead = umIt->second;
    umIt = UniqueVertices.find(aTail);
    if (umIt == UniqueVertices.end())
    {
        // add new vertex or throw Exception
    }
    vTail = umIt->second;

    // vertices located, search if edge already exists
    std::pair<Graph::edge_descriptor, bool> edge = boost::edge(vHead, vTail, graph);
    //check if edge exists; add if it doesn't, update if it does
    //
}
