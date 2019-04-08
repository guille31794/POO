#include "cadena.hpp"
#include "fecha.hpp"

#include <iostream>

int main()
{
    Fecha f;
    Fecha f1{31,7, 1994};
    Fecha f2{1, 2};

    cout << f << "\n" << f1 << "\n" << f2 << "\n" << endl;
    
    Cadena c{"Hola y "};
    Cadena s{"adios."};
    cout << c+s << endl;
    c+= "adios";
    cout << c << endl;
    cout << s << endl;

    return 0;
}