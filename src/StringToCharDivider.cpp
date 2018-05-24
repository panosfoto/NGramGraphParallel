/**
 * \file StringToCharDivider.cpp
 */

#include "StringToCharDivider.hpp"

#include <iostream>



StringToCharDivider::StringToCharDivider()
{
    //ctor
}



StringToCharDivider::StringToCharDivider(unsigned int atomSizeValue) : Divider(atomSizeValue)
{
    //ctor
}



StringToCharDivider::~StringToCharDivider()
{
    //dtor
}



vector<std::string> StringToCharDivider::atomsToString()
{
    vector<string> returnVector;
    for(typename vector<Atom<std::string>>::iterator it = atoms.begin() ; it != atoms.end() ; ++it)
    {
        returnVector.push_back((*it).toString());
    }
    return returnVector;
}



void StringToCharDivider::splitPayloadToAtoms()
{
    if (atomSize > payload.length())
    {
        // TODO : replace with exception throwing
        cerr << "splitPayloadToAtoms(): Warning: atom size provided is greater than the length of the payload. Payload could not be split." << endl;
        return;
    }
    std::string tempString;
    Atom<std::string> *tempAtom;
    atoms.clear();
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
}



unsigned int StringToCharDivider::getPayloadSize()
{
    return payload.length();
}
