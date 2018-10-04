/**
 * \file main.cpp
 *
 * \author Panagiotis Fotopoulos
 *
 * \copyright Copyright 2018 NCSR Demokritos Greece \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. \n
 */

#include <iostream>
#include "GraphSimilarity.hpp"
#include "GraphComparator.hpp"
#include "NGramGraph.hpp"
#include "UniqueVertexGraph.hpp"
#include "StringAtom.hpp"
#include "StringSplitter.hpp"

#define TEXT_PAYLOAD "This is a test sentence."

using namespace std;

int main(){

    // An example of graph creation:

    // Declare a splitter for the Proximity Graph (string splitter here, since we will split a text to n-grams).
    StringSplitter testStringSplitter(4);

    // Set the size of the atoms (n-grams in this  case). Default is 3.
    testStringSplitter.setAtomSize(NGRAMSIZE_DEFAULT_VALUE);

    // Declare the payload of the Proximity Graph (the entity that will be split to atoms). We are using a text in this example, so it will be a string payload.
    StringPayload testStringPayload(TEXT_PAYLOAD);

    // Declare the Proximity Graph. We will split a text into n-grams, so we are using an NGramGraph which is a ProximityGraph for this use.
    // The NGramGraph has a built-in basic Proximity Evaluator so we won't explicitly pass one, but it needs a String Splitter and a String Payload to split.
    NGramGraph testNGramGraph(nullptr, &testStringSplitter, &testStringPayload, 2);

    // Create the graph from the text (StringPayload) and print it in DOT format.
    testNGramGraph.createGraph();
    testNGramGraph.printGraphviz();
    testNGramGraph.printGraphvizToFile("out.dot");



    // -------------------------------------------------------------------------------------------
    cout << endl << endl << "-------------------------" << endl << endl << endl;



    // An example of graph comparison:

    // Declare an instance of GraphSimilarity to hold the comparison's result
    GraphSimilarity testGraphSimilarity;

    // Declare the graph comparator
    GraphComparator<std::string, std::string> testGraphComparator;

    // Compare the previous graph with itself and store the result to testGraphSimilarity
    testGraphSimilarity = testGraphComparator.compare(testNGramGraph, testNGramGraph);

    // Display the size similarity (from the various similarity components) of the two compared graphs.
    map<string, double> testSimilarityComponents =  testGraphSimilarity.getSimilarityComponents();
    cout << "Size Similarity: " << testSimilarityComponents["sizeSimilarity"] << endl;
    // Since they are the same graph, their size is equal, therefore the similarity is 1.

    return 0;

}
