/**
 * \file NormalizedGraphSimilarity.hpp
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

#ifndef NORMALIZEDGRAPHSIMILARITY_H
#define NORMALIZEDGRAPHSIMILARITY_H

// project headers
#include "GraphSimilarity.hpp"


/**
 * \Class A class that represents a normalized similarity of graphs. \n
 * Consists of the same 3 basic similarities in GraphSimilarity, but returns the normalized value similarity as the overall similarity: \n
 * The overall similarity is defined as valueSimilarity / SizeSimilarity (or 0, if SizeSimilarity is 0).
 */
class NormalizedGraphSimilarity : public GraphSimilarity
{
    public:
        /**
         *      Default constructor. Sets all similarity values to 0
         */
        NormalizedGraphSimilarity();



        /** \brief
         *      A constructor that initializes the similarity values with the according provided parameters
         * \param valueSimilarity (double) The valueSimilarity component value.
         * \param containmentSimilarity (double) The containmentSimilarity component value.
         * \param sizeSimilarity (double) The sizeSimilarity component value.
         *
         */
        NormalizedGraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity);



        /** Default destructor */
        virtual ~NormalizedGraphSimilarity();



        /** \brief
         *      A function that returns a map of the similarity constituents, as pairs of the form <SimilarityName, SimilarityValue>.
         * \return map<string, double>
         *      A map with the values of the similarities
         */
        virtual std::map<std::string, double> getSimilarityComponents();



        /** \brief
         *      Returns the overall similarity defined as:
         *      valueSimilarity / sizeSimilarity
         *
         * \return double
         *      Returns the overall similarity
         */
        virtual double getOverallSimilarity();
};

#endif // NORMALIZEDGRAPHSIMILARITY_H
