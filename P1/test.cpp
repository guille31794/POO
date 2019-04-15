#include "fecha.hpp"
#include "cadena.hpp"

#include <iostream>

int main()
{
    Fecha f{30, 7, 1994};
    Fecha f1{31,7, 1994};
    Fecha f2{1, 2};
    Fecha f3{f};

    cout << boolalpha << (f < f1) << endl;
    cout << boolalpha << (f > f1) << endl;
    cout << boolalpha << (f <= f1) << endl;
    cout << boolalpha << (f >= f1) << endl;
    cout << f << "\n" << f1 << "\n" << f2 << "\n" << f3 << endl;
    
    f += 7;
    cout << f << endl;

    f = f + 7;
    cout << f << endl;
    cout << (f -= 7) << endl;

    //f = f - 7;
    cout << f - 7 << endl;
    
    Cadena c{"Hola y "};
    Cadena s{"adios."};
    cout << c + s << endl;
    cout << c << endl;
    c += "adios";
    cout << c << endl;
    Cadena st;
    cin >> st;
    cout << st << endl;
    Cadena c1{20, '['};
    Cadena c2{" !Bravo "};
    cout << c1 + c2 << endl;
    Cadena n1{"novum"};
    Cadena n2{"Nihil novum sub Solem"};
    n1 = n2.substr(6,5);
    cout << n1 << " " << n1.length() << endl;
    const Cadena a("0123456789");
    cout << a.substr(9, -1) << endl;

    return 0;
}