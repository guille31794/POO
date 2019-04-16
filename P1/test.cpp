#include "fecha.hpp"
#include "cadena.hpp"
#include "articulo.hpp"
#include <sstream>
#include <iostream>

int main()
{
    Articulo a{"001", "Libro", "1/1/2000", 10.35, 5};
    cout << a << endl;
    return 0;
}