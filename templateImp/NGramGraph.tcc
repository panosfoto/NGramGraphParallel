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
    //if(MinSize>MaxSize) throw Exception
    for(unsigned int i = MinSize ; i <=MaxSize ; ++i)
    {
        NGramGraphArray.push_back(new boost::directed_graph<Atom<AtomType>, int>);
    }
}



template <typename AtomType>
NGramGraph<AtomType>::~NGramGraph()
{
    //dtor
}
