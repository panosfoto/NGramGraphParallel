/**
 * \file StringSplitter.cpp
 */

#include "StringSplitter.hpp"

#include <iostream>


StringSplitter::StringSplitter()
{
    //ctor
}


StringSplitter::StringSplitter(unsigned int atomSizeValue) : Splitter(atomSizeValue)
{
    //ctor
}



vector<Atom<std::string>> StringSplitter::splitPayloadToAtoms(Payload<std::string> *payloadToSplit)
{
    if (atomSize > (*payloadToSplit).getPayload().length())
    {
        // TODO : replace with exception throwing
        cerr << "splitPayloadToAtoms(): Warning: atom size provided is greater than the length of the payload. Payload could not be split." << endl;
        //return;
    }
    vector<Atom<std::string>> atoms;
    std::string tempString;
    Atom<std::string> *tempAtom;
    //test implementation
    for(unsigned int i = 0 ; i < (*payloadToSplit).getPayload().length()-atomSize+1 ; ++i)
    {
        tempString.clear();
        for(unsigned int j = 0 ; j < atomSize ; ++j)
        {
            tempString.push_back((*payloadToSplit).getPayload()[i+j]);
        }
        tempAtom = new Atom<std::string>(tempString);
        atoms.push_back(*tempAtom);
        // added so valgrind won't count it as a memory leak
        delete tempAtom;
    }
    return atoms;
}
