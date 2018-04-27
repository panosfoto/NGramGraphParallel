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
         * This is a brief 1st test.
         * 
         * And this is the start of the longer version.
         */
        GraphSimilarity();
        GraphSimilarity(double, double, double);

        map<string, double> getSimilarityComponents();

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
