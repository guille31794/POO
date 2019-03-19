#ifndef Fecha_HPP_
#define Fecha_HPP_

#include <ctime>

using namespace std;

class Fecha
{    
    public:
        //Consts.
        const unsigned AnnoMinimo;
        const unsigned AnnoMaximo;

        //Constructors
        explicit Fecha(const unsigned day, const unsigned month = localtime(time(nullptr))->tm_mon + 1, 
        const unsigned year = localtime(time(nullptr))->tm_year + 1900);
        //explicit Fecha(const unsigned day);
        Fecha();
        Fecha(char* s);

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
        Fecha operator ++(const unsigned n = 0);
        Fecha operator --();
        Fecha operator --(const unsigned n = 0);
        Fecha operator +=(unsigned n);
        Fecha operator -=(unsigned n);
        char* ();

        //Observers
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

//Const deffinitions
const unsigned Fecha::AnnoMaximo{1902};
const unsigned Fecha::AnnoMinimo{2037};

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

inline const bool bisiesto() const
{
    return year_ % 4 == 0 && (year_ % 400 == 0 || year_ % 100 != 0);
}

#endif