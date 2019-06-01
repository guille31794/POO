#include "tarjeta.hpp"

set<Numero> Tarjeta::Numbers{};

bool EsBlanco::operator()(char c)
{
    return isspace(c);
}

bool EsDigito::operator()(char c)
{
    return isdigit(c);
}

Numero::Numero(const Cadena& s): num{s}
{
    // ###############################################################
    auto res = remove_if(num.begin(), num.end(), EsBlanco());
    num = num.substr(0, num.length() - strlen(res));
    // ###############################################################
    
    if (num.end() != find_if_not(num.begin(), num.end(), EsDigito()))
        throw Incorrecto(DIGITOS);
    
    if (num.length() < 13 || num.length() > 19)
        throw Incorrecto(LONGITUD);
    
    if(!luhn(num))
        throw Incorrecto(NO_VALIDO);
}

Numero::operator const char *() const
{
    return num.c_str();
}

bool operator ==(const Numero& n1, const Numero& n2)
{
    return strcmp(n1, n2) == 0;
}

Numero::Incorrecto::Incorrecto(const Razon r): r_{r} {}

Numero::Razon Numero::Incorrecto::razon() const
{
    return r_;
}

Tarjeta::Num_duplicado::Num_duplicado(const Numero &num) : n{num}
{}

Numero Tarjeta::Num_duplicado::que() const
{
    return n;
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

Tarjeta::Tarjeta(const Numero& n, Usuario& u, 
const Fecha& d): number{n}, user{&u}, date{d}, active{true}
{
    if(date.anno() < Fecha{}.anno())
        throw Caducada(date);
    if(date.anno() == Fecha{}.anno() && date.mes() < Fecha{}.mes())
        throw Caducada(date);
    if(date.anno() == Fecha{}.anno() && date.mes() == Fecha{}.mes() && date.dia() < Fecha{}.dia())
        throw Caducada(date);

    pair<set<Numero>::iterator, bool> p = Numbers.insert(number);

    if(!p.second)
        throw Num_duplicado(number);

    switch (number[0])
    {
    case '4': type = VISA;
        break;
    case '5': type = Mastercard;
        break;
    case '6': type = Maestro;
        break;
    case '3': 
        switch (number[1])
        {
        case '4' | '7': type = AmericanExpress;
            break;
        default: type = JCB;
            break;
        }
    default: type= Otro;
        break;
    }

    Cadena tf{u.nombre() + " " + u.apellidos()};

    for(unsigned i = 0; i < tf.length(); ++i)
        tf[i] = toupper(tf[i]);
    
    titular_facial_ = tf;

    user->es_titular_de(*this);
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
    Numbers.erase(number);
}

ostream& operator <<(ostream& os, Tarjeta::Tipo t)
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
        default: os << "Tipo indeterminado";
    }

    return os;
}

ostream& operator <<(ostream& os, const Tarjeta& c)
{
    os << c.tipo() << '\n' << c.numero() << '\n' << c.titular_facial()
    << '\n' << "Caduca: " << setprecision(2) << ((c.caducidad().mes() < 10) ? '0' : ' ') <<
    c.caducidad().mes() << '/' << (c.caducidad().anno() % 100) << endl;

    return os;
}

bool operator <(const Tarjeta& C1, const Tarjeta& C2)
{
    return C1.numero() < C2.numero();
}
