/**
 * \file ProximityGraph.tcc
 */

#include "ProximityGraph.hpp"

template <typename AtomType>
ProximityGraph<AtomType>::ProximityGraph()
{
    CorrelationWindow = CORRELATIONWINDOW_DEFAULT_VALUE;
}



template <typename AtomType>
ProximityGraph<AtomType>::ProximityGraph(unsigned int CorrelationWindowValue)
{
    CorrelationWindow = CorrelationWindowValue;
}



template <typename AtomType>
ProximityGraph<AtomType>::~ProximityGraph()
{
    //dtor
}
