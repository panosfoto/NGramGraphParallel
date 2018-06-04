/**
 * \file StringSplitter.cpp
 */

#include "StringSplitter.hpp"

#include <iostream>


StringSplitter::StringSplitter()
{
    //ctor
}



vector<Atom<std::string>> StringSplitter::splitPayloadToAtoms()
{
    if (atomSize > payload.length())
    {
        // TODO : replace with exception throwing
        cerr << "splitPayloadToAtoms(): Warning: atom size provided is greater than the length of the payload. Payload could not be split." << endl;
        //return;
    }
    vector<Atom<std::string>> atoms;
    std::string tempString;
    Atom<std::string> *tempAtom;
    //test implementation
    for(unsigned int i = 0 ; i < payload.length()-atomSize+1 ; ++i)
    {
        tempString.clear();
        for(unsigned int j = 0 ; j < atomSize ; ++j)
        {
            tempString.push_back(payload[i+j]);
        }
        tempString.push_back('\0');
        tempAtom = new Atom<std::string>(tempString);
        atoms.push_back(*tempAtom);
        // added so valgrind won't count it as a memory leak
        delete tempAtom;
    }
    return atoms;
}
