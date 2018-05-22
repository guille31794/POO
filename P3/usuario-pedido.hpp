/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  22/05/2018, GPL Licensed, all rights reserved */

  #ifndef Usuario_Pedido_hpp
  #define Usuario_Pedido_hpp

  using namespace std;

  class Usuario_Pedido
  {
    public:
      typedef set<Pedido*> Pedidos;

      void asocia(const Usuario&, const Pedido&);
      void asocia(const Pedido&, const Usuario&);

    private:
      map<Usuario*, Pedidos> usuario_pedido;
      map<Pedido*, Usuario*> pedido_usuario;
  };

  #endif
