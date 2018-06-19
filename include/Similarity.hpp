/**
 * \file Similarity.hpp
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

#ifndef SIMILARITY_H
#define SIMILARITY_H

// system headers
#include <map>
#include <string>



/**
 * \Class An abstract class that represents a generic similarity interface. Such a similarity is considered to be composed of basic similarities (at least one),
 * which through an appropriate calculation determine the final, overall similarity.
 */
class Similarity
{
    public:
        /** \brief
         *      Used to get the collection of basic similarities, that compose the overall similarity calculation. In trivial cases where
         *      a similarity is not based on constituents, this function is expected to return the overall similarity.
         * \return
         *      A map which contains pairs like <SimilarityName, SimilarityValue>
         */
        virtual std::map<std::string, double> getSimilarityComponents() = 0;



        /** \brief
         *      Calculates and returns the overall similarity, based on the constituents.
         * \return
         *      The overall similarity
         */
        virtual double getOverallSimilarity() = 0;
};

#endif // SIMILARITY_H
