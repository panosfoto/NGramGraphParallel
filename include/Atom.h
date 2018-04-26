#ifndef ATOM_H
#define ATOM_H

#include <string>

template <class AtomType>
class Atom
{
    public:
        /** Default constructor */
        Atom();
        /** Default destructor */
        virtual ~Atom();

        AtomType getPayload() { return payload; };
        std::string toString() { return std::to_string(payload);}

    protected:
        AtomType payload;

    private:
};

#endif // ATOM_H
