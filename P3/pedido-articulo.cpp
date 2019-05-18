#include "pedido-articulo.hpp"

bool OrdenaPedidos::operator() (Pedido* p1, Pedido* p2) const
{
    return p1 -> numero() < p2 -> numero();
}

void Pedido_Articulo::pedir(Pedido& p, Articulo& a,
const double prize, unsigned q)
{
    PedidosArticulos::iterator i = pedidosArticulos.find(&p);
    
    if(i != pedidosArticulos.end())
        i -> second.insert(make_pair(&a, LineaPedido(prize, q)));
    else
    {
        ItemsPedido items;
        items.insert(make_pair(&a, LineaPedido(prize, q)));
        pedidosArticulos.insert(make_pair(&p, items));
    }

    ArticulosPedido::iterator it = articulosPedido.find(&a);

    if (it != articulosPedido.end())
        i -> second.insert(make_pair(&p, LineaPedido(prize, q)));
    else
    {
        Pedidos pedidos_;
        pedidos_.insert(make_pair(&p, LineaPedido(prize, q)));
        articulosPedido.insert(make_pair(&a, pedidos_));
    }  
}

void Pedido_Articulo::pedir(Articulo& a, Pedido& p,
const double prize, const unsigned q)
{
    pedir(p, a, prize, q);
}

Pedido_Articulo::ItemsPedido Pedido_Articulo::detalle(Pedido& p) const
{
    return pedidosArticulos.find(&p) -> second;
}

Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo& a) const
{
    return articulosPedido.find(&a) -> second;
}