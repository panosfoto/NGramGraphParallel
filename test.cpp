/**
 * \file main.cpp
 */

#include <iostream>
#include "Atom.hpp"
#include "GraphSimilarity.hpp"
#include "NGramGraph.hpp"
#include "UniqueVertexGraph.hpp"
#include "StringAtom.hpp"
#include "StringSplitter.hpp"

#define TEXT_PAYLOAD "How many cookies could a good cook cook, if a good cook could cook cookies? A good cook could cook as many cookies as a good cook could, if a good cook could cook cookies."
//#define TEXT_PAYLOAD "Hope..."

using namespace std;

int main(){
    StringSplitter ss;
    cout << ss.getAtomSize() << endl;
    Atom<int> iAtom(42);
    cout << iAtom.toString() << endl;
    cout << iAtom.getData() << endl << endl;

    StringAtom a1("a1"), a2("a2"), a3("a3");
    UniqueVertexGraph<string> uvg;
    uvg.addVertex(a1);
    uvg.addVertex(a2);
    uvg.addVertex(a3);
    uvg.removeVertex(a3);
    uvg.addEdge(a1, a2, 1.43);
    uvg.addEdge(a1, a2, 2.43);
    cout << uvg.contains(a1) << " " << uvg.contains(a2) << " " << uvg.contains(a3) << endl;
    cout << endl;

    StringSplitter sspl(4);
    sspl.setAtomSize(NGRAMSIZE_DEFAULT_VALUE);
    StringPayload sp(TEXT_PAYLOAD);
    NGramGraph ngg(nullptr, &sspl, &sp, 1);
    cout << "Correlation window: " << ngg.getCorrelationWindow() << ", nGram size: " << sspl.getAtomSize() << ", payload size: " << sp.getPayload().length() << endl;
    ngg.createGraph();
    ngg.printGraphvizToFile("out.dot");

    GraphSimilarity gs(0.1, 0.4, 0.2);
    cout << endl << "Overall Similarity: " << gs.getOverallSimilarity() << endl;
    map<string, double> gsValues =  gs.getSimilarityComponents();
    for (map<string, double>::iterator it = gsValues.begin() ; it != gsValues.end() ; ++it)
        cout << it->first << " => " << it->second << endl;

    return 0;
}
