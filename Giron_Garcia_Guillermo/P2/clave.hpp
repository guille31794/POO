#ifndef Clave_HPP_
#define Clave_HPP_

#include "cadena.hpp"
#include <random>
#include "unistd.h"

using namespace std;

class Clave
{
    public:
        //Constructor
        Clave(const char* );

        //Getter
        Cadena clave() const;
        bool verifica(const char* ) const;

        //Exception stuff
        const enum Razon{CORTA, ERROR_CRYPT};

        class Incorrecta
        {
            public:
                Incorrecta(Razon);
                Razon razon() const;
            private:
                Razon r_;      
        };
    private:
        Cadena key;
};

#endif