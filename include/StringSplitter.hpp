/**
 * \file StringSplitter.hpp
 */

#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H


// project headers
#include "Splitter.hpp"


/**
 * \Class A StringSplitter is a Splitter that splits strings. The payload defined is of std::string type. \n
 * This class splits strings into substrings of 'atomSize' characters. Does not apply any form of preprocessing, just uses the string provided "as is". \n
 * Subclasses can overwrite splitPayloadToAtoms() to perform any desired functionality.
 */
class StringSplitter : public Splitter<std::string>
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



        /** Mutator for payload variable.
         * \param setValue The new string that the StringSplitter will hold.
         */
        void setPayload(std::string newPayloadValue){ this->payload = newPayloadValue; }



        /** Accessor for payload variable.
         * \return The string that the StringSplitter holds.
         */
        std::string getPayload(){ return payload; }



        /**
         * Provide a readable representation (string) of the data (payload) that the Splitter holds.
         * \return A string representing the StringSplitter's payload.
         */
        virtual std::string toString() { return payload; }



        /**
         * Splits the payload to Atoms, and returns the result in a vector.
         * \return A vector with the Atoms to which the payload was split.
         */
        virtual vector<Atom<std::string>> splitPayloadToAtoms();



    protected:
        /** \var payload
         * Payload is the original string that the StringSplitter instance holds, e.g. the text/document that will be split into atoms.
         */
        std::string payload;
};

#endif // STRINGSPLITTER_H
