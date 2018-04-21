/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "cadena.hpp"
  #include "tarjeta.hpp"
  #include "articulo.hpp"

  using namespace std;

  class Usuario
  {
    private:
      Cadena id_, nombre_, apellidos, direccion_;
      Clave contraseña_;
      map<Numero, Tarjeta*> tarjetas_;
      unordered_map<Articulo*, unsigned int> articulos_;

    public:

      void es_titular_de(Tarjeta &);
      void no_es_titular_de(Tarjeta &);
      Cadena id() const;
      Cadena nombre() const;
      Cadena apellidos() const;
      Cadena direccion() const;
      const Tarjeta& tarjetas() const;
      void compra(Articulo&, unsigned);
      const Articulo& compra() const;
      size_t n_articulos() const;
  }
