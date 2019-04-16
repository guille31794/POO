#include "usuario.hpp"

//Constructor
Usuario::Usuario(const char* id, const char* n, const char* sn,
const char* a, const char* k): identifier{id}, name{n},
surname{sn}, address{a}, password{k} 
{
    //TODO conditions
}

//Getters
Cadena Usuario::id() const
{
    return identifier;
}

Cadena Usuario::nombre() const
{
    return name;
}

Cadena Usuario::apellidos() const
{
    return surname;
}

Cadena Usuario::direccion() const
{
    return address;
}

Usuario::Tarjetas Usuario::tarjetas() const
{
    return cards;
}

Usuario::Articulos Usuario::compra() const
{
    return shopping_kart;
}

unsigned Usuario::n_articulos() const
{
    return shopping_kart.size();
}

Clave Usuario::pass() const
{
    return password;
}

//Asociative methods
void Usuario::es_titular_de(const Tarjeta& c)
{
    cards.insert(make_pair(c.numero(), &c));
}

void Usuario::no_es_titular_de(const Tarjeta& c)
{
    cards.erase(c.numero());
}

void Usuario::compra(const Articulo& a, const unsigned q)
{
    if(!q)
        shopping_kart.erase(a);
    else
        shopping_kart.insert(make_pair(&a, q));
}

//Destructor
Usuario::~Usuario()
{
    for(auto it : cards)
    {
        it.second -> anula_titular();
        cards.erase(it);
    }
}

//Operators
ostream& operator <<(ostream& os, const Usuario& u)
{
    os << u.id() << " [" << u.pass().clave() << "] " << 
    u.nombre() << ' ' << u.apellidos() << '\n' << u.direccion()
    << "\nTarjetas:\n";

    for(auto it : u.tarjetas())
        os << it.second << '\n';
    
    return os;
}

ostream& mostrar_carro(ostream& os, const Usuario u)
{
    os << "Carrito de la compra de " << u.id() << 
    " [Artículos: " << u.compra().size() << "]\n Cant.  Artículo\n"
    <<
    "===========================================================\n";

    for(auto it : u.compra())
    {
        os << "  " << it.second << "   " << '[' <<
        it.first -> referencia() << '\"' << it.first -> titulo()
        << "\", " << it.first -> f_publi().anno() << ". " << 
        setiosflags(ios::fixed) << setprecision(2) << 
        it.first -> precio() << " €\n"; 
    }

    return os;
}