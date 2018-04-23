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

    enum Razon {LONGITUD, DIGITOS, NO_VALIDO};
    Numero(const Cadena&);
    operator const char*() const;

    class Incorrecto
    {
      private:

        Razon r;

      public:

        inline Incorrecto(const Razon r_): r{r_} {}
        inline Razon razon() const { return this -> r;}
    };
  };

#endif
