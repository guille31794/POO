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
#include <cstdlib>
#include <iostream>
#include <clocale>
#include <cctype>
#include <iterator>
#include <utility>

using namespace std;

class Cadena
{
    int tam_;
    char* s_;

    public:

    static const int tamMax {32};

    //Iteradores

    typedef char* iterator;
    typedef const char* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    //Constructores

    Cadena(const int , const char);
    Cadena(const int );
    Cadena(const char* ); //Conversion explicita

    //De copia

    Cadena(const Cadena &);
    Cadena(Cadena &&);

    //Predeterminado

    Cadena();

    Cadena(const char* , const int );

    //Con otra cadena como parametro -> Similar a substr

    Cadena(const Cadena &, int , const int);

    //Sobrecarga de operadores aritmeticos

    Cadena& operator =(const Cadena &); //Destruyen la cadena
    Cadena& operator =(const char*);     //original
    Cadena& operator =(Cadena &&);
    Cadena& operator +=(const Cadena &);
    inline Cadena operator +(const Cadena &c) const
    {Cadena t(*this); t += c;   return t;}

    //Sobrecarga de operadores logicos

    friend inline bool operator ==(const Cadena &c1, const Cadena &c2)
    {   return (strcmp (c1.s_, c2.s_) == 0);}
    friend inline bool operator <(const Cadena &c1, const Cadena &c2)
    {   return (strcmp(c1.s_, c2.s_) < 0);}
    friend inline bool operator !=(const Cadena &c1, const Cadena &c2)
    {   return !(c1 == c2);}
    friend inline bool operator >(const Cadena &c1, const Cadena &c2)
    { return (strcmp(c1.s_, c2.s_) > 0); }
    friend inline bool operator <=(const Cadena &c1, const Cadena &c2)
    { return (strcmp(c1.s_, c2.s_) <= 0);}
    friend inline bool operator >=(const Cadena &c1, const Cadena &c2)
    {  return (strcmp(c1.s_, c2.s_) >= 0);}

    //Sobrecarga de indice

    inline char& operator [](const int n)    {return s_[n];}
    inline char& operator [](const int n) const    {return s_[n];}
    char& at(const int );
    const char& at(const int ) const;

    //Observador

    inline const char* puts() const { return s_;}
    inline const int length() const { return tam_;}
    inline char* c_str() const {  return this -> s_; }

    Cadena substr(unsigned, const int) const;

    //Operadores de flujo

    friend std::basic_ostream<char>& operator <<
    (std::basic_ostream<char>&, const Cadena &);
    friend std::basic_istream<char>& operator >>
    (std::basic_istream<char>&, Cadena &);

    //Semantica de movimiento

    inline iterator begin()   {   return this -> s_;}
    inline iterator end()   {   return this -> s_ + this -> tam_;}

    inline const_iterator begin() const   {   return this -> s_;}
    inline const_iterator end() const
    {   return this -> s_ + this -> tam_;}
    inline const_iterator cbegin() const   {   return this -> s_;}
    inline const_iterator cend()  const
    {   return this -> s_ + this -> tam_ ;}

    inline reverse_iterator rbegin() noexcept
    {   return reverse_iterator(end());}
    inline reverse_iterator rend() noexcept
    {   return reverse_iterator(begin());}

    inline const_reverse_iterator rbegin() const noexcept
    {   return const_reverse_iterator(end());}
    inline const_reverse_iterator rend() const noexcept
    {   return const_reverse_iterator(begin());}
    inline const_reverse_iterator crbegin() const noexcept
    {   return const_reverse_iterator(cend());}
    inline const_reverse_iterator crend() const noexcept
    {   return const_reverse_iterator(cbegin());}

    //Destructor

    ~Cadena();
};

#endif /* Cadena_hpp */
