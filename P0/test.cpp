#include <iostream>
#include "fecha.hpp"

int main()
{
    Fecha f;
    Fecha f1{1,3, 1994};
    Fecha f2{1, 2};

    cout << f << "/n" << f1 << "/n" << f2 << "/n" << endl;
    return 0;
}