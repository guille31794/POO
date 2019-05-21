#ifndef Numero_HPP_
#define Numero_HPP_

#include "cadena.hpp"
#include <cctype>
#include "../luhn.cpp"

class Numero
{
    public:
        //Constructor
        Numero(const Cadena&);

        //Operator
        operator char*() const;

        //Exception stuff
        const enum Razon{LONGITUD, DIGITOS, NO_VALIDO};

        class Incorrecto
        {
            public:
                Incorrecto(const Razon);
                Razon razon() const;
            private:
                Razon r_;
        };
    private:
        Cadena num;
};

#endif