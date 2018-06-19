/**
 * \file NormalizedGraphSimilarity.cpp
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

#include "NormalizedGraphSimilarity.hpp"

NormalizedGraphSimilarity::NormalizedGraphSimilarity() : GraphSimilarity()
{
    //ctor
}



NormalizedGraphSimilarity::NormalizedGraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity) : GraphSimilarity(valueSimilarity, containmentSimilarity, sizeSimilarity)
{}



NormalizedGraphSimilarity::~NormalizedGraphSimilarity()
{
    //dtor
}



std::map<std::string, double> NormalizedGraphSimilarity::getSimilarityComponents()
{
    // Init result map
    std::map<std::string, double> resultMap;
    // Update components
    resultMap["valueSimilarity"] = this->valueSimilarity;
    resultMap["containmentSimilarity"] = this->containmentSimilarity;
    resultMap["sizeSimilarity"] = this->sizeSimilarity;
    resultMap["normalizedValueSimilarity"] = this->getOverallSimilarity();
    // Return
    return resultMap;
}



double NormalizedGraphSimilarity::getOverallSimilarity()
{
    if (sizeSimilarity == 0)
        return 0;
    else
        return valueSimilarity / sizeSimilarity;
}
