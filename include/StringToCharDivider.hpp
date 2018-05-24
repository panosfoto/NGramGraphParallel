/**
 * \file StringToCharDivider.hpp
 */

#ifndef STRINGTOCHARDIVIDER_H
#define STRINGTOCHARDIVIDER_H

// project headers
#include "Divider.hpp"


// TODO : Add Documentation
class StringToCharDivider : public Divider<std::string>
{
    public:
        /** Default constructor */
        StringToCharDivider();



        /**
         * Constructor that initializes atomSize.
         * \param atomSizeValue The new value for the atomSize variable.
         */
        StringToCharDivider(unsigned int atomSizeValue);



        /** Default destructor */
        virtual ~StringToCharDivider();



        /** Mutator for payload variable.
         * \param setValue The new string that the StringToCharDivider will hold.
         */
        void setPayload(std::string newPayloadValue){ this->payload = newPayloadValue; }



        /** Accessor for payload variable.
         * \return The string that the StringToCharDivider holds.
         */
        std::string getPayload(){ return payload; }



        /**
         * Returns the size of the payload string. Since this divider splits the string to character n-grams, the size of the payload string is its length.
         * \return The length of the payload string.
         */
        unsigned int getPayloadSize();



        /**
         * Provide a readable representation (string) of the data (payload) that the Divider holds.
         * \return Returns a string representing the Divider's payload.
         */
        virtual std::string toString() { return payload; }



        /**
         * Provide a readable representation (string) of the data that the Divider's Atoms hold.
         * \return Returns a vector containing the string representation of each Atom (the atoms themselves in this Divider subclass, since we're dealing with strings).
         */
        virtual vector<std::string> atomsToString();



        /**
         * Splits the Divider's payload to Atoms, filling the atoms vector.\n
         * Splitting is done according to the values of the variables holding the various parameters.
         */
        virtual void splitPayloadToAtoms();



    protected:
        /** \var payload
         * Payload is the original string that the Divider instance holds, e.g. the text/document that will be split into atoms.
         */
        std::string payload;
};

#endif // STRINGTOCHARDIVIDER_H
