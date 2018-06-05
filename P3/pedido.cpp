/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  /21/05/2018, GPL Licensed, all rights reserved */

#include "pedido.hpp"

int Pedido::N_pedidos = 0;

Pedido::Pedido(Usuario_Pedido& up, Pedido_Articulo& pa, Usuario& u,
const Tarjeta& t, const Fecha& f) :num_{N_pedidos+1}, tarjeta_{&t}, fecha_{f},
total_{0}
{
  if(!u.n_articulos())
    throw Vacio(u);

  if (&u != t.titular())
    throw Impostor(u);

  if(t.caducidad() < f)
    throw Tarjeta::Caducada(t.caducidad());

  for(auto compra_ : u.compra())
    if (compra_.first -> stock() < compra_.second)
    {
      const_cast<Usuario::Articulos&> (u.compra()).clear();
      throw SinStock(*compra_.first);
    }

  Usuario::Articulos carrito = u.compra();

  for(auto carro_ : carrito)
  {
      Articulo* p_a = carro_.first;
      unsigned int cantidad = carro_.second;
      double precio = p_a->precio();

      p_a->stock() -= cantidad;
      pa.pedir(*this, *p_a, precio, cantidad);
      total_ += precio * cantidad;
      u.compra(*p_a, 0);
  }

  up.asocia(u, *this);
  ++N_pedidos;
}

std::basic_ostream<char>& operator <<(std::basic_ostream<char>& os, const Pedido& p)
{
  setlocale(LC_ALL, "es_ES");

  os << "Núm. pedido: " << p.numero() << '\n';
  os << "Fecha: \t\t " << p.fecha() << '\n';
  os << "Pagado con:\t" << p.tarjeta()->tipo() << " n.º: " << p.tarjeta()->numero() << '\n';
  os << "Importe:\t\t" << setiosflags(ios::fixed) << setprecision(2) << p.total() << " €" << endl;

  return os;
}

std::basic_ostream<char>& operator <<(std::basic_ostream<char>& os, const LineaPedido& lp)
{
  setlocale(LC_ALL, "es_ES");

  //TODO si hay fallo, es en el tabular, que deja dos espacios en lugar de 3

  os << setiosflags(ios::fixed) << setprecision(2) << lp.precio_venta() <<
  " €\t" << lp.cantidad();

  return os;
}
