/**
 * \file NGramGraph.cpp
 */

#include "NGramGraph.hpp"
#include <boost/graph/graph_utility.hpp>



NGramGraph::NGramGraph()
{
    divider.setAtomSize(NGRAMSIZE_DEFAULT_VALUE);
}



NGramGraph::NGramGraph(unsigned int CorrelationWindowValue, unsigned int NGramSizeValue) : ProximityGraph(CorrelationWindowValue)
{
    divider.setAtomSize(NGramSizeValue);
}



NGramGraph::~NGramGraph()
{
    //dtor
}



unsigned int NGramGraph::getPayloadSize()
{
    return divider.getPayloadSize();
}



void NGramGraph::createGraph()
{
    vector<Atom<std::string>> atoms;
    typename Graph::vertex_descriptor currentVertex;
    vector<typename Graph::vertex_descriptor> preceding_atoms;
    typename std::unordered_map<Atom<std::string>, Graph::vertex_descriptor>::const_iterator uniqueVerticesIterator;

    // split payload to get the n-grams (atoms)
    divider.splitPayloadToAtoms();
    atoms = divider.getAtoms();
    // add the atoms to the graph
    for(typename vector<Atom<std::string>>::iterator itCurrentAtom = atoms.begin() ; itCurrentAtom != atoms.end() ; ++itCurrentAtom)
    {
        // try to locate current vertex (atom) in the graph
        uniqueVerticesIterator = UniqueVertices.find(*itCurrentAtom);
        if (uniqueVerticesIterator == UniqueVertices.end())
            // if it doesn't exist, add it
            currentVertex = graph.add_vertex();
        else
            //if it exists, locate it
            currentVertex = uniqueVerticesIterator->second;

        // add edges from current vertex (atom) to its neighbors
        createEdgesToNeighbors(currentVertex, preceding_atoms);

        // update preceding atoms vector:
        // add current vertex to the neighbors (preceding atoms vector)
        preceding_atoms.push_back(currentVertex);
        // if the number of current neighbors exceeds the correlation window, then remove the first (the oldest) one
        if (preceding_atoms.size() > CorrelationWindow)
            preceding_atoms.erase(preceding_atoms.begin());
    }
    // DEBUG
    std::cout << "Num of vertices: " << boost::num_vertices(graph) << std::endl << "Num of edges: " << boost::num_edges(graph) << std::endl;
    boost::print_graph(graph);
}



void NGramGraph::createEdgesToNeighbors(Graph::vertex_descriptor vHead, vector<typename Graph::vertex_descriptor> neighbors)
{
    for(typename vector<typename Graph::vertex_descriptor>::iterator itCurrentVertex = neighbors.begin() ; itCurrentVertex != neighbors.end() ; ++itCurrentVertex)
    {
        addEdge(vHead, *itCurrentVertex, EDGE_WEIGHT_DEFAULT_VALUE);
    }
}
