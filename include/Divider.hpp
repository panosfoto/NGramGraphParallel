/**
 * \file Divider.hpp
 */

#ifndef DIVIDER_H
#define DIVIDER_H

#include <DivisibleObject.hpp>


class Divider : public DivisibleObject<string>
{
    public:
        /** Default constructor */
        Divider();
        /** Default destructor */
        virtual ~Divider();

    protected:
};


#include "Divider.tcc"


#endif // DIVIDER_H
