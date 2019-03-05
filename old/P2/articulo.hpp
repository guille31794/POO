/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */
#ifndef Articulo_hpp
#define Articulo_hpp
#include "fecha.hpp"
#include "cadena.hpp"
#include <iostream>
#include <iomanip>


class Articulo
{
  private:

  Cadena referencia_;
  Cadena titulo_;
  Fecha f_publi_;
  double precio_;
  unsigned stock_;

  public:

  explicit Articulo(const Cadena&, const Cadena&, const Fecha&, const double,
  const unsigned);

   Cadena referencia() const  { return this -> referencia_;}
   Cadena titulo() const  { return this -> titulo_;}
   Fecha f_publi() const  { return this -> f_publi_;}
   double precio() const { return this -> precio_;}
   double& precio()  { return this -> precio_;}
   unsigned stock() const  { return this -> stock_;}
   unsigned& stock() { return this -> stock_;}
};

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>&, const Articulo&);

#endif
