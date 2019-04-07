#ifndef Cadena_HPP_
#define Cadena_HPP_

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class Cadena
{
    public:
        //Constructors
        explicit Cadena(unsigned size = 0, char c = ' ');
        Cadena(char *string);

        //Getters
        unsigned length() const;
        operator char*() const;
        char operator [](unsigned n) const;
        char at(unsigned n) const;

        //Setters
        char& operator [](unsigned n);
        char& at(unsigned n);

        //Arithmetical operator
        void operator +=(Cadena& s);

        //Other methods
        Cadena substr(unsigned i, unsigned s) const;

        //~Cadena();
    private:
        char* string_;
        unsigned size_;
};

//Arithmetical operator
Cadena operator +(const Cadena& s1, const Cadena& s2)
{
    char* str{new char[s1.length() + s2.length() + 1]};

    strcat(str, s1);
    strcat(str, s2);

    return str;
}

//Logical operators
bool operator <(const Cadena& s1, const Cadena& s2)
{
    
}

bool operator >(const Cadena& s1, const Cadena& s2);
bool operator ==(const Cadena& s1, const Cadena& s2);
bool operator !=(const Cadena& s1, const Cadena& s2);
bool operator <=(const Cadena& s1, const Cadena& s2);
bool operator >=(const Cadena& s1, const Cadena& s2);

Cadena::Cadena(unsigned size, char c): string_{new char[size + 1]}, size_{size}
{
    memset(string_, c, size_);
}

Cadena::Cadena(char* string): string_{new char[strlen(string) + 1]}, size_{(unsigned)strlen(string)}
{
    memcpy(string_, string, size_);
}

inline unsigned Cadena::length() const
{
    return size_;
}

inline Cadena::operator char *() const
{
    return string_;
}

inline char Cadena::operator [](unsigned n) const
{
    return string_[n];
}

inline char Cadena::at(unsigned n) const
{
    if (n < 0 && n > size_)
        throw out_of_range("Position out of range.");
    
    return string_[n];
}

inline char& Cadena::operator[](unsigned n)
{
    return string_[n];
}

inline char& Cadena::at(unsigned n)
{
    if (n < 0 && n > size_)
        throw out_of_range("Position out of range.");
    
    return string_[n];
}

inline void Cadena::operator+=(Cadena& s)
{
    *this = *this + s;
}

#endif