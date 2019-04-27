#include "usuario.hpp"

//Constructor
Clave::Clave(const char* s): key{}
{
    if(strlen(s) < 5)
      throw Incorrecta(CORTA);

    //Setting up crypt call

    char* salt = new char[2];
    int r_number;
    const char *const seedchars
    {"./0123456789ABCDEFGHIJKLMNOPQRST"
    "UVWXYZabcdefghijklmnopqrstuvwxyz"};

    //Random real value seed

    std::random_device r;

    /*
      Random generation engine
    */

    std::default_random_engine el{r()};

    /*
      I distribute my pseudo-random number according
      to a uniform distribution of integer parameters (0, 64),
      which is our range of values in ASCII code.
    */

    std::uniform_int_distribution<int> u_dist{0, (int)(strlen(seedchars)) - 1};

    for(int i = 0; i < 2; ++i )
    {
      r_number = u_dist(el);
      salt[i] = seedchars[r_number];
    }

    char* encrypted = crypt(s, salt);

    if(s == encrypted)
      throw Incorrecta(ERROR_CRYPT);

    key = encrypted;

}

//Getters
Cadena Clave::clave() const
{
    return key;
}

bool Clave::verifica(const char* s) const
{
    bool v;

    if(const char* const checker = crypt(s, key.c_str()))
        v = checker == key;
    else
        throw Incorrecta(ERROR_CRYPT);

    return v;
}

//Exception stuff
Clave::Incorrecta::Incorrecta(Razon r): r_{r} {}

Clave::Razon Clave::Incorrecta::razon() const
{
    return r_;
}

//Constructor
Usuario::Usuario(const char* id, const char* n, const char* sn,
const char* a, const char* k): identifier{id}, name{n},
surname{sn}, address{a}, password{k} 
{
    pair<unordered_set<Cadena*>::iterator, bool> p = 
    users.insert(&identifier);

    if (!p.second)
        throw Id_duplicado{identifier};
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
void Usuario::es_titular_de(Tarjeta& c)
{
    if(identifier == c.titular() -> id())
        cards.insert(make_pair(c.numero(), &c));
}

void Usuario::no_es_titular_de(const Tarjeta& c)
{
    cards.erase(c.numero());
}

void Usuario::compra(Articulo& a, unsigned q)
{
    if(!q)
        shopping_kart.erase(&a);
    else
        shopping_kart.insert(make_pair(&a, q));
}

//Destructor
Usuario::~Usuario()
{
    users.erase(&identifier);

    for(auto it : cards)
    {
        it.second -> anula_titular();
    }

    cards.erase(cards.begin(), cards.end());
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