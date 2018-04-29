/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "numero.hpp"

Numero::Numero(const Cadena& c):
numero_{c}
{
  for(auto i = numero_.begin(); i < numero_.end() < ++i)
  {
    if(isalpha(numero_[i]))
      throw Incorrecto(DIGITOS);

    if(isspace(numero_[i]))
    {
      for(auto cont = i; cont < numero_.end(); ++cont)
      {
        numero_[cont - 1] = numero_[cont];
      }

      numero_.reducir_tam();
    }
  }

  if(numero_.length() >= 19 || numero_.length() <= 13)
    throw Incorrecto(LONGITUD);

  if(!luhn(numero_))
    throw Incorrecto(NO_VALIDO);
}

bool operator <(const Numero& n1, const Numero &n2)
{
  bool v;

  v = static_cast<char*>n1 < static_cast<char*>n2;

  return v;
}
