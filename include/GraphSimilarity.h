#ifndef GRAPHSIMILARITY_H
#define GRAPHSIMILARITY_H

#include "Similarity.h"


/**
 * \Class A class that represents the similarity of graphs
 */
class GraphSimilarity : public Similarity
{
    public:
        GraphSimilarity();
        GraphSimilarity(double, double, double);

        map<string, double> getSimilarityComponents();

        double getOverallSimilarity();

    protected:
        double valueSimilarity;
        double containmentSimilarity;
        double sizeSimilarity;
};

#endif // GRAPHSIMILARITY_H
