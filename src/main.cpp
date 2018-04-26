#include <iostream>
#include "Atom.h"
#include "GraphSimilarity.h"

using namespace std;

int main(){
    Atom<int> iAtom(42);
    cout << iAtom.toString() << endl;
    cout << iAtom.getPayload() << endl << endl;

    GraphSimilarity gs(0.1, 0.4, 0.2);
    cout << "Overall Similarity: " << gs.getOverallSimilarity() << endl;
    map<string, double> gsValues =  gs.getSimilarityComponents();
    for (map<string, double>::iterator it = gsValues.begin() ; it != gsValues.end() ; ++it)
        cout << it->first << " => " << it->second << endl;

    return 0;
}
