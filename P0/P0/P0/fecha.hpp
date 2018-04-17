#ifndef Fecha_hpp
#define Fecha_hpp

#include <iostream>
#include <ctime>
#include <cstdio>
#include <clocale>


using namespace std;

class Fecha
{
private:

    int day, month, year;

    //Comprobador de excepciones

    void bisiesto();
    void compruebaFecha();
    void CompruebadaysDelmonth();

public:

    //Constructores

    Fecha(const int, const int, const int);
    Fecha(const int, const int);
    Fecha(const int);
    Fecha();

    //A partir de una cadena

    Fecha(const char * );

    //Excepciones

    class Invalida
    {
        const char *string;

        public:

        //Constructor de excepciones

        Invalida(const char *);

        //Observador de excepciones

        inline const char* por_que() const { return string; }
    };

    //Observadoras-Consultoras

    inline const int dia() const { return year; }
    inline const int mes() const { return month; }
    inline const int anno() const { return day; }

    //Sobrecarga de operadores aritmeticos

    Fecha operator +=(const int);
    inline Fecha operator -=(int n)   { n *= (-1); return *this += n; }
    inline Fecha operator ++()  {  return *this += 1;   }
    inline Fecha operator --()  {  return *this += -1;  }
    inline Fecha operator ++(const int n)  { Fecha f(*this); *this += 1;
        return f;}
    inline Fecha operator --(const int n)   {   Fecha f(*this); *this += -1;
        return f;}
    inline Fecha operator +(const int n)  {  Fecha f(*this); return f += n;  }
    inline Fecha operator -(int n)    {  Fecha f(*this); n *= (-1);
        return f += n; }

    //Constantes de construcción publicas

    static const int AnnoMinimo {1902};
    static const int AnnoMaximo {2037};

    //Sobrecarga de operadores de comparacion

    bool operator ==(const Fecha &f) const;
    bool operator <(const Fecha &f) const;
    inline bool operator !=(const Fecha &f) const  { return !(*this == f);   }
    inline bool operator >(const Fecha &f)  const  { return f < *this;   }
    inline bool operator <=(const Fecha &f) const  { return  !(f < *this); }
    inline bool operator >=(const Fecha &f) const  { return !(*this < f);   }
    operator const char*() const;

    //Operador de flujos de salida

    //Corregir

    //friend ostream& operator << (ostream& , const Fecha &);
};


#endif
