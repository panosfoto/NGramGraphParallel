/**
 * \file Atom.tcc
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

#include <sstream>


template <typename AtomType>
Atom<AtomType>::Atom(AtomType initialValue)
{
    data = initialValue;
}



template <typename AtomType>
Atom<AtomType>::~Atom()
{
    //dtor
}



template <typename AtomType>
std::string Atom<AtomType>::toString()
{
    std::ostringstream ss;
    ss << data;
    return ss.str();
}



template <typename AtomType>
bool Atom<AtomType>::operator==(const Atom& other) const
{
    return this->data == other.data;
}



template <typename AtomType>
void Atom<AtomType>::operator=(const Atom& aSource)
{
    this->data = aSource.data;
}



namespace std {

    template <typename AtomType>
    struct hash<Atom<AtomType>>
    {
        std::size_t operator()(const Atom<AtomType>& a) const
        {
            return hash<AtomType>()(a.getData());
        }
    };

}
