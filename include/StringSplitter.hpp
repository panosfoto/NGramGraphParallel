/**
 * \file StringSplitter.hpp
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

#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H


// project headers
#include "Splitter.hpp"
#include "StringPayload.hpp"


/**
 * \Class A StringSplitter is a Splitter that splits strings. \n
 * This class splits strings into substrings of 'atomSize' characters. Does not apply any form of preprocessing, just uses the string provided "as is". \n
 * Subclasses can overwrite splitPayloadToAtoms() to perform any desired functionality.
 */
class StringSplitter : public Splitter<std::string, std::string>
{
    public:
        /**
         * Default constructor. atomSize set to ATOMSIZE_DEFAULT_VALUE.
         */
        StringSplitter();



        /**
         * Constructor that initializes atomSize.
         * \param atomSizeValue The new value for the atomSize variable.
         */
        StringSplitter(unsigned int atomSizeValue);



        /**
         * Splits the payload to Atoms, and returns the result in a vector.
         * \return A vector with the Atoms to which the payload was split.
         */
        virtual vector<Atom<std::string>> splitPayloadToAtoms(Payload<std::string> *payloadToSplit);
};

#endif // STRINGSPLITTER_H
