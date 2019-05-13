#include "tarjeta.hpp"

Numero::Numero(const Cadena& s): num{s}
{
    /*for(int i = 0; i < num.length() && num[i] != '\0';
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
    }*/

    find_if(num.begin(), num.end(), [](char c){ if(isalpha(c)) throw Incorrecto(DIGITOS);  })
    remove_if(num.begin(), num.end(), &isspace);
    num.adjustSize();

    if (num.length() < 13 || num.length() > 19)
        throw Incorrecto(LONGITUD);

    if(!luhn(num))
      throw Incorrecto(NO_VALIDO);
}

Numero::operator const char *() const
{
    return num.c_str();
}

Numero::Incorrecto::Incorrecto(const Razon r): r_{r} {}

Numero::Razon Numero::Incorrecto::razon() const
{
    return r_;
}

bool operator <(const Numero& n1, const Numero& n2)
{
    return Cadena{n1} < Cadena{n2};
}

Tarjeta::Caducada::Caducada(const Fecha& f): d{f} {}

Fecha Tarjeta::Caducada::cuando() const
{
    return d;
}

Tarjeta::Tarjeta(const Tipo t, const Numero& n, Usuario& u, 
const Fecha& d): type{t}, number{n}, user{&u}, date{d}, active{true}
{
    if(date.anno() < Fecha{}.anno())
        throw Caducada(date);
    if(date.anno() == Fecha{}.anno() && date.mes() < Fecha{}.mes())
        throw Caducada(date);
    if(date.anno() == Fecha{}.anno() && date.mes() == Fecha{}.mes() && date.dia() < Fecha{}.dia())
        throw Caducada(date);
    
    u.es_titular_de(*this);

    titular_facial_ = u.nombre() + " " + u.apellidos();
}

const Tarjeta::Tipo Tarjeta::tipo() const
{
    return type;
}

const Numero Tarjeta::numero() const
{
    return number;
}

const Usuario* Tarjeta::titular() const
{
    return user;
}

const Fecha Tarjeta::caducidad() const
{
    return date;
}

const Cadena Tarjeta::titular_facial() const
{
    return titular_facial_;
}

const bool Tarjeta::activa() const
{
    return active;
}

bool Tarjeta::activa(bool state)
{
    return active = state;
}

void Tarjeta::anula_titular()
{
    user = nullptr;
}

//Destructor
Tarjeta::~Tarjeta()
{
    if(user != nullptr)
        const_cast<Usuario*>(user) -> no_es_titular_de(*this);
}

ostream& operator <<(ostream& os, const Tarjeta& c)
{
    switch (c.tipo())
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

    os << '\n' << c.numero() << '\n' << c.titular_facial()
    << '\n' << "Caduca: " << setprecision(2) << ((c.caducidad().mes() < 10) ? '0' : ' ') <<
    c.caducidad().mes() << '/' << (c.caducidad().anno() % 100) << endl;

    return os;
}

bool operator <(const Tarjeta& C1, const Tarjeta& C2)
{
    return C1.numero() < C2.numero();
}