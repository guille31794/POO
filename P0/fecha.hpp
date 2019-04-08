#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <ctime>
#include <clocale>
#include <cstring>
#include <cstdio>

using namespace std;

//class Cadena;

class Fecha
{    
    public:
        //Consts.
        static const unsigned AnnoMinimo;
        static const unsigned AnnoMaximo;

        //Constructors
        explicit Fecha(const unsigned day = 0, const unsigned month = 0, const unsigned year = 0);
        Fecha(const char* s);

        //Exception class
        class Invalida
        {
            public:
                //Constructor
                Invalida(const char* s);
                //Observer
                const char* por_que() const;
            private:
                char* error;
        };

        //Operators
        Fecha operator ++();
        Fecha operator ++(const int n);
        Fecha operator --();
        Fecha operator --(const int n);
        Fecha operator +=(unsigned n);
        Fecha operator -=(unsigned n);
        operator char* () const;

        //Observers
        int dia() const;
        int mes() const;
        int anno() const;

    private:
        const bool bisiesto() const;
        unsigned day_, month_, year_;
};

//External Operators
Fecha operator +(Fecha& f, unsigned n);
Fecha operator +(unsigned n, Fecha& f);
Fecha operator -(Fecha& f, unsigned n);
Fecha operator -(unsigned n, Fecha& f);
bool operator <(const Fecha& f1, const Fecha& f2);
bool operator >(const Fecha& f1, const Fecha& f2);
bool operator <=(const Fecha& f1, const Fecha& f2);
bool operator >=(const Fecha& f1, const Fecha& f2);
bool operator ==(const Fecha& f1, const Fecha& f2);
bool operator !=(const Fecha& f1, const Fecha& f2);

#endif