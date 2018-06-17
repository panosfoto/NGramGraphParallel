/**
 * \file GraphComparator.tcc
 */



template <typename PayloadType, typename AtomType>
GraphComparator<PayloadType, AtomType>::GraphComparator()
{
//    similarity = new GraphSimilarity();
}

template <typename PayloadType, typename AtomType>
GraphComparator<PayloadType, AtomType>::~GraphComparator()
{
//    delete similarity;
}



template <typename PayloadType, typename AtomType>
GraphSimilarity GraphComparator<PayloadType, AtomType>::compare(ProximityGraph<PayloadType, AtomType> &pGraph1, ProximityGraph<PayloadType, AtomType> &pGraph2)
{
    double valueSimilarity, containmentSimilarity, sizeSimilarity, normalizedValueSimilarity;
    // calculate size similarity
    if (std::max(pGraph1.numberOfEdges(), pGraph2.numberOfEdges()) > 0)
    {
        sizeSimilarity = std::min(pGraph1.numberOfEdges(), pGraph2.numberOfEdges()) / std::max(pGraph1.numberOfEdges(), pGraph2.numberOfEdges());
    }
    else
    {
        sizeSimilarity = 0.0;
    }

    // calculate containment similarity
    if (std::max(pGraph1.numberOfEdges(), pGraph2.numberOfEdges()) > 0)
    {
        //
    }
    else
    {
        containmentSimilarity = 0.0;
    }

    // calculate value similarity
    if (std::max(pGraph1.numberOfEdges(), pGraph2.numberOfEdges()) > 0)
    {
        //
    }
    else
    {
        valueSimilarity = 0.0;
    }

    // calculate normalized value similarity
    if (sizeSimilarity != 0.0)
    {
        normalizedValueSimilarity = valueSimilarity / sizeSimilarity;
    }
    else
    {
        normalizedValueSimilarity = 0.0;
    }
    GraphSimilarity gSimilarity(valueSimilarity, containmentSimilarity, sizeSimilarity, normalizedValueSimilarity);
    return gSimilarity;
}
