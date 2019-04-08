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

//Const deffinitions
const unsigned Fecha::AnnoMaximo{2037};
const unsigned Fecha::AnnoMinimo{1902};

//Inline deffinitions
inline int Fecha::dia() const
{
    return day_;
}

inline int Fecha::mes() const
{
    return month_;
}

inline int Fecha::anno() const
{
    return year_;
}

inline const char* Fecha::Invalida::por_que() const
{
    return error;
}

inline const bool Fecha::bisiesto() const
{
    return year_ % 4 == 0 && (year_ % 400 == 0 || year_ % 100 != 0);
}

#endif