/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  22/05/2018, GPL Licensed, all rights reserved */

  #ifndef Usuario_Pedido_hpp
  #define Usuario_Pedido_hpp

  #include <utility>

  using namespace std;

  class Usuario;
  class Pedido;

  class Usuario_Pedido
  {
    public:
      typedef set<Pedido*> Pedidos;
      typedef map<Usuario*, Pedidos> Usuarios;

      void asocia(const Usuario&, const Pedido&);
      void asocia(const Pedido&, const Usuario&);
      Pedidos pedidos(const Usuario&) { return usuarios_.find(&u) -> second;  }
      Usuario& cliente(const Pedido&);

    private:
      Pedidos pedidos_;
      Usuarios usuarios_;
  };

  #endif
