/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "cadena.hpp"

  class Usuario
  {

    public:

    void es_titular_de(Tarjeta &);
    void no_es_titular_de(Tarjeta &);
    Cadena id() const;
    Cadena nombre() const;
    Cadena apellidos() const;
    Cadena dirección() const;
    const Tarjeta& tarjetas() const;
    void compra(Articulo&, unsigned);
    const Articulo& compra() const;
    size_t n_articulos() const;
  }
