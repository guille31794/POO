#ifndef CADENA_HPP_
#define CADENA_HPP_

#include <cstring>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class Cadena
{
    public:
        //Constructors
        explicit Cadena(const unsigned size = 0, const char c = ' ');
        Cadena(const char* str);

        //Getters
        unsigned length() const;
        operator char*() const;
        char operator [](unsigned n) const;
        char at(unsigned n) const;

        //Setters
        char& operator [](unsigned n);
        char& at(unsigned n);

        //Arithmetical operator
        void operator +=(const Cadena& s);

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

    strncat(str, s1, s1.length());
    strncat(str, s2, s2.length());

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

//Inline definitions

Cadena::Cadena(const unsigned size, const char c): string_{new char[size + 1]}, size_{size}
{
    memset(string_, c, size_);
}

Cadena::Cadena(const char* str): string_{new char[strlen(str) + 1]}, size_{(unsigned)strlen(str)}
{
    memcpy(string_, str, size_);
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

inline void Cadena::operator+=(const Cadena& s)
{
    *this = *this + s;
}

#endif