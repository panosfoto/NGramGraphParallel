/**
 * \file StringAtom.hpp
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

#ifndef STRINGATOM_H
#define STRINGATOM_H

#include <Atom.hpp>


/**
 * \Class A class that represents an Atom holding a string.
 */
class StringAtom : public Atom<std::string>
{
    public:
        /** Default constructor */
        StringAtom(std::string s);



        /** Default destructor */
        virtual ~StringAtom();



        /**
         * Compares the StringAtom with another StringAtom instance.
         * \param other A reference to an StringAtom instance to be compared with.
         * \return A boolean value: True if the two StringAtoms are identical, otherwise False.
         */
        bool operator==(const StringAtom& other) const;
};

#endif // STRINGATOM_H
