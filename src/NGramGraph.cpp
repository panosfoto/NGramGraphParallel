/**
 * \file NGramGraph.cpp
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

#include "NGramGraph.hpp"
#include <boost/graph/graph_utility.hpp>



NGramGraph::NGramGraph()
{
    CorrelationWindow = CORRELATIONWINDOW_DEFAULT_VALUE;
    splitter = nullptr;
    evaluator = nullptr;
    payload = nullptr;
}



NGramGraph::NGramGraph(ProximityEvaluator<std::string> *newProximityEvaluator, StringSplitter *newSplitter, StringPayload *newPayload, unsigned int CorrelationWindowValue)
{
    evaluator = newProximityEvaluator;
    splitter = newSplitter;
    payload = newPayload;
    CorrelationWindow = CorrelationWindowValue;
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

    if (splitter == nullptr)
    {
        // TODO : throw exception for missing splitter
        std::cerr << "NGramGraph::createGraph() : Error: missing splitter. Exiting..." << std::endl; return;
    }
    if (payload == nullptr)
    {
        // TODO : throw exception for missing payload
        std::cerr << "NGramGraph::createGraph() : Error: missing payload. Exiting..." << std::endl; return;
    }
    // split payload to get the n-grams (atoms)
    atoms = splitter->splitPayloadToAtoms(payload);

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
//    std::cout << "Num of vertices: " << boost::num_vertices(graph) << std::endl << "Num of edges: " << boost::num_edges(graph) << std::endl;
//    std::cout << "---------\nBoost print:" << std:: endl;
//    boost::print_graph(graph);
//    std::cout << "---------\nGraphviz print:" << std:: endl;
//    printGraphviz();
}



void NGramGraph::createEdgesToNeighbors(Graph(std::string)::vertex_descriptor vHead, vector<typename Graph(std::string)::vertex_descriptor> neighbors)
{
    for(typename vector<typename Graph(std::string)::vertex_descriptor>::iterator itCurrentVertex = neighbors.begin() ; itCurrentVertex != neighbors.end() ; ++itCurrentVertex)
    {
        addEdge(vHead, *itCurrentVertex, EDGE_WEIGHT_DEFAULT_VALUE);
    }
}
