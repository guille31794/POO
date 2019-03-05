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
    if(ArticuloAlmacenable* articuloAlmacenable =
    dynamic_cast<ArticuloAlmacenable*> (compra_.first))
      if (articuloAlmacenable -> stock() < compra_.second)
      {
        const_cast<Usuario::Articulos&> (u.compra()).clear();
        throw SinStock(*compra_.first);
      }

  unsigned articulosStock = 0;
  unsigned expirados = 0;
  unsigned n_ebooks = 0;
  Usuario::Articulos carrito = u.compra();

  for(auto carro_ : carrito)
  {
      Articulo* p_a = carro_.first;
      unsigned int cantidad = carro_.second;
      double precio = p_a -> precio();

      if(ArticuloAlmacenable *artAlmacenable =
      dynamic_cast<ArticuloAlmacenable*>(carro_.first))
      {
        artAlmacenable -> stock() -= cantidad;
        pa.pedir(*this, *p_a, precio, cantidad);
        u.compra(*p_a, 0);
        ++articulosStock;
      }
      else if(LibroDigital *libroD = dynamic_cast<LibroDigital*>(carro_.first))
      {
        ++n_ebooks;
        u.compra(*libroD, 0);
        if(libroD -> f_expir() < f)
        {
          ++expirados;
          continue;
        }
        pa.pedir(*this, *libroD, precio, cantidad);
      }

      this -> total_ += precio * cantidad;
  }

  if(!articulosStock && expirados > 0 && n_ebooks == expirados)
    throw Vacio(u);

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
