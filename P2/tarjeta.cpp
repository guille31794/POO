#include "tarjeta.hpp"

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

Tarjeta::Tarjeta(const Tipo t, const Numero& n, Usuario& u, 
const Fecha& d): number{n}, user{&u}, date{d}, active{true}
{
    if(date < Fecha{})
        throw Caducada(date);
    
    u.es_titular_de(*this);

    switch (number[0])
    {
        case '3': 
            switch (number[1])
            {
                case '4': type = AmericanExpress;
                    break;
                case '7': type = AmericanExpress;
                    break;
                default: type = JCB;
                    break;
            }
            break;
        case '4': type = VISA;
            break;
        case '5': type = Mastercard;
            break;
        case '6': type = Maestro;
            break;
        default: type = Otro;
            break;
    }
}

Tarjeta::Tipo Tarjeta::tipo() const
{
    return type;
}

Numero Tarjeta::numero() const
{
    return number;
}

Usuario* Tarjeta::titular() const
{
    return user;
}

Fecha Tarjeta::caducidad() const
{
    return date;
}

bool Tarjeta::activa() const
{
    return active;
}

bool Tarjeta::activa(bool state)
{
    return active = state;
}

//TODO: destructor, operators
Tarjeta::~Tarjeta()
{
    if(user != nullptr)
        const_cast<Usuario*>(user) -> no_es_titular_de(*this);
}

ostream& operator <<(ostream& os, const Tarjeta& C)
{
    os << "____________________\n\'\t\t\t\t\t\'\n| ";

    switch(C.tipo()) 
    {
        case Tarjeta::Tipo::AmericanExpress: 
            os << "American Express";
            break;
        case Tarjeta::Tipo::VISA: os << "VISA";
            break;
        case Tarjeta::Tipo::Maestro: os << "Maestro";
            break;
        case Tarjeta::Tipo::JCB: os << "JCB";
            break;
        case Tarjeta::Tipo::Mastercard: os << "Mastercard";
            break;
        default: os << "OTROS";
            break;
    }
    
    os << " |\n| " + C.numero() + " |\n| " + 
    C.titular() + " |\n| Caduca: " + C.caducidad() + 
    "\t |\n\\____________________/";

    return os;
}

bool operator <(const Tarjeta& C1, const Tarjeta& C2)
{
    return C1.numero() < C2.numero();
}