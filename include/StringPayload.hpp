/**
 * \file StringPayload.hpp
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
