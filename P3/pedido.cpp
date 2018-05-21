#include "pedido.hpp"

Pedido::Pedido(Usuario_pedido& up, Pedido_Articulo& pa, Usuario& u,
Tarjeta& t, Fecha& f)
{

}

basic_ostream<char>& <<(basic_ostream<char>& os, const Pedido& p)
{
  setlocale(LC_ALL, "es_ES");

  os << "Num. pedido: " << p.numero() << '\n';
  os << "Fecha: \t\t " << p.fecha() << '\n';
  os << "Pagado con:\t" << p.tarjeta().tipo() << "n.º: "
  << p.tarjeta().numero() << '\n';
  os << "Importe:\t\t" << setiosflags(ios::fixed) <<
  setprecision(2) << p.total() << " €" << endl;

  return os;
}
