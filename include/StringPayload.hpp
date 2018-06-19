/**
 * \file StringPayload.hpp
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

#ifndef STRINGPAYLOAD_H
#define STRINGPAYLOAD_H


// project headers
#include "Payload.hpp"


class StringPayload : public Payload<std::string>
{
    public:
        /** Default constructor */
        StringPayload();



        /** Constructor that initializes the payload.
         * \var payloadValue The string that will be the payload's data.
         */
        StringPayload(std::string payloadValue);



        /** Default destructor */
        virtual ~StringPayload();



        /**
         * Provide a readable representation (string) of the payload. In this case, it's the payload itself.
         * \return The payload string.
         */
        virtual std::string toString();
};

#endif // STRINGPAYLOAD_H
