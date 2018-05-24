/**
 * \file NGramGraph.cpp
 */

#include "NGramGraph.hpp"



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
    //
}
