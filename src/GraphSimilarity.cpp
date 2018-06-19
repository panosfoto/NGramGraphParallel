/**
 * \file GraphSimilarity.cpp
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

#include "GraphSimilarity.hpp"



GraphSimilarity::GraphSimilarity()
{
    this->valueSimilarity = 0.0;
    this->containmentSimilarity = 0.0;
    this->sizeSimilarity = 0.0;
}



GraphSimilarity::GraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity)
{
    this->valueSimilarity = valueSimilarity;
    this->containmentSimilarity = containmentSimilarity;
    this->sizeSimilarity = sizeSimilarity;
}



std::map<std::string, double> GraphSimilarity::getSimilarityComponents()
{
    // Init result map
    std::map<std::string, double> resultMap;
    // Update components
    resultMap["valueSimilarity"] = this->valueSimilarity;
    resultMap["containmentSimilarity"] = this->containmentSimilarity;
    resultMap["sizeSimilarity"] = this->sizeSimilarity;
    // Return
    return resultMap;
}



double GraphSimilarity::getOverallSimilarity()
{
    return this->valueSimilarity*this->containmentSimilarity*this->sizeSimilarity;
}
