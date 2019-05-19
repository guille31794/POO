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

ostream& operator <<(ostream& os, Pedido_Articulo::ItemsPedido& items)
{
    setlocale(LC_ALL, "es_ES");
    double total{0};

    os << "  PVP   Cantidad       Articulo\n" <<
    "==================================================================\n";

    for(auto it : items)
    {
        os << setiosflags(ios::fixed) << setprecision(2) <<
         it.second.precio_venta() << " € " << it.second.cantidad() <<
        setw(15-(it.second.cantidad()/10)) << "[" << 
        it.first -> referencia() << "] \"" << it.first -> titulo() << "\n";

        total += it.second.precio_venta();  
    }

    os <<
    "==================================================================\n"
    << "Total\t" << setiosflags(ios::fixed) << setprecision(2) <<
    total << " €";

    return os;
}

ostream& operator <<(ostream& os, Pedido_Articulo::Pedidos p)
{
    setlocale(LC_ALL, "es_ES");
    double total{0};

    os << "[Pedidos: " << p.size() << "\n" <<
    "==================================================================\n"
    << "  PVP   Cantidad"  << setw(11) << "Fecha de venta\n"
    <<
    "==================================================================\n";

    for(auto it : p)
    {
        os << setiosflags(ios::fixed) << setprecision(2) << 
        it.second.precio_venta() << " € " << it.second.cantidad() <<
        setw(10) << it.first -> fecha() << "\n";

        total += it.second.precio_venta();
    }

    os <<
    "==================================================================\n"
    << setiosflags(ios::fixed) << setprecision(2) << total << " €\t\t\t"
    << p.size();

    return os;
}

ostream& Pedido_Articulo::mostrarDetallePedidos(ostream& os) const
{
    setlocale(LC_ALL, "es_ES");
    double total{0};

    for(auto it : pedidosArticulos)
    {
        os << "Pedido num. " << it.first -> numero() << "\nCliente: "
        << it.first -> tarjeta() -> titular() << "\t\t" << 
        it.first -> fecha() << "\n";

        total += it.first -> total();
    }

    os << "TOTAL VENTAS\t\t" << setiosflags(ios::fixed) << setprecision(2)
    << total << " €";

    return os;
}