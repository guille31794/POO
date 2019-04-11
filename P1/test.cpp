#include "fecha.hpp"
#include "cadena.hpp"

#include <iostream>

int main()
{
    Fecha f;
    Fecha f1{31,7, 1994};
    Fecha f2{1, 2};
    Fecha f3{f};

    cout << f << "\n" << f1 << "\n" << f2 << "\n" << f3 << endl;
    
    f += 7;
    cout << f << endl;

    f = f + 7;
    cout << f << endl;
    
    Cadena c{"Hola y "};
    Cadena s{"adios."};
    cout << c + s << endl;
    cout << c << endl;
    c += "adios";
    cout << c << endl;
    Cadena st;
    cin >> st;
    cout << st << endl;

    return 0;
}