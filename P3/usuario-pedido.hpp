/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  22/05/2018, GPL Licensed, all rights reserved */

  #ifndef Usuario_Pedido_hpp
  #define Usuario_Pedido_hpp

  #include "pedido.hpp"
  #include "usuario.hpp"
  #include <utility>
  #include <set>
  #include <map>

  using namespace std;

  class Usuario;
  class Pedido;

  class Usuario_Pedido
  {
    public:
      typedef set<Pedido*> Pedidos;
      typedef map<Usuario*, Pedidos> Usuarios;

      void asocia(Usuario&, Pedido&);
      void asocia(Pedido&, Usuario&);
      Pedidos pedidos(Usuario&);
      const Usuario* cliente(Pedido&);

    private:
      Pedidos pedidos_;
      Usuarios usuarios_;
  };

  #endif
