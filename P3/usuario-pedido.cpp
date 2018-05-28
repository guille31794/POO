/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  22/05/2018, GPL Licensed, all rights reserved */

  #include "usuario-pedido.hpp"

  void Usuario_Pedido::asocia(const Usuario& u, const Pedido& p)
  {
    pedidos_.insert(&p);

    if(usuarios_.find(&u) != usuarios_.end())
        usuarios_.find(&u)->second.insert(&p);
    else
    {
        /*
          Si el usuario no ha realizado ningún pedido,
          lo añadimos al diccionario, junto con el pedido que esté realizando
        */

        Pedidos pedidos;
        pedidos.insert(&p);
        usuarios_.insert(make_pair(&u, pedidos));
    }
  }

  void Usuario_Pedido::asocia(const Pedido& p, const Usuario& u)
  {
    this -> asocia(u, p);
  }
  
  Usuario_Pedido::Pedidos Usuario_Pedido::pedidos(const Usuario& u) { 
      return usuarios_.find(&u) -> second;
  }

  Usuario& cliente(const Pedido& p)
  {
    if(pedidos_.find(&p) != pedidos_.end())
      return p.tarjeta() -> titular();
  }
