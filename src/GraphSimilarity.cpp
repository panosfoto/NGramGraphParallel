/**
 * \file GraphSimilarity.cpp
 */
#include "GraphSimilarity.h"

/** \brief
 *      Default constructor. Sets all similarity values to 0
 */
GraphSimilarity::GraphSimilarity()
{
    this->valueSimilarity = 0.0;
    this->containmentSimilarity = 0.0;
    this->sizeSimilarity = 0.0;
}


/** \brief
 *      A constructor that initializes the similarity values with the according provided parameters
 * \param valueSimilarity double
 * \param containmentSimilarity double
 * \param sizeSimilarity double
 *
 */
GraphSimilarity::GraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity)
{
    this->valueSimilarity = valueSimilarity;
    this->containmentSimilarity = containmentSimilarity;
    this->sizeSimilarity = sizeSimilarity;
}


/** \brief
 *      A function that returns  a convenient way to see the similarities defined in this subclass and their values,
 *      in the form of pairs <SimilarityName, SimilarityValue>
 * \return map<string, double>
 *      Returns  a map with the values of the similarities
 */
map<string, double> GraphSimilarity::getSimilarityComponents()
{
    map<string, double> resultMap;
    resultMap["valueSimilarity"] = this->valueSimilarity;
    resultMap["containmentSimilarity"] = this->containmentSimilarity;
    resultMap["sizeSimilarity"] = this->sizeSimilarity;
    return resultMap;
}


/** \brief
 *      Returns the overall similarity defined as:
 *      valueSimilarity * containmentSimilarity * sizeSimilarity
 * \return double
 *      Returns the overall similarity
 */
double GraphSimilarity::getOverallSimilarity()
{
    return this->valueSimilarity*this->containmentSimilarity*this->sizeSimilarity;
}
