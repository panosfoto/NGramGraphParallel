/**
 * \file GraphSimilarity.h
 */
#ifndef GRAPHSIMILARITY_H
#define GRAPHSIMILARITY_H

#include "Similarity.h"


/**
 * \Class A class that represents the similarity of graphs
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
        GraphSimilarity(double, double, double);

        /** \brief
         *      A function that returns a map of the similarity constituents, as pairs of the form <SimilarityName, SimilarityValue>.
         * \return map<string, double>
         *      A map with the values of the similarities
         */
        map<string, double> getSimilarityComponents();

        /** \brief
         *      Returns the overall similarity defined as:
         *      valueSimilarity * containmentSimilarity * sizeSimilarity
         *
         * \return double
         *      Returns the overall similarity
         */
        double getOverallSimilarity();

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
