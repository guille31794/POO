#ifndef Usuario_HPP_
#define Usuario_HPP_

#include "cadena.hpp"
#include "clave.hpp"
#include "tarjeta.hpp"
#include <map>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Usuario
{
    public:
        //Asociative  data types
        typedef map<Numero, Tarjeta*> Tarjetas;
        typedef unordered_map<Articulo*, unsigned> Articulos;
    
        //Constructor
        Usuario(const char*, const char*, const char*, const char*,
        const char*);
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
        void es_titular_de(const Tarjeta&);
        void no_es_titular_de(const Tarjeta&);
        void compra(const Articulo&, const unsigned = 1);

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
        //Repetition control
        static unordered_set<Usuario> users;
};

//Operator
ostream& operator <<(ostream& os, const Usuario& u);
ostream& mostrar_carro(ostream&, const Usuario&);

#endif