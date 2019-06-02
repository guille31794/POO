#include "articulo.hpp"

//Clas Autor
//########################################################
//Constructor
Autor::Autor(const Cadena& n, const Cadena& sn, const Cadena& ad): 
name{n}, surnames{sn}, address{ad}
{}

//Getters
const Cadena& Autor::nombre() const
{
    return name;
}

const Cadena& Autor::apellidos() const
{
    return surnames;
}

const Cadena& Autor::direccion() const
{
    return address;
}

//Class Articulo
//########################################################
//Constructor
Articulo::Articulo(Autores& au, const Cadena& cod, const Cadena& t, const Fecha& f,
double p): authors{au}, cod_{cod}, title{t}, date{f}, prize{p}
{}

//Getters
Cadena Articulo::referencia() const
{
    return cod_;
}

Cadena Articulo::titulo() const
{
    return title;
}

Fecha Articulo::f_publi() const
{
    return date;
}

double Articulo::precio() const
{
    return prize;
}

const Articulo::Autores& Articulo::autores() const
{
    return authors;
}

//Setters
double& Articulo::precio()
{
    return prize;
}

//Operators
ostream& operator <<(ostream& os, const Articulo& a)
{
    os << '[' << a.referencia() << "] \"" << a.titulo() << "\", " << 
    a.f_publi().anno() << ". " << setiosflags(ios::fixed) << setprecision(2)
    << a.precio() << " €";

    return os;
}

//Class ArticuloAlmacenable
//#############################################################
//Constructor
ArticuloAlmacenable::ArticuloAlmacenable(Autores& au, 
const Cadena& ref, const Cadena& ti, const Fecha& d, const double pr,
const unsigned s):
Articulo{au, ref, ti, d, pr}, stock_{s}
{}

//Getters
unsigned ArticuloAlmacenable::stock() const
{
    return stock_;
}

//Setters
unsigned& ArticuloAlmacenable::stock()
{
    return stock_;
}

//Class Libro
//###############################################################
//Constructor
Libro::Libro(Autores& au, const Cadena& ref, const Cadena& ti, 
const Fecha& d, const double pr, const unsigned p,
const unsigned s):
ArticuloAlmacenable{au, ref, ti, d, pr, s}, pages{p}
{}

//Getters
unsigned Libro::n_paginas() const
{
    return pages;
}

void Libro::impresion_especifica(ostream& os) const
{
    setlocale(LC_ALL, "es_ES");
    os << pages << " págs., " << stock_;
    stock_ == 1 ? os << " unidad.\n" : os << " unidades.\n";
}

//Class CD
//##############################################################
//Constructor
Cederrom::Cederrom(Autores& au, const Cadena& ref, const Cadena& ti, 
const Fecha& d, const double pr, const unsigned si,
const unsigned s):
ArticuloAlmacenable{au, ref, ti, d, pr, s}, size_{si}
{}

//Getters
unsigned Cederrom::tam() const
{
    return size_;
}

void Cederrom::impresion_especifica(ostream& os) const
{
    setlocale(LC_ALL, "es_ES");
    os << size_ << "MB, " << stock_ << " unidades.\n";
}

//Class LibroDigital
//##############################################################
//Constructor
LibroDigital::LibroDigital(Autores& au, const Cadena& ref, 
const Cadena& ti, const Fecha& d, const double pr, const Fecha& ex):
Articulo{au, ref, ti, d, pr}, expiration{ex}
{}

//Getters
const Fecha& LibroDigital::f_expir() const
{
    return expiration;
}

void LibroDigital::impresion_especifica(ostream& os) const
{
    setlocale(LC_ALL, "es_ES");
    os << "A la venta hasta el " << expiration << ".\n";
}

