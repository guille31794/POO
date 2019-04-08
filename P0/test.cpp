#include "fecha.hpp"
#include "cadena.hpp"

#include <iostream>

int main()
{
    Fecha f;
    Fecha f1{31,7, 1994};
    Fecha f2{1, 2};

    cout << f << "\n" << f1 << "\n" << f2 << "\n" << endl;
    
    f += 7;
    cout << f << endl;

    f = f + 7;
    cout << f << endl;
    
    Cadena c{"Hola y "};
    Cadena s{"adios."};
    cout << (c+s).c_str() << endl;
    c+= "adios";
    cout << c.c_str() << endl;
    cout << s.c_str() << endl;

    return 0;
}