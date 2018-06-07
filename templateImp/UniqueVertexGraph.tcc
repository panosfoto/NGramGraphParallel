/**
 * \file UniqueVertexGraph.tcc
 */

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
typename Graph(AtomType)::vertex_descriptor UniqueVertexGraph<AtomType>::addVertex(Atom<AtomType> aAtom)
{
    if (UniqueVertices.find(aAtom) == UniqueVertices.end())
    {
        UniqueVertices[aAtom] = graph.add_vertex(aAtom);
    }
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
    this->removeVertex(aAtom, UniqueVertices.find(aAtom)->second);
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::removeVertex(typename Graph(AtomType)::vertex_descriptor vVertex)
{
    this->removeVertex(graph[vVertex], vVertex);
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::removeVertex(Atom<AtomType> aAtom, typename Graph(AtomType)::vertex_descriptor vVertex)
{
    // TODO : remove all vertex's edges
    UniqueVertices.erase(aAtom);
    graph.remove_vertex(vVertex);
}



template <typename AtomType>
bool UniqueVertexGraph<AtomType>::contains(Atom<AtomType> aAtom)
{
    typename std::unordered_map<Atom<AtomType>, typename Graph(AtomType)::vertex_descriptor>::const_iterator umIt;
    umIt = UniqueVertices.find(aAtom);
    if (umIt == UniqueVertices.end())
        return false;
    return true;
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::addEdge(typename Graph(AtomType)::vertex_descriptor vHead, typename Graph(AtomType)::vertex_descriptor vTail, EDGE_WEIGHT_TYPE edgeWeight)
{
    std::pair<typename Graph(AtomType)::edge_descriptor, bool> edge = boost::edge(vHead, vTail, graph);
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
    typename Graph(AtomType)::vertex_descriptor vHead, vTail;

    // Locate the vertices
    // Since addVertex() will check if the vertex already exists, a simple call will return the descriptor to the (either new or found) vertex we want.
    vHead = addVertex(aHead);
    vTail = addVertex(aTail);

    // vertices located, search if edge already exists
    std::pair<typename Graph(AtomType)::edge_descriptor, bool> edge = boost::edge(vHead, vTail, graph);
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



template <typename AtomType>
void UniqueVertexGraph<AtomType>::printGraphviz(std::ostream& outputStream) // outputStream default value is std::cout
{
    boost::dynamic_properties dp;

    // Using the intrinsic vertex index for the graphviz node ids
    dp.property("node_id", get(boost::vertex_index, graph));

    // Grab the property-map for the whole bundle
    auto vbundle = get(boost::vertex_bundle, graph);

    // Transform it
    dp.property("label", boost::make_transform_value_property_map(std::mem_fn(&Atom<std::string>::toString), vbundle));

    // Print graph
    boost::write_graphviz_dp(outputStream, graph, dp);
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::printGraphvizToFile(std::string fileName)
{
    std::ofstream ofs (fileName,  std::ofstream::out | std::ofstream::app);
    if (ofs.good())
        printGraphviz(ofs);
    else
        // TODO : throw exception
        std::cerr << "Error: File stream to output DOT is not in a good state. Graph was not printed." << std::endl;
}
