#include "pedido.hpp"

unsigned Pedido::buysQuantity{0};

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

Pedido::SinStock::SinStock(Articulo& ar): a{&ar}
{}

Articulo& Pedido::SinStock::articulo() const
{
    return *a;
}

//Constructor
LineaPedido::LineaPedido(const double p, const unsigned q):
prize{p}, quantity{q}
{}

Pedido::Pedido(Usuario_Pedido& up, Pedido_Articulo& pa,
Usuario& u, const Tarjeta& c, const Fecha& d):
card{&c}, date{d}
{
    if(!u.n_articulos())
        throw Vacio(u);

    if(c.caducidad() < d)
        throw Tarjeta::Caducada(c.caducidad());

    if(!c.activa())
        throw Tarjeta::Desactivada{};

    if(u.id() != c.titular() -> id())
        throw Impostor(u);

    for(auto it : u.compra())
        if(it.first -> stock() < it.second)
        {
            const_cast<Usuario::Articulos&> (u.compra()).clear();
            throw SinStock(*it.first);
        }
            
    Usuario::Articulos shoppingKart{u.compra()};

    for(auto kart : shoppingKart)
    {
        pa -> stock() -= kart.second;
    }
    
    buysQuantity++;
}

//Getters
double LineaPedido::precio_venta() const
{
    return prize;
}

unsigned LineaPedido::cantidad() const
{
    return quantity;
}

unsigned Pedido::numero() const
{
    return num;
}

const Tarjeta* Pedido::tarjeta() const
{
    return card;
}

Fecha Pedido::fecha() const
{
    return date;
}

double Pedido::total() const
{
    return totalPrize;
}

unsigned Pedido::n_total_pedidos()
{
    return buysQuantity;
}

//Operator
ostream& operator <<(ostream& os, const Pedido& p)
{
    os << "Núm. pedido: " << p.numero() << "\nFecha:\t\t"
    << p.fecha() << "\nPagado con:  " << p.tarjeta() <<
    "\nImporte:\t" << setiosflags(ios::fixed) << setprecision(2) <<
    p.total() << " €";

    return os;
}

ostream& operator <<(ostream& os, const LineaPedido& lp)
{
    os << setiosflags(ios::fixed) << setprecision(2) <<
    lp.precio_venta() << " €\t" << lp.cantidad();

    return os;
}