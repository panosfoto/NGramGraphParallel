/**
 * \file main.cpp
 */

#include <iostream>
#include "Atom.h"
#include "GraphSimilarity.h"
#include "DivisibleObject.h"

using namespace std;

int main(){
    Atom<int> iAtom(42);
    cout << iAtom.toString() << endl;
    cout << iAtom.getPayload() << endl << endl;

    DivisibleObject<string> sDO("Hello");
    cout << sDO.toString() << endl;
    cout << sDO.getPayload() << endl;
    cout << "Number of atoms: " << sDO.getAtoms().size() << endl;
    vector<string> sDOAtomsStrings = sDO.atomsToString();
    for (vector<string>::iterator it = sDOAtomsStrings.begin() ; it != sDOAtomsStrings.end() ; ++it)
    {
        cout << *it << endl;
    }
    cout << endl;

    GraphSimilarity gs(0.1, 0.4, 0.2);
    cout << "Overall Similarity: " << gs.getOverallSimilarity() << endl;
    map<string, double> gsValues =  gs.getSimilarityComponents();
    for (map<string, double>::iterator it = gsValues.begin() ; it != gsValues.end() ; ++it)
        cout << it->first << " => " << it->second << endl;

    return 0;
}
