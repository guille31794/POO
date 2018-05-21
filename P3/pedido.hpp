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
  #include "usuario.hpp"

  using namespace std;

  class Usuario;
  class Tarjeta;
  class LineaPedido;

  class Pedido
  {
    public:
      Pedido(Usuario_pedido&, Pedido_Articulo&, Usuario&,
      Tarjeta&, Fecha&);

      int numero() const {  return this -> num_;  }
      const Tarjeta* tarjeta()  { return this -> tarjeta; }
      Fecha fecha() const { return this -> fecha; }
      double total() const  { return this -> total_;  }
      int const n_total_pedidos() { return this -> N_pedidos; }

      class Vacio
      {
        public:
          Vacio(Usuario& u) { u_ = u;  }
          Usuario* usuario() { return u_;  }
        private:
          Usuario* u_;
      }

      class Impostor
      {
        public:
          Impostor(Usuario& u)  { u_ = u; }
          Usuario* usuario()  { return u_;  }
        private:
          Usuario* u_;
      }

      class SinStock
      {
        public:
          SinStock(Articulo& ar)  { ar_ = ar; }
          Articulo* articulo()  { return ar_; }
        private:
          Articulo* ar_;
      }

    protected:
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
      explicit LineaPedido(double pv, unsigned cant = 1): precio_venta{pv},
      cantidad{cant}
      {}
      double precio_venta() const { return precio_venta;  }
      unsigned cantidad const { return cantidad;  }

    private:
      double precio_venta;
      unsigned cantidad;
  };

basic_ostream<char>& <<(basic_ostream<char>&, const Pedido&);
basic_ostream<char>& <<(basic_ostream<char>&, const LineaPedido&);

  #endif
