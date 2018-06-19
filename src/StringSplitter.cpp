/**
 * \file StringSplitter.cpp
 *
 * \author Panagiotis Fotopoulos
 *
 * \copyright Copyright 2018 NCSR Demokritos Greece \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. \n
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
