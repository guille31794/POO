#include "pedido-articulo.hpp"

bool OrdenaPedidos::operator() (Pedido* p1, Pedido* p2) const
{
    return p1 -> numero() < p2 -> numero();
}

bool OrdenaArticulos::operator() (Articulo* a1, Articulo* a2) const
{
    return a1 -> referencia() < a2 -> referencia();
}

LineaPedido::LineaPedido(double p, unsigned q):
prize{p}, quantity{q}
{}

double LineaPedido::precio_venta() const
{
    return prize;
}

unsigned LineaPedido::cantidad() const
{
    return quantity;
}


ostream& operator <<(ostream& os, const LineaPedido& lp)
{
    os << setiosflags(ios::fixed) << setprecision(2) <<
    lp.precio_venta() << " €\t" << lp.cantidad();

    return os;
}

void Pedido_Articulo::pedir(Pedido& p, Articulo& a, double prize, unsigned q)
{
    PedidosArticulos::iterator i = pedidosArticulos_.find(&p);
    
    if(i != pedidosArticulos_.end())
        i -> second.insert(make_pair(&a, LineaPedido(prize, q)));
    else
    {
        ItemsPedido items;
        items.insert(make_pair(&a, LineaPedido(prize, q)));
        pedidosArticulos_.insert(pair<Pedido*, Pedido_Articulo::ItemsPedido>(&p, items));
    }

    ArticulosPedido::iterator it = articulosPedido_.find(&a);

    if (it != articulosPedido_.end())
        it -> second.insert(pair<Pedido*, LineaPedido>(&p, LineaPedido{prize, q}));
    else
    {
        Pedidos pedidos_;
        pedidos_.insert(make_pair(&p, LineaPedido(prize, q)));
        articulosPedido_.insert(make_pair(&a, pedidos_));
    }  
}

void Pedido_Articulo::pedir(Articulo& a, Pedido& p,
double prize, unsigned q)
{
    pedir(p, a, prize, q);
}

Pedido_Articulo::ItemsPedido Pedido_Articulo::detalle(Pedido& p) const
{
    return pedidosArticulos_.find(&p) -> second;
}

Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo& a) const
{
    
    auto it = articulosPedido_.find(&a);
    if(it != articulosPedido_.end())
        return it -> second;
    else
        return Pedidos{};
}

ostream& operator <<(ostream& os, const Pedido_Articulo::ItemsPedido& items)
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
    total << " €\n";

    return os;
}

ostream& operator <<(ostream& os, Pedido_Articulo::Pedidos p)
{
    setlocale(LC_ALL, "es_ES");
    double total{0};

    os << "[Pedidos: " << p.size() << "]\n" <<
    "==================================================================\n"
    << "  PVP   Cantidad\t\t"  << "Fecha de venta\n"
    <<
    "==================================================================\n";

    for(auto it : p)
    {
        os << setiosflags(ios::fixed) << setprecision(2) << 
        it.second.precio_venta() << " € " << it.second.cantidad() <<
        "\t\t" << it.first -> fecha() << "\n";

        total += it.second.precio_venta() * it.second.cantidad();
    }

    os <<
    "==================================================================\n"
    << setiosflags(ios::fixed) << setprecision(2) << total << " €\t\t\t"
    << p.size() << '\n';

    return os;
}

ostream& Pedido_Articulo::mostrarDetallePedidos(ostream& os) const
{
    setlocale(LC_ALL, "es_ES");
    double total{0};

    for(auto it : pedidosArticulos_)
    {
        os << "Pedido num. " << it.first -> numero() << "\nCliente: "
        << it.first -> tarjeta() -> titular() -> nombre() << "\t\t" << 
        it.first -> fecha() << "\n" << it.second << "\n";

        total += it.first -> total();
    }

    os << "TOTAL VENTAS\t\t" << setiosflags(ios::fixed) << setprecision(2)
    << total << " €\n";

    return os;
}

ostream& Pedido_Articulo::mostrarVentasArticulos(ostream& os) const
{
    setlocale(LC_ALL, "es_ES");

    for(auto it : articulosPedido_)
        os << "Ventas de " << it.first->titulo() << "\n" <<
        it.second << "\n\n";

    return os;
}