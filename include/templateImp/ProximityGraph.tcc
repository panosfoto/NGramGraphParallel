/**
 * \file ProximityGraph.tcc
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


template <typename PayloadType, typename AtomType>
ProximityGraph<PayloadType, AtomType>::ProximityGraph()
{
    evaluator = nullptr;
    splitter = nullptr;
    payload = nullptr;
}



template <typename PayloadType, typename AtomType>
ProximityGraph<PayloadType, AtomType>::ProximityGraph(ProximityEvaluator<AtomType> *newEvaluator, Splitter<PayloadType, AtomType> *newSplitter, Payload<PayloadType> *newPayload)
{
    evaluator = newEvaluator;
    splitter = newSplitter;
    payload = newPayload;
}



template <typename PayloadType, typename AtomType>
ProximityGraph<PayloadType, AtomType>::~ProximityGraph()
{
    //dtor
}



template <typename PayloadType, typename AtomType>
void ProximityGraph<PayloadType, AtomType>::createGraph()
{
    vector<Atom<std::string>> atoms;
    typename Graph(std::string)::vertex_descriptor currentVertex;

    if (splitter == nullptr)
    {
        // TODO : throw exception for missing splitter
        std::cerr << "ProximityGraph::createGraph() : Error: missing splitter. Exiting..." << std::endl; return;
    }
    // split payload to get the n-grams (atoms)
    atoms = splitter->splitPayloadToAtoms(payload);

    // add the atoms to the graph
    for (typename vector<Atom<std::string>>::iterator itCurrentAtom = atoms.begin() ; itCurrentAtom != atoms.end() ; ++itCurrentAtom)
    {
        // add or locate current vertex (atom) in the graph
        currentVertex = this->addVertex(*itCurrentAtom);

        // add an edge from current vertex (atom) to every other vertex (atom) it should connect to, based on the proximity evaluator
        for (typename vector<Atom<std::string>>::iterator itPrecedingAtom = atoms.begin() ; itPrecedingAtom != itCurrentAtom ; ++itPrecedingAtom)
        {
            if (evaluator->areClose(*itCurrentAtom, *itPrecedingAtom))
                this->addEdge(currentVertex, this->UniqueVertices[*itPrecedingAtom], EDGE_WEIGHT_DEFAULT_VALUE);
        }
    }
}
