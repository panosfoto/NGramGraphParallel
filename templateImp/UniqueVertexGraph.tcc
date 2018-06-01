/**
 * \file UniqueVertexGraph.tcc
 */

#include "UniqueVertexGraph.hpp"
#include <iostream>


template <typename AtomType>
UniqueVertexGraph<AtomType>::UniqueVertexGraph()
{
    //ctor
    edgeWeightMap = get(boost::edge_weight, graph);
}



template <typename AtomType>
UniqueVertexGraph<AtomType>::~UniqueVertexGraph()
{
    //dtor
}



    // DEPRECATED
//template <typename AtomType>
//void UniqueVertexGraph<AtomType>::addVertex(Atom<AtomType> aAtom)
//{
//    if (UniqueVertices.find(aAtom) == UniqueVertices.end())
//        UniqueVertices[aAtom] = graph.add_vertex();
////    else  // vertex already exists, so throw exception
////        // throw Exception
//}



template <typename AtomType>
typename Graph::vertex_descriptor UniqueVertexGraph<AtomType>::addVertex(Atom<AtomType> aAtom)
{
    if (UniqueVertices.find(aAtom) == UniqueVertices.end())
        UniqueVertices[aAtom] = graph.add_vertex();
    return UniqueVertices[aAtom];
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::removeVertex(Atom<AtomType> aAtom)
{
    // first check if the Atom exists in the graph. If it doesn't there's nothing to remove, so return
    if (UniqueVertices.find(aAtom) == UniqueVertices.end())
        return;
    // Reminder: UniqueVertices.find(aAtom) returns an iterator to unordered_map, meaning that it has two fields:
    // -> "first", the key of the map (Atom<AtomType> in this case).
    // -> "second", the value of the map (vertex_descriptor in this case).
    graph.remove_vertex(UniqueVertices.find(aAtom)->second);
    UniqueVertices.erase(aAtom);
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::removeVertex(typename Graph::vertex_descriptor vVertex)
{
    graph.remove_vertex(vVertex);
}



template <typename AtomType>
bool UniqueVertexGraph<AtomType>::contains(Atom<AtomType> aAtom)
{
    typename std::unordered_map<Atom<AtomType>, Graph::vertex_descriptor>::const_iterator umIt;
    umIt = UniqueVertices.find(aAtom);
    if (umIt == UniqueVertices.end())
        return false;
    return true;
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::addEdge(typename Graph::vertex_descriptor vHead, typename Graph::vertex_descriptor vTail, EDGE_WEIGHT_TYPE edgeWeight)
{
    std::pair<Graph::edge_descriptor, bool> edge = boost::edge(vHead, vTail, graph);
    //check if edge exists
    if (edge.second == false) // edge doesn't exist, so add it
    {
        EdgeWeightProperty ewp = edgeWeight;
        boost::add_edge(vHead, vTail, ewp, graph);
    }
    else    // edge.second == true, edge exists, so update its weight
    {
        edgeWeightMap[edge.first] += edgeWeight;
    }
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::addEdge(Atom<AtomType> aHead, Atom<AtomType> aTail, EDGE_WEIGHT_TYPE edgeWeight)
{
    typename Graph::vertex_descriptor vHead, vTail;

    // Locate the vertices
    // Since addVertex() will check if the vertex already exists, a simple call will return the descriptor to the (either new or found) vertex we want.
    vHead = addVertex(aHead);
    vTail = addVertex(aTail);

    // vertices located, search if edge already exists
    std::pair<Graph::edge_descriptor, bool> edge = boost::edge(vHead, vTail, graph);
    //check if edge exists
//    std::cout << "Exists: " << edge.second << std::endl;    // DEBUG
    if (edge.second == false) // edge doesn't exist, so add it
    {
        EdgeWeightProperty ewp = edgeWeight;
        boost::add_edge(vHead, vTail, ewp, graph);
//        std::cout << "Exists: " << boost::edge(vHead, vTail, graph).second << " with weight " << boost::get( boost::edge_weight, graph, boost::edge(vHead, vTail, graph).first ) << std::endl;  // DEBUG
    }
    else    // edge.second == true, edge exists, so update its weight
    {
        //EdgeWeightMap edgeWeightMap = get(boost::edge_weight, graph);
        edgeWeightMap[edge.first] += edgeWeight;
//        std::cout << "Exists: " << boost::edge(vHead, vTail, graph).second << " with weight " << boost::get( boost::edge_weight, graph, boost::edge(vHead, vTail, graph).first ) << std::endl;  // DEBUG
    }
}
