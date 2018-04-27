/**
 * \file GraphSimilarity.cpp
 */
#include "GraphSimilarity.h"

/**
 *      Default constructor. Sets all similarity values to 0
 * 
 * An example code to use this class is as follows:
 * @code
 * GraphSimilarity gs = new GraphSimilarity::GraphSimilarity();
 * @endcode
 */
GraphSimilarity::GraphSimilarity()
{
    this->valueSimilarity = 0.0;
    this->containmentSimilarity = 0.0;
    this->sizeSimilarity = 0.0;
}


/** \brief
 *      A constructor that initializes the similarity values with the according provided parameters
 * \param valueSimilarity (double) The valueSimilarity component value.
 * \param containmentSimilarity (double) The containmentSimilarity component value.
 * \param sizeSimilarity (double) The sizeSimilarity component value.
 *
 */
GraphSimilarity::GraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity)
{
    this->valueSimilarity = valueSimilarity;
    this->containmentSimilarity = containmentSimilarity;
    this->sizeSimilarity = sizeSimilarity;
}


/** \brief
 *      A function that returns a map of the similarity constituents, as pairs of the form <SimilarityName, SimilarityValue>.
 * \return map<string, double>
 *      A map with the values of the similarities
 */
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


/** \brief
 *      Returns the overall similarity defined as:
 *      valueSimilarity * containmentSimilarity * sizeSimilarity
 * 
 * \return double
 *      Returns the overall similarity
 */
double GraphSimilarity::getOverallSimilarity()
{
    return this->valueSimilarity*this->containmentSimilarity*this->sizeSimilarity;
}
