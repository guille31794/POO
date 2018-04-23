/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

Numero(const Cadena& c):
numero_{c}
{
  //TODO comprobar excepciones etc..
}

bool operator <(const Numero& n1, const Numero &n2)
{
  bool v;

  v = <static_cast>n1 < <static_cast>n2;

  return v;
}
