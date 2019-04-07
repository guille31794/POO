#include <iostream>
#include "cadena.hpp"

int main()
{
    /*Fecha f;
    Fecha f1{1,3, 1994};
    Fecha f2{1, 2};

    cout << f << "/n" << f1 << "/n" << f2 << "/n" << endl;*/
    Cadena c{"Hola y "};
    Cadena s{"adios."};
    cout << c+s << endl;
    c+=s;
    cout << c << endl;
    cout << s << endl;
    return 0;
}