/**
 * \file NGramGraph.cpp
 */

#include "NGramGraph.hpp"
#include <boost/graph/graph_utility.hpp>



NGramGraph::NGramGraph()
{
    CorrelationWindow = CORRELATIONWINDOW_DEFAULT_VALUE;
    splitter = nullptr;
    evaluator = nullptr;
}



NGramGraph::NGramGraph(unsigned int CorrelationWindowValue, Splitter<std::string> *newSplitter, ProximityEvaluator<std::string> *newProximityEvaluator)
{
    CorrelationWindow = CorrelationWindowValue;
    splitter = newSplitter;
    evaluator = newProximityEvaluator;
}



NGramGraph::~NGramGraph()
{
    //dtor
}



void NGramGraph::createGraph()
{
    vector<Atom<std::string>> atoms;
    typename Graph(std::string)::vertex_descriptor currentVertex;
    vector<typename Graph(std::string)::vertex_descriptor> preceding_atoms;

    // split payload to get the n-grams (atoms)
    atoms = splitter->splitPayloadToAtoms();

    // add the atoms to the graph
    for(typename vector<Atom<std::string>>::iterator itCurrentAtom = atoms.begin() ; itCurrentAtom != atoms.end() ; ++itCurrentAtom)
    {
        // add or locate current vertex (atom) in the graph
        currentVertex = addVertex(*itCurrentAtom);

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



void NGramGraph::createEdgesToNeighbors(Graph(std::string)::vertex_descriptor vHead, vector<typename Graph(std::string)::vertex_descriptor> neighbors)
{
    for(typename vector<typename Graph(std::string)::vertex_descriptor>::iterator itCurrentVertex = neighbors.begin() ; itCurrentVertex != neighbors.end() ; ++itCurrentVertex)
    {
        addEdge(vHead, *itCurrentVertex, EDGE_WEIGHT_DEFAULT_VALUE);
    }
}
