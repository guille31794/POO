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
        
        // improved_by_guilogar
        //operator const char*() const;
        char operator [](unsigned n) const;
        char at(unsigned n) const;

        //Setters
        char& operator [](unsigned n);
        char& at(unsigned n);

        //Arithmetical operator
        Cadena& operator +=(const Cadena& s);

        //Other methods
        Cadena& substr(unsigned i, unsigned s) const;
        
        // improved_by_guilogar
        const char* c_str() const;

        //Destructor
        ~Cadena(); 
    private:
        char* string_;
        unsigned size_;
};

Cadena operator +(const Cadena& s1, const Cadena& s2);
bool operator <(const Cadena& s1, const Cadena& s2);
bool operator >(const Cadena& s1, const Cadena& s2);
bool operator ==(const Cadena& s1, const Cadena& s2);
bool operator !=(const Cadena& s1, const Cadena& s2);
bool operator <=(const Cadena& s1, const Cadena& s2);
bool operator >=(const Cadena& s1, const Cadena& s2);

#endif
