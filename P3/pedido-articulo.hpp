#ifndef Pedido_Articulo_hpp
#define Pedido_Articulo_hpp

#include <locale>
#include <iomanip>
#include <map>
#include <iostream>
#include "pedido.hpp"
#include "articulo.hpp"

using namespace std;

class Pedido;

class OrdenaArticulos
{
    void operator()();
};

class OrdenaPedidos
{
    bool operator()(Pedido*, Pedido*) const;
};

class Pedido_Articulo
{
    public:
        typedef map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
        typedef map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
        typedef map<Pedido*, ItemsPedido, OrdenaPedidos> PedidosArticulos;
        typedef map<Articulo*, Pedidos, OrdenaArticulos> ArticulosPedido;

        void pedir(Pedido&, Articulo&, const double, unsigned = 1);
        void pedir(Articulo&, Pedido&, const double, unsigned = 1);

        ItemsPedido detalle(Pedido&) const;
        Pedidos ventas(Articulo&) const;

        ostream& mostrarDetallePedidos(ostream&) const;
        ostream& mostrarVentasArticulos(ostream&) const;
    private:
        PedidosArticulos pedidosArticulos;
        ArticulosPedido articulosPedido;
};

ostream& operator <<(ostream&, const Pedido_Articulo::ItemsPedido&);
ostream& operator <<(ostream&, const Pedido_Articulo::Pedidos);

#endif