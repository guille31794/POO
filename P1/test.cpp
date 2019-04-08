#include "fecha.hpp"
#include "cadena.hpp"

#include <iostream>

int main()
{
    Fecha f;
    Fecha f1{31,7, 1994};
    Fecha f2{1, 2};

    cout << f.cadena() << "\n" << f1.cadena() << "\n" 
    << f2.cadena() << "\n" << endl;
    
    f += 7;
    cout << f.cadena() << endl;

    f = f + 7;
    cout << f.cadena() << endl;
    
    Cadena c{"Hola y "};
    Cadena s{"adios."};
    cout << (c+s).c_str() << endl;
    cout << c.c_str() << endl;
    c += "adios";
    cout << c << endl;

    return 0;
}