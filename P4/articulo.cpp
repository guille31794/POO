/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "articulo.hpp"

  Articulo::Articulo(const Autores& a, const Cadena& referencia, const Cadena& titulo,
  const Fecha& f_publi, const double precio):
  referencia_{referencia}, titulo_{titulo}, f_publi_{f_publi},
  precio_{precio}
  {
    if(a.empty())
      throw Autores_vacios();
    else
      this -> autores_.swap(a);
  }

  inline Cadena Articulo::referencia() const  { return this -> referencia_;}
  inline Cadena Articulo::titulo() const  { return this -> titulo_;}
  inline Fecha Articulo::f_publi() const  { return this -> f_publi_;}
  inline double Articulo::precio() const { return this -> precio_;}
  inline double& Articulo::precio()  { return this -> precio_;}

  std::basic_ostream<char>& operator <<
  (std::basic_ostream<char>& os, const Articulo& ar)
  {
    os << '[' << ar.referencia() << "] " << '"' << ar.titulo() << '"' << ", "
    << ar.f_publi().anno() << ". " << setiosflags(ios::fixed) << setprecision(2)
    << ar.precio() << " €";

    return os;
  }

  ArticuloAlmacenable::ArticuloAlmacenable(const Autores& aut,
  const Cadena& referencia, const Cadena& titulo, const Fecha& f_publi,
  const double precio, const unsigned stock ): //sotck = 0
  stock_{stock}
  {
    Articulo(aut, referencia, titulo, f_publi, precio);
  }

  inline unsigned ArticuloAlmacenable::stock()  { return this -> stock_; }

  Libro::Libro(const Autores& a, const Cadena& referencia,
  const Cadena& titulo, const Fecha& f_publi, const double precio,
  const size_t n_pag, const unsigned stock ): //stock = 0
  n_pag_{n_pag}
  {
    ArticuloAlmacenable(aut, referencia, titulo, f_publi, precio, stock);
  }

  Cederron::Cederron(const Autores& a, const Cadena& referencia,
  const Cadena& titulo, const Fecha& f_publi, const double precio,
  const size_t tam, const unsigned stock): //stock = 0
  tam_{tam}
  {
    ArticuloAlmacenable(aut, referencia, titulo, f_publi, precio, stock);
  }

  LibroDigital::LibroDigital(const Autores& a,
  const Cadena& referencia, const Cadena& titulo, const Fecha& f_publi,
  const double precio, const Fecha& f_expir):
  f_expir_{f_expir}
  {
    Articulo(aut, referencia, titulo, f_publi, precio);
  }
