#ifndef Articulo_HPP_
#define Articulo_HPP_

#include "fecha.hpp"
#include "cadena.hpp"
#include <iomanip>
#include <iostream>
#include <set>

using namespace std;

class Autor
{
    public:
        //Constructor
        Autor(const Cadena&, const Cadena&, const Cadena&);

        //Getters
        const Cadena& nombre() const;
        const Cadena& apellidos() const;
        const Cadena& direccion() const;
    private:
        const Cadena name, surnames, address;
};

class Articulo
{
    public:
        //Constructors
        typedef set<Autor*> Autores;
        explicit Articulo(const Autores&, const Cadena&, const Cadena&, const Fecha& , 
        const double);

        //Getters
        Cadena referencia() const;
        Cadena titulo() const;
        Fecha f_publi() const;
        double precio() const;
        
        const Autores& autores() const;

        //Setters
        double& precio();

        //Abstract class
        virtual void impresion_especifica(ostream&) const = 0;
        virtual ~Articulo() = default;

        //Exception stuff
        class Autores_vacios{}; 
    private:
        Cadena cod_;
        Cadena title;
        Fecha date;
        Autores authors;
        double prize;
};

ostream& operator <<(ostream&, const Articulo&);

class ArticuloAlmacenable: public Articulo
{
    public:
        //Constructor
        ArticuloAlmacenable(Autores&, const Cadena&, const Cadena&, const Fecha& , 
        const double, const unsigned = 0);

        //Getters
        unsigned stock() const;
        //Setters
        unsigned& stock();

        //Abstract class
        virtual void impresion_especifica(ostream&) const = 0;
        virtual ~ArticuloAlmacenable() = default;
    protected:
        unsigned stock_;
};

class Libro: public ArticuloAlmacenable
{
    public:
        Libro(Autores&, const Cadena&, const Cadena&, const Fecha& , 
        const double, const unsigned, const unsigned = 0);
        //Getters
        unsigned n_paginas() const;
        void impresion_especifica(ostream&) const;
        //Destructor
        ~Libro() = default;
    private:
        unsigned pages;
};

class Cederron: public ArticuloAlmacenable
{
    public:
        Cederron(Autores&, const Cadena&, const Cadena&, const Fecha&,
        const double, const unsigned, const unsigned = 0);
        //Getters
        unsigned tam() const;
        void impresion_especifica(ostream&) const;
        //Destructor
        ~Cederron() = default;
    private:
        unsigned size_;
};

class LibroDigital: public Articulo
{
    public:
        //Constructor
        LibroDigital(Autores&, const Cadena&, const Cadena&, const Fecha& , 
        const double, const Fecha&);
        //Getters
        const Fecha& f_expir() const;
        void impresion_especifica(ostream&) const;
        //Destructor
        ~LibroDigital() = default;
    private:
        Fecha expiration;
};

#endif