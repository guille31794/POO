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
    Cadena(const char* ); //Conversion implicita

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
     Cadena operator +(const Cadena &c) const
    {Cadena t(*this); t += c;   return t;}
    void reducir_tam()  { this -> tam_--;} //Prueba

    //Sobrecarga de operadores logicos

    friend bool operator ==(const Cadena &c1, const Cadena &c2)
    {   return (strcmp (c1.s_, c2.s_) == 0);}
    friend bool operator <(const Cadena &c1, const Cadena &c2)
    {   return (strcmp(c1.s_, c2.s_) < 0);}
    friend bool operator !=(const Cadena &c1, const Cadena &c2)
    {   return !(c1 == c2);}
    friend bool operator >(const Cadena &c1, const Cadena &c2)
    { return (strcmp(c1.s_, c2.s_) > 0); }
    friend bool operator <=(const Cadena &c1, const Cadena &c2)
    { return (strcmp(c1.s_, c2.s_) <= 0);}
    friend bool operator >=(const Cadena &c1, const Cadena &c2)
    {  return (strcmp(c1.s_, c2.s_) >= 0);}

    //Sobrecarga de indice

    inline char& operator [](const int n)    {return s_[n];}
    inline char& operator [](const int n) const    {return s_[n];}
    char& at(const int );
    const char& at(const int ) const;

    //Observador

     const char* puts() const { return s_;}
     const int length() const { return tam_;}
     char* c_str() const {  return this -> s_; }

    Cadena substr(unsigned, const int) const;


    friend std::basic_istream<char>& operator >>
    (std::basic_istream<char>&, Cadena &);

    //Semantica de movimiento

     iterator begin()   {   return this -> s_;}
     iterator end()   {   return this -> s_ + this -> tam_;}

     const_iterator begin() const   {   return this -> s_;}
     const_iterator end() const
    {   return this -> s_ + this -> tam_;}
     const_iterator cbegin() const   {   return this -> s_;}
     const_iterator cend()  const
    {   return this -> s_ + this -> tam_ ;}

     reverse_iterator rbegin() noexcept
    {   return reverse_iterator(end());}
     reverse_iterator rend() noexcept
    {   return reverse_iterator(begin());}

     const_reverse_iterator rbegin() const noexcept
    {   return const_reverse_iterator(end());}
     const_reverse_iterator rend() const noexcept
    {   return const_reverse_iterator(begin());}
     const_reverse_iterator crbegin() const noexcept
    {   return const_reverse_iterator(cend());}
     const_reverse_iterator crend() const noexcept
    {   return const_reverse_iterator(cbegin());}

    //Destructor

    ~Cadena();
};

namespace std
{
  // Estaremos dentro del espacio de nombres std
  template <> // Es una especialización de una plantilla para Cadena
  struct hash<Cadena> // Es una clase con solo un operador publico
  {
    size_t operator() (const Cadena& cad) const // el operador función
    {
      hash<string> hs;
      const char* p = cad.c_str();
      string s(p);
      size_t res = hs(s);
      return res;
    }
  };
}

//Operadores de flujo

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>&, const Cadena &);

#endif /* Cadena_hpp */
