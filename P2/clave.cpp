#include "clave.hpp"

//Constructor
Clave::Clave(const char* s): key{strlen(s)}
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

    std::uniform_int_distribution<int> u_dist{0, strlen(seedchars) - 1};

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