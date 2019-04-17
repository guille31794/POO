#include "tarjeta.hpp"

Tarjeta::Tarjeta(const Numero& n, Usuario& u, 
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