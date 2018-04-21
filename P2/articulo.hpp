/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

#include "fecha.hpp"
#include "cadena.cpp"

class Articulo
{
  public:

  Cadena referencia() const;
  Cadena titulo() const;
  Fecha f_publi() const;
  double precio() const;
  double& precio();
  unsigned stock() const;
  unsigned& stock();
}
