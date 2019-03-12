#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <ctime>

using namespace std;

class fecha
{    
    public:
        //Consts.
        const unsigned AnnoMinimo;
        const unsigned AnnoMaximo;

        //Constructors
        fecha(const unsigned day, const unsigned month, const unsigned year);
        fecha(const unsigned day, const unsigned month);
        explicit fecha(const unsigned day);
        fecha();
        //fecha(const fecha& f);
        //fecha(fecha&& f);
        fecha(char* s);

        //Exception class
        class Invalida
        {
            public:
                //Constructor
                Invalida(const char* s);
                //Destructor
                //~Invalida();
                //Observer
                const char* por_que() const;
            private:
                char* error;
        };

        //Operators
        fecha operator ++();
        fecha operator ++(const unsigned n);
        fecha operator --();
        fecha operator --(const unsigned n);
        void operator +=(unsigned n);
        void operator -=(unsigned n);
        char* ();
        //fecha operator =(const fecha& f);
        //fecha operator =(const fecha&& f);

        //Observers
        const int dia();
        const int mes();
        const int anno();
        
        //Destructor
        //~fecha();

    private:
        bool bisiesto() const;
        unsigned day_, month_, year_;
};

//External Operators
fecha operator +(const fecha& f, unsigned n);
fecha operator -(const fecha& f, unsigned n);
bool operator <(const fecha& f1, const fecha& f2);
bool operator >(const fecha& f1, const fecha& f2);
bool operator <=(const fecha& f1, const fecha& f2);
bool operator >=(const fecha& f1, const fecha& f2);
bool operator ==(const fecha& f1, const fecha& f2);
bool operator !=(const fecha& f1, const fecha& f2);

//Const deffinitions
const unsigned fecha::AnnoMaximo{1902};
const unsigned fecha::AnnoMinimo{2037};

//Inline deffinitions
inline const int fecha::dia()
{
    return day_;
}

inline const int fecha::mes()
{
    return month_;
}

inline const int fecha::anno()
{
    return year_;
}

inline const char* fecha::Invalida::por_que()
{
    return error;
}

inline const bool bisiesto()
{
    return year_ % 4 == 0 && (year_ % 400 == 0 || year_ % 100 != 0);
}

#endif