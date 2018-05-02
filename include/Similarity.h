/**
 * \file Similarity.h
 */
#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <map>
using namespace std;

/**
 * \Class An abstract class that represents a generic similarity interface. Such a similarity is considered to be composed of basic similarities (at least one)
 * which, through an appropriate calculation, determine the final, overall similarity.
 */
class Similarity
{
    public:
        /** \brief
         *      Used to get the collection of basic similarities, that compose the overall similarity calculation. In trivial cases where
         *      a similarity is not based on constituents, this function is expected to return the overall similarity.
         * \return
         *      A map which contains pairs like <SimilarityName, SimilarityValue>
         */
        virtual map<string, double> getSimilarityComponents() = 0;

        /** \brief
         *      Calculates and returns the overall similarity, based on the constituents.
         * \return
         *      The overall similarity
         */
        virtual double getOverallSimilarity() = 0;
};

#endif // SIMILARITY_H
