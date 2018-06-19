/**
 * \file NormalizedGraphSimilarity.cpp
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
