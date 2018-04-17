//
//  Cadena.hpp
//  Fecha
//
//  Created by Guillermo Girón García on 17/3/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#ifndef Cadena_hpp
#define Cadena_hpp

#include <cstdio>
#include <cstring>
#include <stdexcept>

class Cadena
{
    char* s_;
    size_t tam_;

    public:

    //Constructores

    Cadena(const size_t , const char);
    Cadena(const size_t );
    Cadena(const char* ); //Conversion explicita

    //De copia

    Cadena(const Cadena &);

    //Predeterminado

    Cadena();

    Cadena(const char* , const size_t );

    //Con otra cadena como parametro -> Similar a substr

    Cadena(const Cadena &, size_t , const size_t);

    //Sobrecarga de operadores aritmeticos

    Cadena& operator =(const Cadena &); //Destruyen la cadena
    Cadena& operator =(const char*);     //original
    Cadena& operator +=(const Cadena &);
    inline Cadena operator +(const Cadena &c)    {Cadena t(*this); t += c;  return t;}

    //Sobrecarga de operadores logicos

    bool operator ==(const Cadena &);
    bool operator <(const Cadena &);
    inline bool operator !=(const Cadena &c)    {   return !(*this == c);}
    inline bool operator >(Cadena &c) { return c < *this; }
    inline bool operator <=(Cadena &c) { return !(c < *this);}
    inline bool operator >=(const Cadena &c)    {return !(*this < c);}

    //Sobrecarga de indice

    inline char& operator [](const size_t n)    {return s_[n];}
    inline char& operator [](const size_t n) const    {return s_[n];}
    char& at(const size_t );
    const char& at(const size_t ) const;

    //Observador

    inline const char* puts() const { return s_;}
    inline const size_t length() const { return tam_;}
    inline operator const char*() const {  return this -> s_; }

    char* substr(unsigned, const size_t);

    //Destructor

    ~Cadena();
};

#endif /* Cadena_hpp */
