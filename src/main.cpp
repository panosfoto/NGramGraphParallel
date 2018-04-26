#include <iostream>
#include "Atom.h"

using namespace std;

int main(){
    Atom<int> iAtom(10);
    cout << iAtom.toString() << endl;

    return 0;
}
