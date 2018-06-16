/**
 * \file GraphSimilarity.cpp
 */

#include "GraphSimilarity.hpp"



GraphSimilarity::GraphSimilarity()
{
    this->valueSimilarity = 0.0;
    this->containmentSimilarity = 0.0;
    this->sizeSimilarity = 0.0;
    this->normalizedValueSimilarity = 0.0;
}



GraphSimilarity::GraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity, double normalizedValueSimilarity)
{
    this->valueSimilarity = valueSimilarity;
    this->containmentSimilarity = containmentSimilarity;
    this->sizeSimilarity = sizeSimilarity;
    this->normalizedValueSimilarity = normalizedValueSimilarity;
}



std::map<std::string, double> GraphSimilarity::getSimilarityComponents()
{
    // Init result map
    std::map<std::string, double> resultMap;
    // Update components
    resultMap["valueSimilarity"] = this->valueSimilarity;
    resultMap["containmentSimilarity"] = this->containmentSimilarity;
    resultMap["sizeSimilarity"] = this->sizeSimilarity;
    resultMap["normalizedValueSimilarity"] = this->normalizedValueSimilarity;
    return resultMap;
}



double GraphSimilarity::getOverallSimilarity()
{
    return this->valueSimilarity*this->containmentSimilarity*this->sizeSimilarity;
}
