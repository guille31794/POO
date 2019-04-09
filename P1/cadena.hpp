#ifndef CADENA_HPP_
#define CADENA_HPP_

#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <iterator>

using namespace std;

class Cadena
{
    public:
        //Constructors
        explicit Cadena(const unsigned size = 0, const char c = ' ');
        Cadena(const char* str);
        Cadena(Cadena&& s);

        //Operator
        Cadena& operator =(Cadena&& s);

        //Getters
        unsigned length() const;
        char operator [](unsigned n) const;
        char at(unsigned n) const;

        //Setters
        char& operator [](unsigned n);
        char& at(unsigned n);

        //Arithmetical operator
        Cadena& operator +=(const Cadena& s);

        //Other methods
        Cadena substr(const unsigned i, const unsigned s) const;
        
        // improved_by_guilogar
        char* c_str() const;

        //Iterators
        typedef char* iterator;
        typedef const char* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        iterator begin();
        iterator end();
        const_iterator cbegin();
        const_iterator cend();
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator crbegin();
        const_reverse_iterator crend();

    private:
        char* string_;
        unsigned size_;
};

//External operators
Cadena operator +(const Cadena& s1, const Cadena& s2);
bool operator <(const Cadena& s1, const Cadena& s2);
bool operator >(const Cadena& s1, const Cadena& s2);
bool operator ==(const Cadena& s1, const Cadena& s2);
bool operator !=(const Cadena& s1, const Cadena& s2);
bool operator <=(const Cadena& s1, const Cadena& s2);
bool operator >=(const Cadena& s1, const Cadena& s2);
ostream& operator <<(ostream& os, const Cadena& s);
istream& operator >>(istream& is, Cadena& s);

#endif
