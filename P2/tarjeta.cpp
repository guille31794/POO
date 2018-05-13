/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "tarjeta.hpp"

  Numero::Numero(const Cadena& c):
  numero_{}
  {
    numero_ = c;

    for(int i = 0; i < numero_.length() && numero_[i] != '\0';
    ++i)
    {
      if(isalpha(numero_[i]))
        throw Incorrecto(DIGITOS);

      while(isspace(numero_[i]))
      {
        for(auto cont = i; cont < numero_.length() && numero_[cont] != '\0';
        ++cont)
        {
          numero_[cont] = numero_[cont + 1];
        }

        numero_.reducir_tam();
        numero_[numero_.length() + 1] = '\0';
      }

      if(numero_.length() < 13)
        throw Incorrecto(LONGITUD);

    }

    if(numero_.length() >= 19 || numero_.length() <= 13)
      throw Incorrecto(LONGITUD);

    if(!luhn(numero_))
      throw Incorrecto(NO_VALIDO);
  }


  Tarjeta::Tarjeta(const Tipo t, const Numero& n, Usuario& u, const Fecha& f):
  numero_{n}, titular_{&u}, caducidad_{f}, tipo_{t}
  {
    Fecha hoy;

    if(caducidad_ < hoy)
      throw Caducada(caducidad_);

    u.es_titular_de(*this);
  }

  Tarjeta::~Tarjeta()
  {
      if(titular_ != nullptr)
        const_cast<Usuario*>(titular_) -> no_es_titular_de(*this);
  }

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>& os, const Tarjeta& t)
{
  os << t.tipo() << '\n' << t.numero() << '\n' << t.titular_facial()
  << '\n' << "Caduca: " << setprecision(2) << t.caducidad().mes() <<
   '/' << setprecision(2) << t.caducidad().anno();

  return os;
}
