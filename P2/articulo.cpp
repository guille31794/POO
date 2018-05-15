/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "articulo.hpp"

  Articulo::Articulo(const Cadena& referencia, const Cadena& titulo,
  const Fecha& f_publi, const double precio, const unsigned stock):
  referencia_{referencia}, titulo_{titulo}, f_publi_{f_publi},
  precio_{precio}, stock_{stock}
  {}

  std::basic_ostream<char>& operator <<
  (std::basic_ostream<char>& os, const Articulo& ar)
  {
    char* precio_str = new char[3];
    sprintf(precio_str, "%.2f", ar.precio());

    os << '[' << ar.referencia() << "] " << '"' << ar.titulo() << '"' << ", "
    << ar.f_publi().anno() << ". " << precio_str << " €";

    return os;
  }
