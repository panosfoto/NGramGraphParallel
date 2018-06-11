/**
 * \file ProximityGraph.tcc
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
