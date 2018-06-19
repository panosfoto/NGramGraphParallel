/**
 * \file Atom.hpp
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

#ifndef ATOM_H
#define ATOM_H

// system headers
#include <string>


/**
 * \Class A class that represents an atom, the smallest entity of a Payload.
 *
 * Templates are used, so that it may contain whichever type of data is needed each time.
 * \note To specialize this class for a specific Atom type, subclass this with the desired type and overwrite the necessary functions.
 */
template <typename AtomType>
class Atom
{
    public:
        // Parameter-less constructor added to avoid errors with boost property initialization:
        // Atom used as template parameter, and by default it calls a parameter less constructor.
        // TODO : check if there is a way to bypass this (e.g. providing an empty string ("") as default parameter).
        /**
         * Constructor for Atom class.
         * \note data is not initialized with this constructor, setData() should be used to avoid undefined behavior by uninitialized data.
         */
        Atom() {}


        /**
         * Constructor for Atom class.
         * \param initialValue The data that the Atom will hold
         *
         */
        Atom(AtomType initialValue);


        /** Default destructor for Atom class */
        virtual ~Atom();


        /**
         * Returns the Atom's data.
         * \return The data that the Atom holds.
         */
        AtomType getData() const { return data; };


        /**
         * Updates the Atom's data.
         * \param newData The new data that the Atom will hold.
         */
        void setData(AtomType newData) { data = newData; };


        /**
         * Provide a readable representation (string) of the data that the Atom holds.
         * \return Returns a string made by the data.
         */
        std::string toString();


        /**
         * Compares the Atom with another Atom instance.
         * \param other A reference to an Atom instance to be compared with.
         * \return A boolean value: True if the two Atoms are identical, otherwise False.
         * \note Should be type-based overwritten to compare correctly depending on type used.
         */
        bool operator==(const Atom& other) const;


        /**
         * Assignment operator for Atom instances.
         * \param aSource A reference to the source Atom instance, whose values will be assigned to this.
         * \note Should be type-based overwritten (template specialization) to assign correctly depending on type used.
         */
        void operator=(const Atom& aSource);


    protected:
        /** \var data
         * The data that the Atom holds.
         */
        AtomType data;
};


// template implementation file
#include "templateImp/Atom.tcc"


#endif // ATOM_H
