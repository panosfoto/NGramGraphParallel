#ifndef STRINGATOM_H
#define STRINGATOM_H

#include <Atom.hpp>


class StringAtom : public Atom<std::string>
{
    public:
        /** Default constructor */
        StringAtom(std::string s);
        /** Default destructor */
        virtual ~StringAtom();
        bool operator==(const StringAtom& other) const;

    protected:

    private:
};

#endif // STRINGATOM_H
