/**
 * \file NormalizedGraphSimilarity.hpp
 */

#ifndef NORMALIZEDGRAPHSIMILARITY_H
#define NORMALIZEDGRAPHSIMILARITY_H

// project headers
#include "GraphSimilarity.hpp"


/**
 * \Class A class that represents a normalized similarity of graphs. \n
 * Consists of the same 3 basic similarities in GraphSimilarity, but returns the normalized value similarity as the overall similarity: \n
 * The overall similarity is defined as valueSimilarity / SizeSimilarity (or 0, is SizeSimilarity is 0).
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
