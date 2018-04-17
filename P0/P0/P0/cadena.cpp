//
//  Cadena.cpp
//  Fecha
//
//  Created by Guillermo Girón García on 17/3/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "cadena.hpp"

//Constructores

Cadena::Cadena(const size_t tam, char c):
tam_{tam}, s_{}
{
    int i;

    s_ = new char[tam_ + 1];

    for(i = 0; i < tam_; ++i)
        s_[i] = c;

    s_[tam_] = '\0';
}

Cadena::Cadena(const size_t tam):
tam_{tam}, s_{}
{
    int i;

    s_ = new char[tam_ +1];

    for(i = 0; i < tam_; ++i)
        s_[i] = ' ';

    s_[tam_] = '\0';
}

Cadena::Cadena(const char* c):
tam_{strlen(c)}, s_{}
{
    s_ = new char[tam_ + 1];

    strcpy(this -> s_, c);
}

Cadena::Cadena():
tam_{0}, s_{}
{
    s_ = new char[tam_ + 1];
    s_[tam_] = '\0';
}

Cadena::Cadena(const Cadena &c):
tam_{c.tam_}, s_{}
{
    s_ = new char[this -> tam_ + 1];

    strcpy(this -> s_, c.s_);
}

Cadena::Cadena(const char* c, const size_t t):
tam_{t}, s_{}
{
    s_ = new char[tam_ + 1];
    size_t i;

    i = 0;

    for(; i < t; ++i)
        this -> s_[i] = c[i];
}

Cadena::Cadena(const Cadena &c, size_t i, const size_t t):
tam_{t}, s_{}
{
    s_ = new char[this -> tam_ + 1];
    size_t ristra;
    size_t j;

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
        //delete[] this -> s_;

        this -> tam_ = c.length();
        this -> s_ = new char[this -> tam_ + 1];
        strcpy(this -> s_, c.s_);
    }

    return *this;
}

Cadena& Cadena::operator=(const char* s)
{
    //Evitar autoasignacion

    if(strcmp(this -> s_, s))
    {
        //delete[] this -> s_;
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

    delete[] this -> s_;
    this -> s_ = new char[this -> tam_ + 1];

    strcpy(this -> s_, string.s_);

    return *this;
}

bool Cadena::operator ==(const Cadena &c)
{
    bool v;

    v = this -> tam_ == c.tam_ && strcmp(this -> s_, c.s_);

    return v;
}

bool Cadena::operator <(const Cadena &c)
{
    bool v;
    int i;

    if (this -> tam_ < c.tam_)
        i = strncmp(this -> s_, c.s_, this -> tam_);
    else
        i = strncmp(this -> s_, c.s_, c.tam_);

    if( i == 0)
        v = false;
    else if(i < 0)
        v = true;
    else
        v = false;

    return v;
}

char& Cadena::at(const size_t n)
{
    if (n > this -> tam_)
        throw std::out_of_range((const char*)"Fuera de rango");

    return s_[n];
}

const char& Cadena::at(const size_t n) const
{
    if (n > this -> tam_)
        throw std::out_of_range((const char*)"Fuera de rango");

    return s_[n];
}

char* Cadena::substr(unsigned i, size_t tam)
{
    Cadena c(tam);
    size_t j, k;

    j = i + tam - 1;


    if (i <= this -> tam_)
    {
        if( this -> tam_ - j < 1)
            throw std::out_of_range((const char*)"tam fuera de rango");

        k = 0;

        while (i <= j)
        {
            c.s_[k] = this -> s_[i];
            ++i;
            k++;
        }
    }
    else
        throw std::out_of_range((const char *)"i está fuera de rango");

    return c.s_;
}

//Destructor

Cadena::~Cadena()
{
    tam_ = 0;
    delete[] s_;
}
