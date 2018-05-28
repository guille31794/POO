/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  /21/05/2018, GPL Licensed, all rights reserved */

#include "pedido.hpp"

Pedido::Pedido(Usuario_Pedido& up, Pedido_Articulo& pa, Usuario& u,
Tarjeta& t, const Fecha& f)
{

}

basic_ostream<char>& operator <<(basic_ostream<char>& os, const Pedido& p)
{
  setlocale(LC_ALL, "es_ES");

  os << "Num. pedido: " << p.numero() << '\n';
  os << "Fecha: \t\t " << p.fecha() << '\n';
  os << "Pagado con:\t" << p.tarjeta()->tipo() << "n.º: "
  << p.tarjeta()->numero() << '\n';
  os << "Importe:\t\t" << setiosflags(ios::fixed) <<
  setprecision(2) << p.total() << " €" << endl;

  return os;
}

basic_ostream<char>& operator <<(basic_ostream<char>& os, const LineaPedido& lp)
{
  setlocale(LC_ALL, "es_ES");

  //TODO si hay fallo, es en el tabular, que deja dos espacios en lugar de 3

  os << setiosflags(ios::fixed) << setprecision(2) << lp.precio_venta() <<
  " €\t" << lp.cantidad();

  return os;
}
