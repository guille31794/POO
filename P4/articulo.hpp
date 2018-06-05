/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved
*/

#ifndef Articulo_hpp
#define Articulo_hpp
#include "fecha.hpp"
#include "cadena.hpp"
#include <iostream>
#include <iomanip>


class Articulo
{
  public:

  explicit Articulo(const Cadena&, const Cadena&, const Fecha&, const double,
  const unsigned);

   virtual Cadena referencia() const noexcept = 0;
   virtual Cadena titulo() const noexcept = 0;
   virtual Fecha f_publi() const noexcept = 0;
   virtual double precio() const noexcept = 0;
   virtual double& precio() noexcept = 0;
   //TODO
   virtual void impresion_especifica(ostream&) = 0;

 private:

 Autores autores_;
 Cadena referencia_;
 Cadena titulo_;
 Fecha f_publi_;
 double precio_;

};

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>&, const Articulo&);

class ArticuloAlmacenable: public Articulo
{
  public:
    ArticuloAlmacenable(const Cadena&, const Cadena&, const Fecha&, const double,
    const unsigned = 0);
    virtual unsigned stock() const noexcept = 0;
  private:
    unsigned stock_;
};

class Libro: public ArticuloAlmacenable
{
  public:
    Libro(const Cadena&, const Cadena&, const Fecha&, const double,
    const size_t, const unsigned = 0);
    const size_t n_pag() const noexcept { return this -> n_pag_;  }

  private:
    const size_t n_pag_;
};

class Cederron: public ArticuloAlmacenable
{
  private:
    Cederron(const Cadena&, const Cadena&, const Fecha&, const double,
    const size_t, const unsigned = 0);
    const size_t tam() const noexcept { return this -> tam_;}

  public:
    const size_t tam_;
};

class LibroDigital: public Articulo
{
  public:
    LibroDigital(const Cadena&, const Cadena&, const Fecha&, const double,
    const unsigned, const Fecha&);
    const Fecha f_expir() const noexcept  { return this -> f_expir_;  }

  private:
    const Fecha f_expir_;
};

#endif
