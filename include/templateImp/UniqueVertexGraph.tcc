/**
 * \file UniqueVertexGraph.tcc
 *
 * \author Panagiotis Fotopoulos
 *
 * \copyright Copyright 2018 NCSR Demokritos Greece \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. \n
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



template <typename AtomType>
typename Graph(AtomType)::vertex_descriptor UniqueVertexGraph<AtomType>::addVertex(Atom<AtomType> aAtom)
{
    if (UniqueVertices.find(aAtom) == UniqueVertices.end())
    {
        UniqueVertices[aAtom] = boost::add_vertex(aAtom, graph);
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
//    std::cout << "numOfEdges: " << boost::num_edges(graph) << std::endl;      //DEBUG
//    std::cout << "numberOfOutEdges: " << boost::out_degree(vVertex, graph) << std::endl;      //DEBUG

    // remove all edges connected to this vertex
    boost::clear_vertex(vVertex, graph);

    // remove the vertex entry in the atom hash
    UniqueVertices.erase(aAtom);

    // remove vertex from graph
    boost::remove_vertex(vVertex, graph);

//    std::cout << "numOfEdges: " << boost::num_edges(graph) << std::endl;        //DEBUG
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
        edgeWeightMap[edge.first] += edgeWeight;
//        std::cout << "Exists: " << boost::edge(vHead, vTail, graph).second << " with weight " << boost::get( boost::edge_weight, graph, boost::edge(vHead, vTail, graph).first ) << std::endl;  // DEBUG
    }
}




template <typename AtomType>
int UniqueVertexGraph<AtomType>::numberOfVertices()
{
    return boost::num_vertices(graph);
}




template <typename AtomType>
int UniqueVertexGraph<AtomType>::numberOfEdges()
{
    return boost::num_edges(graph);
}



template <typename AtomType>
std::pair<typename boost::graph_traits<Graph(AtomType)>::edge_iterator, typename boost::graph_traits<Graph(AtomType)>::edge_iterator> UniqueVertexGraph<AtomType>::getEdges()
{
    return boost::edges(graph);
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::printGraphviz(std::ostream& outputStream) // outputStream default value is std::cout
{
    boost::dynamic_properties dp;

    // Grab the property-map for the whole bundle
    auto vbundle = get(boost::vertex_bundle, graph);

    // Using the atom's string representation for the graphviz node ids
    dp.property("node_id", boost::make_transform_value_property_map(std::mem_fn(&Atom<AtomType>::toString), vbundle));

    // Transform it
    dp.property("label", boost::make_transform_value_property_map(std::mem_fn(&Atom<AtomType>::toString), vbundle));

    // Add edge weight
    dp.property("label", get(boost::edge_weight, graph));

    // Print graph
    boost::write_graphviz_dp(outputStream, graph, dp);
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::printGraphvizToFile(std::string fileName, std::ofstream::openmode openMode)
{
    std::ofstream ofs (fileName, openMode);
    if (ofs.good())
        printGraphviz(ofs);
    else
        // TODO : throw exception
        std::cerr << "Error: File stream to output DOT is not in a good state. Graph was not printed." << std::endl;
}
