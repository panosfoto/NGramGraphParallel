/**
 * \file StringAtom.cpp
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

#include "StringAtom.hpp"

StringAtom::StringAtom(std::string s) : Atom<std::string> (s)
{
    //ctor
}

StringAtom::~StringAtom()
{
    //dtor
}

bool StringAtom::operator==(const StringAtom& other) const
{
    return this->data.compare(other.data) == 0;
}
