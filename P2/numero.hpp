/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

#ifndef Numero_hpp
#define Numero_hpp
#include <cctype>
#include "cadena.hpp"
#include "luhn.cpp"

bool luhn(const Cadena&);

  class Numero
  {
    private:

      Cadena numero_;

    public:

      enum Razon {LONGITUD, DIGITOS, NO_VALIDO};
      Numero(const Cadena&);
      inline operator const char*() const { return this -> numero_.c_str();}

      class Incorrecto
      {
        private:

          Razon r;

        public:

          inline Incorrecto(const Razon r_): r{r_} {}
          inline Razon razon() const { return this -> r;}
      };
  };

  bool operator <(const Numero&, const Numero &);

#endif
