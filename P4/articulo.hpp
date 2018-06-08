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
#include <unordered_set>
#include <locale>

using namespace std;

class Autor
{
  public:

    Autor(const Cadena&, const Cadena&, const Cadena&) noexcept;
    const Cadena nombre() const noexcept { return this -> nombre_;  }
    const Cadena apellidos() const noexcept { return this -> apellidos_;  }
    const Cadena direccion() const noexcept { return this -> direccion_;  }

  private:
    const Cadena nombre_;
    const Cadena apellidos_;
    const Cadena direccion_;
};

class Articulo
{
  public:

  class Autores_vacios{};

  typedef unordered_set<Autor*> Autores;

  explicit Articulo(const Autores&, const Cadena&, const Cadena&, const Fecha&,
  const double);

  Cadena referencia() const noexcept;
  Cadena titulo() const noexcept;
  Fecha f_publi() const noexcept;
  double precio() const noexcept;
  double& precio() noexcept;
  Autores autores() const noexcept  { return this -> autores_;  }

  virtual void impresion_especifica(basic_ostream<char>&) const noexcept = 0;

  virtual ~Articulo() = 0;

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
    ArticuloAlmacenable(const Autores&, const Cadena&, const Cadena&, const Fecha&, const double,
    const unsigned = 0);
    const unsigned stock() const noexcept;
    unsigned& stock() noexcept;

    virtual void impresion_especifica(basic_ostream<char>&) const noexcept = 0;

    virtual ~ArticuloAlmacenable() = 0;

  private:
    unsigned stock_;
};

class Libro: public ArticuloAlmacenable
{
  public:
    Libro(const Autores&, const Cadena&, const Cadena&, const Fecha&, const double,
    const size_t, const unsigned = 0);
    const size_t n_pag() const noexcept { return this -> n_pag_;  }

    void impresion_especifica(basic_ostream<char>&) const noexcept;

  private:
    const size_t n_pag_;
};

class Cederron: public ArticuloAlmacenable
{
  public:
    Cederron(const Autores&, const Cadena&, const Cadena&, const Fecha&, const double,
    const size_t, const unsigned = 0);
    const size_t tam() const noexcept { return this -> tam_;}

    void impresion_especifica(basic_ostream<char>&) const noexcept;

  private:
    const size_t tam_;
};

class LibroDigital: public Articulo
{
  public:
    LibroDigital(const Autores&, const Cadena&, const Cadena&, const Fecha&,
    const double, const Fecha&);
    const Fecha f_expir() const noexcept  { return this -> f_expir_;  }

    void impresion_especifica(basic_ostream<char>& os) const noexcept;

  private:
    const Fecha f_expir_;
};

#endif
