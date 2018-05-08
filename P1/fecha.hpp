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

    unsigned day, month, year;

    //Comprobador de excepciones

    void bisiesto();
    void compruebaFecha();
    void CompruebadaysDelmonth();

public:

    //Constructores

    explicit Fecha(const unsigned, const unsigned, const unsigned);
    explicit Fecha(const unsigned, const unsigned);
    explicit Fecha(const unsigned);
    explicit Fecha();

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

         const char* por_que() const { return string; }
    };

    //Observadoras-Consultoras

     const int dia() const { return this -> day; }
     const int mes() const { return this -> month; }
     const int anno() const { return this -> year; }

    //Sobrecarga de operadores aritmeticos

    Fecha& operator +=(const int);
     Fecha& operator -=(int n)   { n *= (-1); return *this += n; }

    //Predecremento/Preincremento

     Fecha& operator ++()  {  return *this += 1;   }
     Fecha& operator --()  {  return *this += -1;  }

    //Postdecremento/Postincremento

     Fecha operator ++(const int n)  { Fecha f(*this); *this += 1;
        return f;}
     Fecha operator --(const int n)   {   Fecha f(*this); *this += -1;
        return f;}
     Fecha& operator +(const int n) const {  Fecha f(*this); return f += n;  }
     Fecha& operator -(int n) const   {  Fecha f(*this); n *= (-1);
        return f += n; }

    //Constantes de construcción publicas

    static const unsigned AnnoMinimo {1902};
    static const unsigned AnnoMaximo {2037};

    //Operador de Conversion

    explicit operator const char*() const;

    //Operador de flujos de salida

    friend ostream& operator << (ostream& , const Fecha &);
    friend istream& operator >> (istream&, Fecha &);

    char* const cadena() const;
};

//Sobrecarga de operadores de comparacion

bool operator ==(const Fecha &, const Fecha &);
bool operator <(const Fecha &, const Fecha &);
inline bool operator !=(const Fecha &f1, const Fecha &f2)
{ return !(f1 == f2);   }
inline bool operator >(const Fecha &f1, const Fecha &f2)
{ return f2 < f1;   }
inline bool operator <=(const Fecha &f1, const Fecha &f2)
{ return  !(f1 > f2); }
inline bool operator >=(const Fecha &f1, const Fecha &f2)
{ return !(f1 < f2);   }

#endif
