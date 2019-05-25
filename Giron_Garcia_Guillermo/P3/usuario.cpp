#include "usuario.hpp"

//Static user checker
unordered_set<Cadena> Usuario::users;

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
Usuario::Usuario(const Cadena& id, const Cadena& n, const Cadena& sn,
const Cadena& a, const Clave& k): identifier{id}, name{n},
surname{sn}, address{a}, password{k} 
{
    pair<unordered_set<Cadena>::iterator, bool> p = 
    users.insert(identifier);

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

const Usuario::Tarjetas &Usuario::tarjetas() const
{
    return cards;
}

const Usuario::Articulos& Usuario::compra() const
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
    if(identifier == c.titular() -> id() || c.titular() == nullptr)
        cards.insert(pair(c.numero(), &c));        
}

void Usuario::no_es_titular_de(Tarjeta& c)
{
    cards.erase(c.numero());
}

void Usuario::compra(Articulo& a, unsigned q)
{
    if(!q)
        shopping_kart.erase(&a);
    else
        shopping_kart[&a] = q;
}

//Destructor
Usuario::~Usuario()
{
    users.erase(identifier);

    for(auto it : cards)
        it.second -> anula_titular();

    cards.erase(cards.begin(), cards.end());
}

Usuario::Id_duplicado::Id_duplicado(const Cadena& s): id{s} {}

Cadena Usuario::Id_duplicado::idd() const
{
    return id;
}

//Operators
ostream& operator <<(ostream& os, const Usuario& u)
{
    os << u.id() << " [" << u.pass().clave() << "] " << 
    u.nombre() << ' ' << u.apellidos() << '\n' << u.direccion()
    << "\nTarjetas:\n";

    for(auto it : u.tarjetas())
        os << *it.second << '\n';
    
    return os;
}

void mostrar_carro(ostream& os, const Usuario& u)
{
    setlocale(LC_ALL, "es_ES");

    os << "Carrito de la compra de " << u.id() << " [Artículos: " <<
    u.n_articulos() << "]\n";

    os << "Cant. Artículo\n";
    os <<
    "===========================================================\n";

    int cont = 1;

    for (auto i : u.compra())
    {
        os << cont << "    " << *i.first << "\n";
        ++cont;
    }
}