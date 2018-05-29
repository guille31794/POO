/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/05/2018, GPL Licensed, all rights reserved */

  #ifndef Pedido_hpp
  #define Pedido_hpp

  #include <iostream>
  #include <locale>

  #include "tarjeta.hpp"
  #include "cadena.hpp"
  #include "fecha.hpp"
  #include "usuario.hpp"
  #include "articulo.hpp"
  #include "pedido-articulo.hpp"
  #include "usuario-pedido.hpp"

  using namespace std;

  class Usuario;
  class Tarjeta;
  class Articulo;
  class Pedido_Articulo;
  class Usuario_Pedido;

  class Pedido
  {
    public:
      Pedido(Usuario_Pedido&, Pedido_Articulo&, Usuario&, Tarjeta&, const Fecha& = Fecha());

      int numero() const {  return this -> num_;  }
      const Tarjeta* tarjeta() const  { return this -> tarjeta_; }
      Fecha fecha() const { return this -> fecha_; }
      double total() const  { return this -> total_;  }
      static int const n_total_pedidos() { return N_pedidos; }

      class Vacio
      {
        public:
          Vacio(Usuario& u) : u_(u) { }
          Usuario& usuario() const { return u_;  }
        private:
          Usuario& u_;
      };

      class Impostor
      {
        public:
          Impostor(Usuario& u) : u_(u) { }
          Usuario& usuario() const { return u_;  }
        private:
          Usuario& u_;
      };

      class SinStock
      {
        public:
          SinStock(Articulo& ar) : ar_(ar) { }
          Articulo& articulo() const  { return ar_; }
        private:
          Articulo& ar_;
      };

      static int N_pedidos;

    private:

      int num_;
      Tarjeta* tarjeta_;
      Fecha fecha_;
      double total_;
  };

  class LineaPedido
  {
    public:
      explicit LineaPedido(double pv, unsigned cant = 1): precio_venta_{pv}, cantidad_{cant} {}
      double precio_venta() const { return precio_venta_;  }
      unsigned cantidad() const { return cantidad_;  }

    private:
      double precio_venta_;
      unsigned cantidad_;
  };

basic_ostream<char>& operator <<(basic_ostream<char>&, const Pedido&);
basic_ostream<char>& operator <<(basic_ostream<char>&, const LineaPedido&);

  #endif
