/**
 * \file main.cpp
 */

#include <iostream>
#include "Atom.hpp"
#include "GraphSimilarity.hpp"
#include "DivisibleObject.hpp"
#include "NGramGraph.hpp"

using namespace std;

int main(){
    Atom<int> iAtom(42);
    cout << iAtom.toString() << endl;
    cout << iAtom.getPayload() << endl << endl;

    DivisibleObject<string> sDO("Hello");
    sDO.splitPayloadToAtoms(3);
    cout << sDO.toString() << endl;
    cout << sDO.getPayload() << endl;
    cout << "Number of atoms: " << sDO.getAtoms().size() << endl;
    vector<string> sDOAtomsStrings = sDO.atomsToString();
    for (vector<string>::iterator it = sDOAtomsStrings.begin() ; it != sDOAtomsStrings.end() ; ++it)
    {
        cout << *it << endl;
    }
    cout << endl;
    DivisibleObject<int> iDO(5);
    iDO.splitPayloadToAtoms(2);

    NGramGraph<string> g;

    GraphSimilarity gs(0.1, 0.4, 0.2);
    cout << endl << "Overall Similarity: " << gs.getOverallSimilarity() << endl;
    map<string, double> gsValues =  gs.getSimilarityComponents();
    for (map<string, double>::iterator it = gsValues.begin() ; it != gsValues.end() ; ++it)
        cout << it->first << " => " << it->second << endl;

    return 0;
}
