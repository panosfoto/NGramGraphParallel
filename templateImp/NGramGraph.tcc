/**
 * \file NGramGraph.cpp
 */

#include "NGramGraph.hpp"

#include <boost/graph/directed_graph.hpp>
#include <vector>



template <typename AtomType>
NGramGraph<AtomType>::NGramGraph()
{
    initGraphs();
}



template <typename AtomType>
NGramGraph<AtomType>::NGramGraph(unsigned int uiMinSize, unsigned int uiMaxSize, unsigned int uiCorrelationWindow)
{
    // TODO :  if(iMinSize > iMaxSize) throw Exception
    this->MinSize = uiMinSize;
    this->MaxSize = uiMaxSize;
    this->CorrelationWindow = uiCorrelationWindow;
    initGraphs();
}



template <typename AtomType>
NGramGraph<AtomType>::~NGramGraph()
{
    //dtor
}



template <typename AtomType>
void NGramGraph<AtomType>::initGraphs()
{
    graphArray.clear();
    atomGraph temp;
    // TODO : if(MinSize>MaxSize) throw Exception
    for(unsigned int i = MinSize ; i <=MaxSize ; ++i)
    {
        graphArray.push_back(atomGraph());
    }
    // DEBUG
//    typename atomGraph::vertex_descriptor v;
//    cout << "v " << v << endl;
//    Atom<std::string>a ("asd"), b;
//    findVertex(graphArray[0], a, v);
//    cout << "v " << v << endl;
//    typedef typename boost::property_map<atomGraph, vertex_atom_t>::const_type atomPM;
//    atomPM tempAtomPM = get(vertex_atom, graphArray[0]);
//    b = boost::get(tempAtomPM, vertex_atom);
}



template <typename AtomType>
void NGramGraph<AtomType>::createGraphs()
{
    vector<Atom<AtomType>> atoms;
    typename atomGraph::vertex_descriptor temp_vertex;
    vector<typename atomGraph::vertex_descriptor> preceding_atoms;

    // TODO : Throw Exception if MinSize > MaxSize
    // for each n-gram size
    for(unsigned int uiNGramSize = MinSize ; uiNGramSize <= MaxSize ; ++uiNGramSize)
    {
        // clear vectors from previous iterations
        atoms.clear();
        preceding_atoms.clear();

        // If the n-gram is bigger than the text
        if(uiNGramSize > divider.getPayloadSize())
            // then continue, since we can't do any calculations
            continue;

        // split payload to get the n-grams (atoms)
        divider.setAtomSize(uiNGramSize);
        divider.splitPayloadToAtoms();
        atoms = divider.getAtoms();

        // add the atoms to the graph
        for(typename vector<Atom<AtomType>>::iterator itCurrentAtom = atoms.begin() ; itCurrentAtom != atoms.end() ; ++itCurrentAtom)
        {
            // add current atom to the graph, or locate it if it already exists
            // TODO : what to do in case an atom already in preceding vector re-appears?
            temp_vertex = addOrFindVertex(graphArray[uiNGramSize - MinSize], *itCurrentAtom);

            // add edges to the graph
            addEdges(graphArray[uiNGramSize - MinSize], *itCurrentAtom, preceding_atoms);

            // update preceding atoms vector:
            // add current vertex to the neighbors (preceding atoms vector)
            preceding_atoms.push_back(temp_vertex);
            // if the number of current neighbors exceeds the correlation window, then remove the first (the oldest) one
            if (preceding_atoms.size() > CorrelationWindow)
                preceding_atoms.erase(preceding_atoms.begin());
        }
    }
}



template <typename AtomType>
bool NGramGraph<AtomType>::findVertex(atomGraph gGraph, Atom<AtomType> aAtomParam, typename atomGraph::vertex_descriptor & vReturnVertex)
{
    typename atomGraph::vertex_descriptor temp = gGraph.add_vertex(aAtomParam);
    typename boost::property_map<atomGraph, vertex_atom_t>::type atom = get(vertex_atom, gGraph);
    boost::put(atom, temp, aAtomParam);
    vReturnVertex = temp;
    return true;
}



template <typename AtomType>
typename NGramGraph<AtomType>::atomGraph::vertex_descriptor NGramGraph<AtomType>::addOrFindVertex(atomGraph gGraph, Atom<AtomType> aAtomParam)
{

}



template <typename AtomType>
void NGramGraph<AtomType>::addEdges(atomGraph gGraph, typename atomGraph::vertex_descriptor vStartVertex, vector<typename atomGraph::vertex_descriptor> vec_vNeighbors)
{

}
