#ifndef CADENA_CPP_
#define CADENA_CPP_

#include "cadena.hpp"

Cadena Cadena::substr(unsigned i, unsigned s) const
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

#endif
