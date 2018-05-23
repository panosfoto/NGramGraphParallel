/**
 * \file UniqueVertexGraph.tcc
 */

#include "UniqueVertexGraph.hpp"



template <typename AtomType>
UniqueVertexGraph<AtomType>::UniqueVertexGraph()
{
    //ctor
}



template <typename AtomType>
UniqueVertexGraph<AtomType>::~UniqueVertexGraph()
{
    //dtor
}



template <typename AtomType>
void UniqueVertexGraph<AtomType>::addVertex(AtomType aAtom)
{
    if (UniqueVertices.find(aAtom) == UniqueVertices.end())
        UniqueVertices[aAtom] = graph.add_vertex();
//    else  // vertex already exists, so throw exception
//        // throw Exception
}
