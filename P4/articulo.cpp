/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved
*/

  #include "articulo.hpp"

  Autor::Autor(const Cadena& nombre, const Cadena& apellidos,
  const Cadena& direccion): nombre_{nombre}, apellidos_{apellidos},
  direccion_{direccion}
  {}

  Articulo::Articulo(const Autores& a, const Cadena& referencia,
  const Cadena& titulo, const Fecha& f_publi, const double precio):
  referencia_{referencia}, titulo_{titulo}, f_publi_{f_publi},
  precio_{precio}
  {
    if(a.empty())
      throw Autores_vacios();
    else
      //this -> autores_.swap(a);
      this -> autores_ = a;
  }

  Articulo::~Articulo() {}

  std::basic_ostream<char>& operator <<
  (std::basic_ostream<char>& os, const Articulo& ar)
  {
    setlocale(LC_ALL, "es_ES");

    size_t cont = 0;

    os << '[' << ar.referencia() << "] " << '"' << ar.titulo() << '"' << ", de ";

    for(auto autores : ar.autores())
    {
      os << autores -> apellidos();

      if(cont < (ar.autores().size() - 1))
        os << ", ";

      ++cont;
    }

    os << ". " << ar.f_publi().anno() << ". " << setiosflags(ios::fixed) << setprecision(2)
    << ar.precio() << " €" << "\n\t";

    ar.impresion_especifica(os);

    return os;
  }

  ArticuloAlmacenable::ArticuloAlmacenable(const Autores& aut,
  const Cadena& referencia, const Cadena& titulo, const Fecha& f_publi,
  const double precio, const unsigned stock ): //sotck = 0
  Articulo(aut, referencia, titulo, f_publi, precio), stock_{stock}
  {}

  ArticuloAlmacenable::~ArticuloAlmacenable() {}

  Libro::Libro(const Autores& a, const Cadena& referencia,
  const Cadena& titulo, const Fecha& f_publi, const double precio,
  const size_t n_pag, const unsigned stock ): //stock = 0
  ArticuloAlmacenable(a, referencia, titulo, f_publi, precio, stock), n_pag_{n_pag}
  {}

  void Libro::impresion_especifica(basic_ostream<char>& os) const noexcept
  {
    setlocale(LC_ALL, "es_ES");

    os << this -> n_pag_ << " págs., " << this -> stock_ << " unidades.";
  }

  Cederron::Cederron(const Autores& a, const Cadena& referencia,
  const Cadena& titulo, const Fecha& f_publi, const double precio,
  const size_t tam, const unsigned stock): //stock = 0
  ArticuloAlmacenable(a, referencia, titulo, f_publi, precio, stock), tam_{tam}
  {}

  void Cederron::impresion_especifica(basic_ostream<char>& os) const noexcept
  {
    setlocale(LC_ALL, "es_ES");

    os << this -> tam_ << " MB, " << this -> stock_ << " unidades.";
  }

  LibroDigital::LibroDigital(const Autores& a,
  const Cadena& referencia, const Cadena& titulo, const Fecha& f_publi,
  const double precio, const Fecha& f_expir):
  Articulo(a, referencia, titulo, f_publi, precio), f_expir_{f_expir}
  {}

  void LibroDigital::impresion_especifica(basic_ostream<char>& os) const noexcept
  {
    setlocale(LC_ALL, "es_ES");

    os << "A la venta hasta el " << this -> f_expir_ << ".";
  }
