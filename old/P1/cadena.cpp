//
//  Cadena.cpp
//  Fecha
//
//  Created by Guillermo Girón García on 17/3/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "cadena.hpp"

const int Cadena::tamMax = 32;

//Constructores

Cadena::Cadena(const unsigned tam, char c):
tam_{tam}, s_{new char[tam+1]}
{
    if (tam < 0)
        throw std::out_of_range((const char*)"Fuera de rango");

    for(unsigned i = 0; i < tam_; ++i)
        s_[i] = c;

    s_[tam_] = '\0';
}

Cadena::Cadena(const unsigned tam):
tam_{tam}, s_{new char[tam+1]}
{
    if (tam < 0)
        throw std::out_of_range((const char*)"Fuera de rango");

    int i;

    for(i = 0; i < tam_; ++i)
        s_[i] = ' ';

    s_[tam_] = '\0';
}

Cadena::Cadena(const char* c):
tam_{(unsigned)strlen(c)}, s_{new char[(strlen(c)+1)]}
{
    strcpy(this -> s_, c);
}

Cadena::Cadena():
tam_{0}, s_{new char[1]}
{
  s_[tam_] = '\0';
}

Cadena::Cadena(const Cadena& c): tam_{c.tam_}, s_{new char[c.tam_ + 1]}
{
    strcpy(s_, c.s_);
}

Cadena::Cadena(Cadena &&c):
tam_{c.tam_}, s_{c.s_}
{
  c.s_ = nullptr;
  c.tam_ = 0;
}

Cadena::Cadena(const char* c, const unsigned t):
tam_{t}, s_{new char[t+1]}
{
    int i;

    i = 0;

    for(; i < t; ++i)
        this -> s_[i] = c[i];
}

Cadena::Cadena(const Cadena &c, unsigned i, const unsigned t):
tam_{t}, s_{new char[t+1]}
{
    int ristra;
    int j;

    ristra = i + t - 1;
    j = 0;
    i--;

    for(;i <= ristra; ++i)
    {
        this -> s_[j] = c.s_[i];
        ++j;
    }
}

//Sobrecarga de operadores

Cadena& Cadena::operator=(const Cadena &c)
{
    //Evitar autoasignacion

    if (*this != c)
    {
        this -> tam_ = c.length();
        delete[] this -> s_;
        this -> s_ = new char[this -> tam_ + 1];
        strcpy(this -> s_, c.s_);
    }

    return *this;
}

Cadena& Cadena::operator=(Cadena &&c)
{
  //Evitar autoasignacion

  if (*this != c)
  {
      this -> tam_ = c.length();
      this -> s_ = c.s_;

      c.s_ = nullptr;
      c.tam_ = 0;
  }

  return *this;
}

Cadena& Cadena::operator=(const char* s)
{
    //Evitar autoasignacion

    if(strcmp(this -> s_, s))
    {
        this -> tam_ = strlen(s);
        delete[] this -> s_;
        this -> s_ = new char[this -> tam_ + 1];
        strcpy(this -> s_, s);
    }

    return *this;
}

Cadena& Cadena::operator += (const Cadena &c)
{
    this -> tam_ += c.tam_;
    Cadena string(this -> tam_);

    strcpy(string.s_, this -> s_);
    strcat(string.s_, c.s_);

    this -> s_ = new char[this -> tam_ + 1];

    strcpy(this -> s_, string.s_);

    return *this;
}

char& Cadena::at(const int n)
{
    if (n >= this -> tam_ )
        throw std::out_of_range((const char*)"Fuera de rango");

    return s_[n];
}

const char& Cadena::at(const int n) const
{
    if (n >= this -> tam_)
        throw std::out_of_range((const char*)"Fuera de rango");

    return s_[n];
}

Cadena Cadena::substr(unsigned i, const int tam) const
{
    if (tam < 0)
        throw std::out_of_range((const char*)"Fuera de rango");

    if(i < 0)
    throw std::out_of_range((const char*)"Fuera de rango");

    if(tam + i > this -> tam_)
        throw std::out_of_range((const char*)"Fuera de rango");

    Cadena c(tam);
    int j, k;

    j = i + tam - 1;


    if (i <= this -> tam_)
    {
        if( this -> tam_ - j < 1)
            throw std::out_of_range((const char*)"tam fuera de rango");

        k = 0;
        while (i <= j && j >= 0)
        {
            c.s_[k] = this -> s_[i];
            ++i;
            k++;
        }
    }
    else
        throw std::out_of_range((const char *)"i está fuera de rango");

    return c;
}

//Operadores de flujo

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>& os, const Cadena &c)
{
  os << c.c_str();
  return os;
}

std::basic_istream<char>& operator >>
(std::basic_istream<char>& is, Cadena &c)
{
  char* string = new char[c.tamMax+1];
  string[0] = '\0';

  is.width(c.tamMax + 1);

  is >> string;
  delete[] c.s_;
  c.s_ = new char[c.tamMax+1];

  strcpy(c.s_, string);

  return is;
}

//Destructor

Cadena::~Cadena()
{
    if(tam_ != 0) {
        tam_ = 0;
        delete[] s_;
        s_ = nullptr;
    }
}
