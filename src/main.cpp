#include <iostream>
#include "Atom.h"

using namespace std;

int main(){
    Atom<string> iAtom("hello!");
    cout << iAtom.toString() << endl;

    return 0;
}
