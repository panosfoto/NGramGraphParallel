/**
 * \file Payload.hpp
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

#ifndef PAYLOAD_H
#define PAYLOAD_H


// system headers
#include <string>


/**
 * \Class An abstract class that describes the Payload, a form of data that can be split into smaller parts (Atoms).\n
 * Usage: Every ProximityGraph holds a Payload. When the ProximityGraph creates its graph, it splits the Payload into Atoms and uses these Atoms as the graph's vertices.
 */
template <typename PayloadType>
class Payload
{
    public:
        /** Default destructor */
        virtual ~Payload() {}



        /**
         * Provide a readable representation (string) of the payload.
         * \return A string representing the payload.
         */
        virtual std::string toString() = 0;



        /** Accessor for payload variable.
         * \return The Payload's data.
         */
        virtual PayloadType getPayload() { return payload; }



        /** Mutator for payload variable.
         * \param newPayload The new payload that the Payload will hold.
         */
        virtual void setPayload(PayloadType newPayload) { payload = newPayload; }



    protected:
        /** \var payload
         * Payload is some form of data that can be split into smaller parts (atoms), e.g. a word that can be split into character sequences ("Hello" -> "Hel", "ell", "llo").
         */
        PayloadType payload;
};

#endif // PAYLOAD_H
