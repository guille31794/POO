#ifndef CADENA_HPP_
#define CADENA_HPP_

#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <functional>

using namespace std;

class Cadena
{
    public:
        //Constructors
        explicit Cadena(const unsigned size = 0, const char c = ' ');
        Cadena(const char* str);
        Cadena(const Cadena& str);
        Cadena(Cadena&& s);

        //Operator
        Cadena& operator =(const Cadena& s) = default;
        Cadena& operator =(Cadena&& s);

        //Getters
        unsigned length() const;
        char operator [](unsigned n) const;
        const char at(unsigned n) const;

        //Setters
        char& operator [](unsigned n);
        char& at(unsigned n);
        void adjustSize();

        //Arithmetical operator
        Cadena& operator +=(const Cadena& s);

        //Other methods
        Cadena substr(const unsigned i, const int s) const;
        
        // improved_by_guilogar
        char* c_str() const;

        //Iterators
        typedef char* iterator;
        typedef const char* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;

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

// Para P2 y ss.
// Especialización de la plantilla hash<T>para definir la
// función hash a utilizar con contenedores desordenados de
// Cadena, unordered_[set|map|multiset|multimap].
namespace std 
{
    template <> struct hash<Cadena> 
    {
        size_t operator()(const Cadena& cad) const
        { 
            // conversión const char* ->string
            return hash<string>{}(cad.c_str());
        }
    };
}

#endif
