/**
 * \file main.cpp
 */

#include <iostream>
#include "Atom.hpp"
#include "GraphSimilarity.hpp"
#include "StringToCharDivider.hpp"
//#include "NGramGraph.hpp"
#include "UniqueVertexGraph.hpp"

//#define TEXT_PAYLOAD "Betty Butters bought some bitter butter, but the butter was too bitter, so she bought a better butter to make the bitter butter better."
#define TEXT_PAYLOAD "Hope..."

using namespace std;

int main(){
    Atom<int> iAtom(42);
    cout << iAtom.toString() << endl;
    cout << iAtom.getPayload() << endl << endl;

    StringToCharDivider sCD;
    sCD.setPayload("Hello");
    sCD.splitPayloadToAtoms();
    cout << sCD.toString() << endl;
    cout << sCD.getPayload() << endl;
    cout << "Number of atoms: " << sCD.getAtoms().size() << endl;
    vector<string> sCDAtomsStrings = sCD.atomsToString();
    for (vector<string>::iterator it = sCDAtomsStrings.begin() ; it != sCDAtomsStrings.end() ; ++it)
    {
        cout << *it << endl;
    }
    cout << endl;
//    DivisibleObject<int> iDO(5);
//    iDO.splitPayloadToAtoms(2);

    Atom<string> a1("a1"), a2("a2"), a3("a3");
    UniqueVertexGraph<string> uvg;
    uvg.addVertex(a1);
    uvg.addVertex(a2);
    uvg.addEdge(a1, a2, 1.43);
    uvg.addEdge(a1, a2, 2.43);
    cout << uvg.contains(a1) << " " << uvg.contains(a2) << " " << uvg.contains(a3) << endl;
    cout << endl;

//    NGramGraph<string> g;
//    g.divider.setPayload(TEXT_PAYLOAD);
//    g.divider.splitPayloadToAtoms();
//    cout << g.divider.toString() << endl;
//    cout << g.divider.getPayload() << endl;
//    cout << "Number of atoms: " << g.divider.getAtoms().size() << endl;
//    vector<string> gDAtomsStrings = g.divider.atomsToString();
//    for (vector<string>::iterator it = gDAtomsStrings.begin() ; it != gDAtomsStrings.end() ; ++it)
//    {
//        cout << *it << endl;
//    }
//    cout << endl;

    GraphSimilarity gs(0.1, 0.4, 0.2);
    cout << endl << "Overall Similarity: " << gs.getOverallSimilarity() << endl;
    map<string, double> gsValues =  gs.getSimilarityComponents();
    for (map<string, double>::iterator it = gsValues.begin() ; it != gsValues.end() ; ++it)
        cout << it->first << " => " << it->second << endl;

    return 0;
}
