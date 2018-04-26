/**
 * \file Similarity.h
 */
#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <map>
using namespace std;

/**
 * \Class A class that represents a generic similarity interface
 */
class Similarity
{
    public:
        /** \brief
         *      Used to get a collection of the similarities defined in sub-class with their values
         * \return
         *      Returns a map which contains pairs like <SimilarityName, SimilarityValue>
         */
        virtual map<string, double> getSimilarityComponents() = 0;

        /** \brief
         *      Used to get the overall similarity, as it is defined in the sub-class
         * \return
         *      Returns the overall similarity
         */
        virtual double getOverallSimilarity() = 0;
};

#endif // SIMILARITY_H
