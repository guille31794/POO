#include "cadena.hpp"

// Constructors

Cadena::Cadena(const unsigned size, const char c): string_{new char[size + 1]}, size_{size}
{
    memset(string_, c, size_);
}

Cadena::Cadena(const char* str): string_{new char[strlen(str) + 1]}, size_{(unsigned)strlen(str)}
{
    strcpy(string_, str);
}

Cadena::Cadena(Cadena&& s): string_{s.string_}, size_{s.size_}
{
    s.~Cadena();
}

//Operator
Cadena& Cadena::operator=(Cadena&& s)
{
    if(*this != s)
    {
        size_ = s.size_;
        string_ = new char[size_ + 1];
        strcpy(string_, s.string_);
        s.~Cadena();
    }

    return *this;
}

//Getters

unsigned Cadena::length() const
{
    return size_;
}

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

char* Cadena::c_str() const 
{
     return string_; 
}

//Setters

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

Cadena Cadena::substr(const unsigned i, const unsigned s) const
{
    if(i < 0 || i > size_ || i+s > size_)
        throw out_of_range("Index out of range.");

    Cadena str{i+s};
    unsigned n{0};

    for(int j = i; j < i + s; ++j)
    {  
        str[n] = string_[j];
        ++n;
    }

    return str;
}

// Operators

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

//Arithmetical operator
Cadena operator +(const Cadena& s1, const Cadena& s2)
{
    char* str{new char[s1.length() + s2.length() + 1]};
    strcpy(str, s1.c_str());
    strcat(str, s2.c_str());
    Cadena st{str};
    delete[] str;
    return st;
}

//Logical operators
bool operator <(const Cadena& s1, const Cadena& s2)
{
    return strcmp(s1.c_str(), s2.c_str()) < 0;
}

bool operator >(const Cadena& s1, const Cadena& s2)
{
    return s2 < s1;
}

bool operator ==(const Cadena& s1, const Cadena& s2)
{
    return strcmp(s1.c_str(), s2.c_str()) == 0;
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

ostream& operator <<(ostream& os, const Cadena& s)
{
    return os << s.c_str();
}

istream& operator >>(istream& is, Cadena& s)
{
    char* string = new char[32];
    string[0] = '\0';

    is.width(32);
    is >> string;
    
    s = move(Cadena{string});

    delete[] string;

    return is;
}

//Iterators
Cadena::iterator Cadena::begin()
{
    return string_;
}



//Destructor

/*Cadena::~Cadena()
{
    delete[] string_;
    size_ = 0;
    string_ = nullptr;
}*/