#ifndef ATOM_H
#define ATOM_H

#include <string>

template <class AtomType>
class Atom
{
    public:
        /** Default constructor */
        Atom(AtomType);
        /** Default destructor */
        virtual ~Atom();

        AtomType getPayload() { return payload; };
        std::string toString();
    protected:
        AtomType payload;
};

#endif // ATOM_H
