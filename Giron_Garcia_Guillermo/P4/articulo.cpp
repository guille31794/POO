#include "articulo.hpp"

//Clas Autor
//########################################################
//Constructor
Autor::Autor(const Cadena& n, const Cadena& sn, const Cadena& ad): 
name{n}, surname{sn}, address{ad}
{}

//Getters
const Cadena& Autor::nombre() const
{
    return name;
}

const Cadena& Autor::apellidos() const
{
    return surname;
}

const Cadena& Autor::direccion() const
{
    return address;
}

//Class Articulo
//########################################################
//Constructor
Articulo::Articulo(const Autores &au, const Cadena &cod, const Cadena &t, const Fecha &f,
double p) : cod_{cod}, title{t}, date{f}, authors{au}, prize{p}
{
    if(au.empty())
        throw Autores_vacios();
}

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
    setlocale(LC_ALL, "es_ES.UTF-8");
    unsigned cont{0};
    os << '[' << a.referencia() << "] \"" << a.titulo() << "\", de ";

    for(auto authors : a.autores())
    {
        os << authors -> apellidos();

        if(cont < a.autores().size() - 1)
            os << ", ";
        
        ++cont;
    }

    os << ". " << a.f_publi().anno() << ". " << setiosflags(ios::fixed) << setprecision(2)
    << a.precio() << " €\n\t";

    a.impresion_especifica(os);

    return os;
}

//Class ArticuloAlmacenable
//#############################################################
//Constructor
ArticuloAlmacenable::ArticuloAlmacenable(const Autores& au, 
const Cadena& ref, const Cadena& ti, const Fecha& d, double pr,
unsigned s):
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
Libro::Libro(const Autores& au, const Cadena& ref, const Cadena& ti, 
const Fecha& d, double pr, unsigned p,
const unsigned s):
ArticuloAlmacenable{au, ref, ti, d, pr, s}, pages{p}
{}

//Getters
unsigned Libro::n_pag() const
{
    return pages;
}

void Libro::impresion_especifica(ostream& os) const
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    os << pages << " págs., " << stock_;
    stock_ == 1 ? os << " unidad." : os << " unidades.";
}

//Class CD
//##############################################################
//Constructor
Cederron::Cederron(const Autores& au, const Cadena& ref, const Cadena& ti, 
const Fecha& d, double pr, unsigned si, unsigned s):
ArticuloAlmacenable{au, ref, ti, d, pr, s}, size_{si}
{}

//Getters
unsigned Cederron::tam() const
{
    return size_;
}

void Cederron::impresion_especifica(ostream& os) const
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    os << size_ << " MB, " << stock_;
    stock_ == 1 ? os << " unidad." : os << " unidades.";
}

//Class LibroDigital
//##############################################################
//Constructor
LibroDigital::LibroDigital(const Autores& au, const Cadena& ref, 
const Cadena& ti, const Fecha& d, double pr, const Fecha& ex):
Articulo{au, ref, ti, d, pr}, expiration{ex}
{}

//Getters
const Fecha& LibroDigital::f_expir() const
{
    return expiration;
}

void LibroDigital::impresion_especifica(ostream& os) const
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    os << "A la venta hasta el " << expiration << ".";
}

