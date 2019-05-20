#ifndef Usuario_HPP_
#define Usuario_HPP_

#include "cadena.hpp"
#include "tarjeta.hpp"
#include <map>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include "cadena.hpp"
#include <random>
#include "unistd.h"
#include "articulo.hpp"

using namespace std;

//class Articulo;
class Tarjeta;
class Numero;

class Clave
{
    public:
        //Constructor
        Clave(const char* );

        //Getter
        Cadena clave() const;
        bool verifica(const char* ) const;

        //Exception stuff
        enum Razon{CORTA, ERROR_CRYPT};

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

class Usuario
{
    public:
        //Asociative  data types
        typedef map<Numero, Tarjeta*> Tarjetas;
        typedef unordered_map<Articulo*, unsigned> Articulos;
        //Repetition control
        static unordered_set<Cadena> users;
    
        //Constructor
        Usuario(const Cadena&, const Cadena&, const Cadena&, const Cadena&,
        const Clave&);
        Usuario(const Usuario&) = delete;
        Usuario& operator =(const Usuario&) = delete;

        //Destructor
        ~Usuario();

        //Getters
        Cadena id() const;
        Cadena nombre() const;
        Cadena apellidos() const;
        Cadena direccion() const;
        Tarjetas tarjetas() const;
        unsigned n_articulos() const;
        Articulos compra() const;
        Clave pass() const;

        //Asociative data methods
        void es_titular_de(Tarjeta&);
        void no_es_titular_de(Tarjeta&);
        void compra(Articulo&, unsigned = 1);

        //Exception stuff
        class Id_duplicado
        {
            public:
                Id_duplicado(const Cadena&);
                Cadena idd() const;
            private:
                Cadena id;
        };
    private:
        Cadena identifier, name, surname, address;
        Clave password;
        Tarjetas cards;
        Articulos shopping_kart;
};

//Operator
ostream& operator <<(ostream& os, const Usuario& u);
void mostrar_carro(ostream&, const Usuario&);

#endif