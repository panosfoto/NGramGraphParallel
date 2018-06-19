/**
 * \file GraphSimilarity.hpp
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

#ifndef GRAPHSIMILARITY_H
#define GRAPHSIMILARITY_H

// project headers
#include "Similarity.hpp"



/**
 * \Class A class that represents the similarity of graphs. Consists of 3 basic similarities: \n
 * valueSimilarity, regarding the existence and weight of edges of the graphs, \n
 * containmentSimilarity, regarding the existence of edges of the graphs, \n
 * sizeSimilarity, regarding the number of edges of the graphs. \n
 * The overall similarity is defined as the product of the 3 basic similarities.
 */
class GraphSimilarity : public Similarity
{
    public:
        /**
         *      Default constructor. Sets all similarity values to 0
         */
        GraphSimilarity();



        /** \brief
         *      A constructor that initializes the similarity values with the according provided parameters
         * \param valueSimilarity (double) The valueSimilarity component value.
         * \param containmentSimilarity (double) The containmentSimilarity component value.
         * \param sizeSimilarity (double) The sizeSimilarity component value.
         *
         */
        GraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity);



        /** \brief
         *      A function that returns a map of the similarity constituents, as pairs of the form <SimilarityName, SimilarityValue>.
         * \return map<string, double>
         *      A map with the values of the similarities
         */
        virtual std::map<std::string, double> getSimilarityComponents();



        /** \brief
         *      Returns the overall similarity defined as:
         *      valueSimilarity * containmentSimilarity * sizeSimilarity
         *
         * \return double
         *      Returns the overall similarity
         */
        virtual double getOverallSimilarity();



    protected:
        /** \var valueSimilarity
         * Similarity regarding the existence and weight of edges of the graphs
         */
        double valueSimilarity;



        /** \var containmentSimilarity
         * Similarity regarding the existence of edges of the graphs
         */
        double containmentSimilarity;



        /** \var sizeSimilarity
         * Similarity regarding the number of edges of the graphs
         */
        double sizeSimilarity;
};

#endif // GRAPHSIMILARITY_H
