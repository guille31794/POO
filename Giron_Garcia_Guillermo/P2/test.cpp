#include "../P1/fecha.hpp"
#include "../P1/cadena.hpp"
#include "tarjeta.hpp"
#include "usuario.hpp"

int main()
{   
    Usuario u{"123", "Guille", "Giron", "calle", "558712ggg"};
    Usuario* pU = &u;
    Tarjeta c{TIPO::AmericanExpress, Numero{12345678901234}, *pU, Fecha{}};
    cout << c.tipo() << '\n' << c.numero() << '\n' <<
    c.caducidad() << '\n' << c.titular_facial().c_str() << endl;
}