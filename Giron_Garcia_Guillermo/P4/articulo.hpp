#ifndef ARTICULO_HPP
#define ARTICULO_HPP

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
        const Cadena name, surname, address;
};

class Articulo
{
    public:
        //Exception stuff
        class Autores_vacios{};

        //Definition types
        typedef set<Autor*> Autores;

        //Constructor
        explicit Articulo(const Autores&, const Cadena&, const Cadena&,
        const Fecha&, double);

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
    private:
        Cadena cod_, title;
        Fecha date;
        Autores authors;
        double prize;
};

//Operator
ostream& operator <<(ostream&, const Articulo&);

class ArticuloAlmacenable: public Articulo
{
    public:
        //Constructor
        ArticuloAlmacenable(const Autores&, const Cadena&, const Cadena&,
        const Fecha&, double, unsigned = 0);

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
        //Constructor
        Libro(const Autores&, const Cadena&, const Cadena&,
        const Fecha&, double, unsigned, unsigned = 0);

        //Getters
        unsigned n_pag() const;
        void impresion_especifica(ostream&) const;

        //Destructor
        ~Libro() = default;
    private:
        unsigned pages;
};

class Cederron: public ArticuloAlmacenable
{
    public:
        //Constructor
        Cederron(const Autores&, const Cadena&, const Cadena&,
        const Fecha&, double, unsigned, unsigned = 0);

        //Getters
        unsigned tam() const;
        void impresion_especifica(ostream&) const;

        //Destructor
        ~Cederron() = default;
    private:
        const unsigned size_;
};

class LibroDigital: public Articulo
{
    public:
        //Constructor
        LibroDigital(const Autores&, const Cadena&, const Cadena&,
        const Fecha&, double, const Fecha&);

        //Getters
        const Fecha& f_expir() const;
        void impresion_especifica(ostream&) const;

        //Destructor
        ~LibroDigital() = default;
    private:
        Fecha expiration;
};

#endif