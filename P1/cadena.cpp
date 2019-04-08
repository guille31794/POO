#include "cadena.hpp"

//Arithmetical operator
Cadena operator +(const Cadena& s1, const Cadena& s2)
{
    Cadena str{s1.length() + s2.length()};
    strcpy(str, s1);
    strcat(str, s2);

    return str;
}

//Logical operators
bool operator <(const Cadena& s1, const Cadena& s2)
{
    return strcmp(s1, s2) < 0;
}

bool operator >(const Cadena& s1, const Cadena& s2)
{
    return s2 < s1;
}

bool operator ==(const Cadena& s1, const Cadena& s2)
{
    return strcmp(s1, s2) == 0;
}

bool operator !=(const Cadena& s1, const Cadena& s2)
{
    return !(s1 == s2);
}

bool operator <=(const Cadena& s1, const Cadena& s2)
{
    return s1 < s2 || s1 == s2;
}

bool operator >=(const Cadena& s1, const Cadena& s2)
{
    return s1 > s2 || s1 == s2;
}

// definitions

Cadena::Cadena(const unsigned size, const char c): string_{new char[size + 1]}, size_{size}
{
    memset(string_, c, size_);
}

Cadena::Cadena(const char* str): string_{new char[strlen(str) + 1]}, size_{(unsigned)strlen(str)}
{
    strcpy(string_, str);
}

unsigned Cadena::length() const
{
    return size_;
}

Cadena::operator char *() const
{
    return string_;
}

// improved_by_guilogar
/*Cadena::operator const char *() const
{
    return string_;
}*/

char Cadena::operator [](unsigned n) const
{
    return string_[n];
}

char Cadena::at(unsigned n) const
{
    if (n < 0 && n > size_)
        throw out_of_range("Position out of range.");
    
    return string_[n];
}

char& Cadena::operator[](unsigned n)
{
    return string_[n];
}

char& Cadena::at(unsigned n)
{
    if (n < 0 && n > size_)
        throw out_of_range("Position out of range.");
    
    return string_[n];
}

Cadena& Cadena::operator+=(const Cadena& s)
{
    this -> size_ += s.size_;
    char* aux = new char[size_+1];
    strcpy(aux, string_);
    string_ = new char[size_ + 1];
    strcpy(string_, aux);
    strcat(string_, s.string_);
    delete[] aux;

    return *this;
}

const char* Cadena::c_str() const 
{
     return string_; 
}

Cadena& Cadena::substr(unsigned i, unsigned s) const
{
    if(i < 0 || i > size_ || i+s > size_)
        throw out_of_range("Index out of range.");

    char* str = new char[i+s+1];
    unsigned n{0};

    // improved_by_guilogar
    for(int j = i; j < s; ++j)
    {  
        str[n] = string_[j];
        ++n;
    }

    Cadena st{str};
    delete[] str;

    return st;
}

Cadena::~Cadena()
{
    delete[] string_;
    size_ = 0;
    string_ = nullptr;
}