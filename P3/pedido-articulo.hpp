/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/05/2018, GPL Licensed, all rights reserved */

  #ifndef Pedido_Articulo_hpp
  #define Pedido_Articulo_hpp

  #include "pedido.hpp"
  #include "articulo.hpp"
  #include <map>
  #include <locale>
  #include <iostream>

  using namespace std;

  class Pedido;
  class Articulo;
  class LineaPedido;

  struct OrdenaArticulos
  {
    bool operator() (Articulo* a1, Articulo* a2) const
    { return a1 > a2;  }
  };

  struct OrdenaPedidos
  {
    bool operator() (Pedido*, Pedido*) const;
  };

  class Pedido_Articulo
  {
    public:
      typedef map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
      typedef map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
      typedef map<Pedido*, ItemsPedido, OrdenaPedidos> PedidosArticulos;
      typedef map<Articulo*, Pedidos, OrdenaArticulos> ArticulosPedidos;

      void pedir(Pedido&, Articulo&, double, unsigned = 1);
      void pedir(Articulo&, Pedido&, double, unsigned = 1);
      const ItemsPedido& detalle(Pedido&);
      const Pedidos ventas(Articulo&);

      std::basic_ostream<char>& mostrarDetallePedidos(std::basic_ostream<char>&);
      std::basic_ostream<char>& mostrarVentasArticulos(std::basic_ostream<char>&);

    private:
      PedidosArticulos pedidosArticulos_;
      ArticulosPedidos articulosPedidos_;
  };

    std::basic_ostream<char>& operator <<
    (std::basic_ostream<char>&, const Pedido_Articulo::ItemsPedido&);
    std::basic_ostream<char>& operator <<
    (std::basic_ostream<char>&, const Pedido_Articulo::Pedidos&);

  #endif
