/**
 * \file StringToCharDivider.hpp
 */

#ifndef STRINGTOCHARDIVIDER_H
#define STRINGTOCHARDIVIDER_H

#include <Divider.hpp>



class StringToCharDivider : public Divider<std::string>
{
    public:
        /** Default constructor */
        StringToCharDivider();



        /** Default destructor */
        virtual ~StringToCharDivider();



        /** Mutator for payload variable.
         * \param setValue The new string that the StringToCharDivider will hold.
         */
        void setPayload(std::string setValue){ this->payload = setValue; }



        /** Accessor for payload variable.
         * \return The string that the StringToCharDivider holds.
         */
        std::string getPayload(){ return payload; }



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



        /** \var atomSize
         * The length of each atom in characters.\n
         * Defaults to 3.
         */
        unsigned int atomSize = 3;
};

#endif // STRINGTOCHARDIVIDER_H
