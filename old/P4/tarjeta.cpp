/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "tarjeta.hpp"

  Numero::Numero(Cadena c)
  {
    auto charEliminados = remove_if(c.begin(), c.end(), EsBlanco());

    c = c.substr(0, (c.length() - strlen(charEliminados)));

    if(c.length() < 13 || c.length() > 19  )
      throw Incorrecto(LONGITUD);

    if(c.end() != find_if_not(c.begin(), c.end(), EsDigito()))
      throw Incorrecto(DIGITOS);

    if(!luhn(c))
      throw Incorrecto(NO_VALIDO);

    numero_ = c;
  }


  Tarjeta::Tarjeta(Tipo t, Numero n, Usuario& u, const Fecha& f): tipo_{t}, numero_{n}, titular_{&u}, caducidad_(f)
  {
    Fecha hoy;

    if(caducidad_ < hoy)
      throw Caducada(caducidad_);

    u.es_titular_de(*this);

    this -> titular_facial_ = u.nombre() + " " + u.apellidos();
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
  << '\n' << "Caduca: " << setprecision(2) << ((t.caducidad().mes() < 10) ? '0' : ' ') <<
  t.caducidad().mes() << '/' << (t.caducidad().anno() % 100) << endl;

  return os;
}

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>& os, const Tarjeta::Tipo& t)
{
  switch (t)
  {
    case Tarjeta::Tipo::VISA: os << "VISA";
              break;
    case Tarjeta::Tipo::Mastercard: os << "Mastercard";
              break;
    case Tarjeta::Tipo::Maestro: os << "Maestro";
              break;
    case Tarjeta::Tipo::AmericanExpress: os << "American Expres";
              break;
    case Tarjeta::Tipo::JCB: os << "JCB";
              break;
    default: os << "Error, ninguna tarjeta conocida" << endl;
  }

  return os;
}
