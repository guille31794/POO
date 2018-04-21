/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "fecha.hpp"
  #include "cadena.hpp"
  #include "numero.hpp"
  #include "usuario.hpp"

  class Tarjeta
  {
    private:
      Numero numero_;
      Usuario* titular_;
      Fecha caducidad_;
      Cadena titular_facial_;

    public:
      typedef Tipo
      {
        enum tipo_ {VISA, Mastercard, Maestro, JCB,
           AmericanExpress};
      };
      Tipo tipo() const;
      Numero numero() const;
      Fecha caducidad() const;
      Cadena titular_facial() const;
      const Usuario* titular() const;
  }
