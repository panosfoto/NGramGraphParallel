/**
 * \file GraphComparator.tcc
 *
 * \author Panagiotis Fotopoulos
 *
 * \copyright Copyright 2018 NCSR Demokritos Greece \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. \n
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
    double valueSimilarity, containmentSimilarity, sizeSimilarity;
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

    GraphSimilarity gSimilarity(valueSimilarity, containmentSimilarity, sizeSimilarity);
    return gSimilarity;
}
