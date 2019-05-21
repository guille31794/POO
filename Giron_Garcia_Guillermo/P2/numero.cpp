#include "numero.hpp"

Numero::Numero(const Cadena& s): num{s}
{
    for(int i = 0; i < num.length() && num[i] != '\0';
    ++i)
    {
      if(isalpha(num[i]))
        throw Incorrecto(DIGITOS);

      while(isspace(num[i]))
      {
        for(auto cont = i; cont < num.length() && num[cont] != '\0';
        ++cont)
        {
          num[cont] = num[cont + 1];
        }

        num[num.length()] = '\0';
        num.adjustSize();
      }

      if(num.length() < 13 || num.length() > 19  )
        throw Incorrecto(LONGITUD);
    }

    if( num.length() < 13)
      throw Incorrecto(LONGITUD);

    if(!luhn(num))
      throw Incorrecto(NO_VALIDO);
}

Numero::operator char *() const
{
    return num.c_str();
}

Numero::Incorrecto::Incorrecto(const Razon r): r_{r} {}

Numero::Razon Numero::Incorrecto::razon() const
{
    return r_;
}