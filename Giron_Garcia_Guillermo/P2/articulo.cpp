#include "articulo.hpp"

Articulo::Articulo(const Cadena& cod, const Cadena& t, const Fecha& f,
double p, unsigned s): cod_{cod}, title{t}, date{f}, prize{p}, stock_{s}
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

unsigned Articulo::stock() const
{
    return stock_;
}

//Setters
double& Articulo::precio()
{
    return prize;
}

unsigned& Articulo::stock()
{
    return stock_;
}

//Operators
ostream& operator <<(ostream& os, const Articulo& a)
{
    os << '[' << a.referencia() << "] \"" << a.titulo() << "\", " << 
    a.f_publi().anno() << ". " << setiosflags(ios::fixed) << setprecision(2)
    << a.precio() << " €";

    return os;
}