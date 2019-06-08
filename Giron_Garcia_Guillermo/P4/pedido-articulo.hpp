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

class LineaPedido
{
    public:
        //Constructor
        explicit LineaPedido(double, unsigned = 1);
        //Getters
        double precio_venta() const;
        unsigned cantidad() const;
    private:
        double prize;
        unsigned quantity;
};

ostream& operator <<(ostream&, const LineaPedido&);

class OrdenaArticulos
{
    public:
        bool operator()(Articulo*, Articulo*) const;
};

class OrdenaPedidos
{
    public:
        bool operator()(Pedido*, Pedido*) const;
};

class Pedido_Articulo
{
    public:
        typedef map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
        typedef map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
        typedef map<Pedido*, ItemsPedido, OrdenaPedidos> PedidosArticulos;
        typedef map<Articulo*, Pedidos, OrdenaArticulos> ArticulosPedido;

        void pedir(Pedido&, Articulo&, double, unsigned = 1);
        void pedir(Articulo&, Pedido&, double, unsigned = 1);

        ItemsPedido detalle(Pedido&) const;
        Pedidos ventas(Articulo&) const;

        ostream& mostrarDetallePedidos(ostream&) const;
        ostream& mostrarVentasArticulos(ostream&) const;
    private:
        PedidosArticulos pedidosArticulos_;
        ArticulosPedido articulosPedido_;
};

ostream& operator <<(ostream&, const Pedido_Articulo::ItemsPedido&);
ostream& operator <<(ostream&, const Pedido_Articulo::Pedidos);

#endif