/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "articulo.hpp"

  Articulo::Articulo(const Cadena& referencia, const Cadena& titulo,
  const Fecha& f_publi, const double precio, const double stock):
  referencia_{referencia}, titulo_{titulo}, f_publi_{f_publi},
  precio_{precio}, stock_{stock}
  {}

  
