/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/05/2018, GPL Licensed, all rights reserved */

  #ifndef Pedido_Articulo_hpp
  #define Pedido_Articulo_hpp

  #include "pedido.hpp"
  #include "articulo.hpp"
  #include <map>

  using namespace std;

  class Pedido;
  class Articulo;

  class Pedido_Articulo
  {
    public:
      typedef map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
      typedef map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;

      void pedir(Pedido&, Articulo&, double, unsigned = 1);
      void pedir(Articulo&, Pedido&, double, unsigned = 1);
      Articulo detalle(const ItemsPedido&) const;
      Pedidos ventas();

      void mostrarDetallePedidos();
      void mostrarVentasArticulos();

    private:
      map<Pedido*, ItemsPedido, OrdenaPedidos> AD;
      map<Articulo*, Pedidos, OrdenaArticulos> AI;
  }

  basic_ostream<char>& <<(basic_ostream<char>&, Pedido_Articulo::ItemsPedido&);
  basic_ostream<char>& <<(basic_ostream<char>&, Pedido_Articulo::Pedidos&);

  #endif
