/**
 * \file NGramGraph.cpp
 */

#include "NGramGraph.hpp"

#include <boost/graph/directed_graph.hpp>



template <typename AtomType>
NGramGraph<AtomType>::NGramGraph()
{
    //InitGraphs();
}



template <typename AtomType>
NGramGraph<AtomType>::NGramGraph(unsigned int iMinSize, unsigned int iMaxSize, unsigned int iCorrelationWindow)
{
    this->MinSize = iMinSize;
    this->MaxSize = iMaxSize;
    this->CorrelationWindow = iCorrelationWindow;
    //InitGraphs();
}



template <typename AtomType>
void NGramGraph<AtomType>::initGraphs()
{
    graphArray.clear();
    //if(MinSize>MaxSize) throw Exception
    for(unsigned int i = MinSize ; i <=MaxSize ; ++i)
    {
        graphArray.push_back(new boost::directed_graph<Atom<AtomType>, int>);
    }
}



template <typename AtomType>
void NGramGraph<AtomType>::createGraphs()
{
    vector<Atom<AtomType>> atoms;
    typename boost::directed_graph<Atom<AtomType>, int>::vertex_descriptor temp_vertex;
    for(unsigned int uiNGramSize = MinSize ; uiNGramSize <= MaxSize ; ++uiNGramSize)
    {
        // If the n-gram is bigger than the text
        if(uiNGramSize > divider.getPayloadSize())
            // then continue, since we can't do any calculations
            continue;
        // split payload to get the n-grams (atoms)
        divider.setAtomSize(uiNGramSize);
        divider.splitPayloadToAtoms();
        atoms = divider.getAtoms();

        for(typename vector<Atom<AtomType>>::iterator itCurrentAtom = atoms.begin() ; itCurrentAtom != atoms.end() ; ++itCurrentAtom)
        {
            if (itCurrentAtom == atoms.begin())
            {
                // add vertex to graph
                temp_vertex = graphArray[uiNGramSize - MinSize].add_vertex(*itCurrentAtom);
            }
            else
            {
                // add edges from itCurrentAtom to up to CorrelationWindow-1 previous vertices
            }
        }
    }
}



template <typename AtomType>
NGramGraph<AtomType>::~NGramGraph()
{
    //dtor
}
