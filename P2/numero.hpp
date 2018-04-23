/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

#ifndef Numero_hpp
#define Numero_hpp
#include "cadena.hpp"

  class Numero {
  private:
    Cadena numero_;

  public:
    operator const char*() const;
  };

#endif
