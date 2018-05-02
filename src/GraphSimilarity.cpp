/**
 * \file GraphSimilarity.cpp
 */
#include "GraphSimilarity.h"

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


map<string, double> GraphSimilarity::getSimilarityComponents()
{
    // Init result map
    map<string, double> resultMap;
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
