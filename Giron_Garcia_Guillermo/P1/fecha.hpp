#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <ctime>
#include <clocale>
#include <cstring>
#include <cstdio>
#include <iostream>
#include "cadena.hpp"

using namespace std;

//class Cadena;

class Fecha
{    
    public:
        //Consts.
        static const unsigned AnnoMinimo;
        static const unsigned AnnoMaximo;

        //Constructors
        explicit Fecha(unsigned day = 0, unsigned month = 0, unsigned year = 0);
        Fecha(const char* s);

        //Exception class
        class Invalida
        {
            public:
                //ructor
                Invalida(const char* s);
                //Observer
                 char* por_que() ;
            private:
                char* error;
        };

        //Operators
        
        Fecha& operator =(const Fecha& f) = default;
        Fecha& operator ++();
        Fecha operator ++(int n);
        Fecha& operator --();
        Fecha operator --(int n);
        Fecha& operator +=(int n);
        Fecha& operator -=(int n);
         char* cadena() const;

        //Getters
        int dia() const;
        int mes() const;
        int anno() const;

    private:
        const bool bisiesto() const;
        unsigned day_, month_, year_;
};

//External Operators
Fecha operator +(const Fecha& f, unsigned n);
Fecha operator +(unsigned n, const Fecha& f);
Fecha operator -(const Fecha& f, unsigned n);
Fecha operator -(unsigned n, const Fecha& f);
bool operator <(const Fecha& f1, const Fecha& f2);
bool operator >(const Fecha& f1, const Fecha& f2);
bool operator <=(const Fecha& f1, const Fecha& f2);
bool operator >=(const Fecha& f1, const Fecha& f2);
bool operator ==(const Fecha& f1, const Fecha& f2);
bool operator !=(const Fecha& f1, const Fecha& f2);
ostream& operator <<(ostream& os, const Fecha& f);
istream& operator >>(istream& is, Fecha& f);

#endif