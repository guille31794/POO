#include "pedido.hpp"

//Exceptio Stuff
Pedido::Vacio::Vacio(const Usuario& u): uP{&u} 
{}

const Usuario& Pedido::Vacio::usuario() const
{
    return *uP;
}

Pedido::Impostor::Impostor(const Usuario& u): uP{&u}
{}

const Usuario& Pedido::Impostor::usuario() const
{
    return *uP;
}

Pedido::SinStock::SinStock(const Articulo& ar): a{&ar}
{}

const Articulo& Pedido::SinStock::articulo() const
{
    return *a;
}

//Constructor
Pedido::Pedido(const Usuario_Pedido& up, const Pedido_Articulo& pa,
const Usuario& u, const Tarjeta& c, const Fecha& d):
card{&c}, date{d}
{
    
}

//Getters
unsigned Pedido::numero() const
{
    return num;
}

const Tarjeta& Pedido::tarjeta() const
{
    return *card;
}

Fecha Pedido::fecha() const
{
    return date;
}

double Pedido::total() const
{
    return totalPrize;
}

unsigned Pedido::n_total_pedidos() const
{
    return buysQuantity;
}

//Operator
ostream& operator <<(ostream& os, Pedido p)
{
    os << "Núm. pedido: " << p.numero() << "\nFecha:\t\t"
    << p.fecha() << "\nPagado con:  " << p.tarjeta() <<
    "\nImporte:\t" << setiosflags() << setprecision(2) <<
    p.total() << " €";

    return os;
}