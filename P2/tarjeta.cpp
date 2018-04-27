/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  Tarjeta(const Tipo t, const Numero& n, Usuario& u, const Fecha& f):
  numero_{n}, titular_{u}, caducidad_{f}, tipo_{t}
  {
    Fecha hoy;

    if(caducidad_ < hoy)
      throw Caducada(caducidad_);

    u.es_titular_de(*this);
  }

  ~Tarjeta()
  {
    this -> titular_.no_es_titular_de(*this);
  }

ostream& operator << (ostream& os, const Tarjeta& t)
{
  os << t.tipo() << '\n' << t.numero() << '\n' << t.titular_facial()
  << '\n' << "Caduca: " << t.caducidad().mes() << '/'
  << t.caducidad().anno();

  return os;
}
