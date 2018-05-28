/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  22/05/2018, GPL Licensed, all rights reserved */

  #include "pedido-articulo.hpp"

  void Pedido_Articulo::pedir
  (Pedido& p, Articulo& ar, double precio, unsigned cant
  {
    auto i = pedidosArticulos_.find(&p);

    if (i != pedidosArticulos_.end())
      i -> second.insert(make_pair(&a, LineaPedido(precio, cant)));
    else
      {
        ItemsPedido itemspedido;
        itemspedido.insert(make_pair(&a, LineaPedido(precio, cant)));
        pedidosArticulos_.insert(make_pair(&p, itemspedido));
      }
  }

  void Pedido_Articulo::pedir
  (Articulo& ar, Pedido& p, double precio, unsigned cant)
  {
    pedir(p, ar, precio, cant);
  }

  //TODO: probablemente pida un set de articulos

  Articulo Pedido_Articulo::detalle(const ItemsPedido& ip) const
  {

  }

  Pedidos Pedido_Articulo::ventas()
  {

  }

  basic_ostream<char>& mostrarDetallePedidos(basic_ostream<char>& os)
  {
    setlocale(LC_ALL, "es_ES");

    os << ;

    return os;
  }

  void mostrarVentasArticulos()
  {

  }

  basic_ostream<char>& <<
  (basic_ostream<char>& os, Pedido_Articulo::ItemsPedido& ip)
  {
    setlocale(LC_ALL, "es_ES");
    os << "PVP\tCantidad\t\tArtículo\n" <<
    "==================================================================\n" <<


    return os;
  }

  basic_ostream<char>& <<
  (basic_ostream<char>& os, Pedido_Articulo::Pedidos& p)
  {
    setlocale(LC_ALL, "es_ES");

    os << ;

    return os;
  }
