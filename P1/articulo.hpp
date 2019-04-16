#ifndef Articulo_HPP_
#define Articulo_HPP_

#include "fecha.hpp"
#include "cadena.hpp"
#include <iomanip>

using namespace std;

class Articulo
{
    public:
        //Constructors
        explicit Articulo(const Cadena&, const Cadena&, const Fecha& , 
        const double, const unsigned);

        //Getters
        Cadena referencia() const;
        Cadena titulo() const;
        Fecha f_publi() const;
        double precio() const;
        unsigned stock() const;

        //Setters
        double& precio();
        unsigned& stock(); 
    private:
        Cadena cod_;
        Cadena title;
        Fecha date;
        double prize;
        unsigned stock_;
};

ostream& operator <<(ostream&, const Articulo&);

#endif