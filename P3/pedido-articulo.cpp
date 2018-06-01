/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  22/05/2018, GPL Licensed, all rights reserved */

  #include "pedido-articulo.hpp"

  inline bool OrdenaPedidos::operator() (Pedido* p1, Pedido* p2) const
  {
    return p1 -> numero() < p2 -> numero();
  }

  void Pedido_Articulo::pedir
  (Pedido& p, Articulo& ar, double precio, unsigned cant)
  {
    auto i = pedidosArticulos_.find(&p);

    if (i != pedidosArticulos_.end())
      i -> second.insert(make_pair(&ar, LineaPedido(precio, cant)));
    else
      {
        ItemsPedido itemspedido;
        itemspedido.insert(make_pair(&ar, LineaPedido(precio, cant)));
        pedidosArticulos_.insert(make_pair(&p, itemspedido));
      }

    auto it = articulosPedidos_.find(&ar);

    if (it != articulosPedidos_.end())
      it -> second.insert(make_pair(&p, LineaPedido(precio, cant)));
    else
    {
      Pedidos pedidos;
      pedidos.insert(make_pair(&p, LineaPedido(precio, cant)));
      articulosPedidos_.insert(make_pair(&ar, pedidos));
    }
  }

  void Pedido_Articulo::pedir
  (Articulo& ar, Pedido& p, double precio, unsigned cant)
  {
    pedir(p, ar, precio, cant);
  }

  const Pedido_Articulo::ItemsPedido& Pedido_Articulo::detalle(Pedido& p)
  {
    return pedidosArticulos_.find(&p) -> second;
  }

  const Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo& ar)
  {
    return articulosPedidos_.find(&ar) -> second;
  }

  std::basic_ostream<char>&
  Pedido_Articulo::mostrarDetallePedidos(std::basic_ostream<char>& os)
  {
    setlocale(LC_ALL, "es_ES");

    double total = 0;

    for(auto ap : articulosPedidos_)
      for(auto pedidos : ap.second)
      {
        os << "Pedido núm. "  << pedidos.first -> numero() << " Cliente: " <<
        pedidos.first -> tarjeta() -> titular() << "\t\tFecha: " <<
        pedidos.first -> fecha() << '\n';
        total += pedidos.second.precio_venta();
      }

    os << "\nTOTAL VENTAS\t\t"<< setprecision(2) << total << " €" << endl;

    return os;
  }

  std::basic_ostream<char>&
  Pedido_Articulo::mostrarVentasArticulos(std::basic_ostream<char>& os)
  {
    setlocale(LC_ALL, "es_ES");

    for(auto i : articulosPedidos_)
    {
      os << "Ventas de " << *i.first << i.second << endl;
    }

    return os;
  }

  std::basic_ostream<char>& operator <<
  (std::basic_ostream<char>& os, Pedido_Articulo::PedidosArticulos& pa)
  {
    setlocale(LC_ALL, "es_ES");
    os << "PVP\tCantidad\t\tArtículo\n" <<
    "==================================================================\n";

    /*
      bucle for mejorado. Equivale a for each
    */

    double total = 0;

    for(auto itpa : pa) //Reocorro PedidosArticulos
      for(auto itemspedido_ : itpa.second) //Recorro ItemsPedido
      {
        os << setiosflags(ios::fixed) << setprecision(2) <<
        itemspedido_.second.precio_venta() << " € " <<
        itemspedido_.second.cantidad() << "\t\t\t\t\t [" <<
        itemspedido_.first -> referencia() << "] \"" <<
        itemspedido_.first -> titulo() << "\"\n";
        total += itemspedido_.second.precio_venta();
      }

    os <<
    "==================================================================\n" <<
    "Total\t" << setprecision(2) << total << " €" << endl;

    return os;
  }

  std::basic_ostream<char>& operator <<
  (std::basic_ostream<char>& os, Pedido_Articulo::ArticulosPedidos& ap)
  {
    setlocale(LC_ALL, "es_ES");

    os << "[Pedidos: " << ap.size() << "]\n" <<
    "==================================================================\n" <<
    "PVP\t Cantidad\t\t\t  Fecha de venta\n" <<
    "==================================================================\n";

    double total = 0;
    unsigned cant = 0;

    for( auto itap : ap)
      for(auto pedidos_ : itap.second)
      {
        os << setiosflags(ios::fixed) << setprecision(2) <<
        pedidos_.second.precio_venta() << " € " << pedidos_.second.cantidad() <<
        "\t\t\t " << pedidos_.first -> fecha();
        total += pedidos_.second.precio_venta();
        cant += pedidos_.second.cantidad();
      }

    os << "==================================================================\n"
    << setprecision(2) << total << " €\t\t\t" << cant << endl;

    return os;
  }
