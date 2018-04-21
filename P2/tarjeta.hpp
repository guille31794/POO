/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "fecha.hpp"
  #include "cadena.hpp"

  class Tarjeta
  {

    public:

      Tipo tipo() const;
      Numero numero() const;
      Fecha caducidad() const;
      Cadena titular_facial() const;
      const Usuario* titular() const;
  }
