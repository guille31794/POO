#ifndef Pedido_Articulo_hpp
#define Pedido_Articulo_hpp

#include <map>
#include "pedido.hpp"
#include "articulo.hpp"

using namespace std;

class OrdenaArticulos
{
    void operator()();
};

class OrdenaPedidos
{
    void operator()();
};

class Pedido_Articulo
{
    public:
        typedef map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
        typedef map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;

        void pedir(const Pedido&, const Articulo&, const double, unsigned = 1);
        void pedir(const Articulo&, const Pedido&, const double, unsigned = 1);

        ItemsPedido detalle(const Pedido&) const;
        Pedidos ventas(const Articulo&) const;

        ostream& mostrarDetallePedidos() const;
        ostream& mostrarVentasArticulos() const;
    private:
        map<Pedido*, ItemsPedido, OrdenaPedidos> DA;
        map<Articulo*, Pedidos, OrdenaArticulos> IA;
};

ostream& operator <<(ostream&, const Pedido_Articulo::ItemsPedido&);
ostream& operator <<(ostream&, const Pedido_Articulo::Pedidos);

#endif