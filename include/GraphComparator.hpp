/**
 * \file GraphComparator.hpp
 */

#ifndef GRAPHCOMPARATOR_H
#define GRAPHCOMPARATOR_H

// project headers
#include "GraphSimilarity.hpp"
#include "ProximityGraph.hpp"


/**
 * \Class
 * Usage:
 */
template <typename PayloadType, typename AtomType>
class GraphComparator
{
    public:
        /** Default constructor */
        GraphComparator();



        /** Default destructor */
        virtual ~GraphComparator();



        virtual GraphSimilarity compare(ProximityGraph<PayloadType, AtomType> &pGraph1, ProximityGraph<PayloadType, AtomType> &pGraph2);

    protected:
//        GraphSimilarity *similarity;
};


// template implementation file
#include "templateImp/GraphComparator.tcc"


#endif // GRAPHCOMPARATOR_H
