/**
 * \file NGramGraph.cpp
 */

#include "NGramGraph.h"

#include <boost/graph/directed_graph.hpp>



template <typename PayloadType>
NGramGraph<PayloadType>::NGramGraph()
{
    //InitGraphs();
}



template <typename PayloadType>
NGramGraph<PayloadType>::NGramGraph(unsigned int iMinSize, unsigned int iMaxSize, unsigned int iCorrelationWindow)
{
    this->MinSize = iMinSize;
    this->MaxSize = iMaxSize;
    this->CorrelationWindow = iCorrelationWindow;
    //InitGraphs();
}



template <typename PayloadType>
NGramGraph<PayloadType>::~NGramGraph()
{
    //dtor
}
