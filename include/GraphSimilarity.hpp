/**
 * \file GraphSimilarity.hpp
 */

#ifndef GRAPHSIMILARITY_H
#define GRAPHSIMILARITY_H

// system headers
#include "Similarity.hpp"



/**
 * \Class A class that represents the similarity of graphs. Consists of 3 basic similarities: \n
 * valueSimilarity, regarding the existence and weight of edges of the graphs, \n
 * containmentSimilarity, regarding the existence of edges of the graphs, \n
 * sizeSimilarity, regarding the number of edges of the graphs. \n
 * The overall similarity is defined as the product of the 3 basic similarities.
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
         * \param normalizedValueSimilarity (double) The normalizedValueSimilarity component value.
         *
         */
        GraphSimilarity(double valueSimilarity, double containmentSimilarity, double sizeSimilarity, double normalizedValueSimilarity);



        /** \brief
         *      A function that returns a map of the similarity constituents, as pairs of the form <SimilarityName, SimilarityValue>.
         * \return map<string, double>
         *      A map with the values of the similarities
         */
        std::map<std::string, double> getSimilarityComponents();



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



        /** \var normalizedValueSimilarity
         * Similarity regarding the number of edges and the size of the graphs
         */
        double normalizedValueSimilarity;
};

#endif // GRAPHSIMILARITY_H
