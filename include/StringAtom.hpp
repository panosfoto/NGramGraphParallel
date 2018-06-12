/**
 * \file StringAtom.hpp
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
