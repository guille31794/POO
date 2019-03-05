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
    int tam_;
    char* s_;

    public:

    //Constructores

    explicit Cadena(const int , const char);
    explicit Cadena(const int );
    explicit Cadena(const char* ); //Conversion explicita

    //De copia

    Cadena(const Cadena &);

    //Predeterminado

    Cadena();

    explicit Cadena(const char* , const int );

    //Con otra cadena como parametro -> Similar a substr

    explicit Cadena(const Cadena &, int , const int);

    //Sobrecarga de operadores aritmeticos

    Cadena& operator =(const Cadena &); //Destruyen la cadena
    Cadena& operator =(const char*);     //original
    Cadena& operator +=(const Cadena &);
    inline Cadena operator +(const Cadena &c) const   {Cadena t(*this); t += c;
        return t;}

    //Sobrecarga de operadores logicos

    inline bool operator ==(const Cadena &c) const  {   return (strcmp
        (this -> s_, c.s_) == 0);}
    inline bool operator <(const Cadena &c) const   {   return (strcmp
        (this -> s_, c.s_) < 0);}
    inline bool operator !=(const Cadena &c) const   {   return !(*this == c);}
    inline bool operator >(const Cadena &c) const { return (strcmp
        (this -> s_, c.s_) > 0); }
    inline bool operator <=(const Cadena &c) const { return (strcmp
        (this -> s_, c.s_) <= 0);}
    inline bool operator >=(const Cadena &c) const   {  return (strcmp
        (this -> s_, c.s_) >= 0);}

    //Sobrecarga de indice

    inline char& operator [](const int n)    {return s_[n];}
    inline char& operator [](const int n) const    {return s_[n];}
    char& at(const int );
    const char& at(const int ) const;

    //Observador

    inline const char* puts() const noexcept { return s_;}
    inline const int length() const noexcept { return tam_;}
    inline operator const char*() const {  return this -> s_; }

    Cadena substr(unsigned, const int) const;

    //Destructor

    ~Cadena();
};

#endif /* Cadena_hpp */
