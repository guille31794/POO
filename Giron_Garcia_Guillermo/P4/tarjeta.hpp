#ifndef Tarjeta__HPP__
#define Tarjeta__HPP__

#include "fecha.hpp"
#include "cadena.hpp"
#include "usuario.hpp"
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;

bool luhn(const Cadena& numero);
class Usuario;

class EsBlanco
{
    public:
    bool operator ()(char c);
};

class EsDigito
{
    public:
    bool operator ()(char c);
};

class Numero
{
    public:
        //Constructor
        Numero(const Cadena&);

        //Operator
        operator const char*() const;

        //Exception stuff
        enum Razon{LONGITUD, DIGITOS, NO_VALIDO};

        class Incorrecto
        {
            public:
                Incorrecto(const Razon);
                Razon razon() const;
            private:
                Razon r_;
        };
    private:
        Cadena num;
};

bool operator <(const Numero& n1, const Numero& n2);

class Tarjeta
{
    public:
        enum Tipo{Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress};

        //Constructor
        explicit Tarjeta(const Numero &, Usuario &, const Fecha &);
        Tarjeta(const Tarjeta&) = delete;
        Tarjeta& operator =(const Tarjeta&) = delete;

        //Getters
        const Tipo tipo() const;
        const Numero numero() const;
        const Usuario* titular() const;
        const Fecha caducidad() const;
        const Cadena titular_facial() const;
        const bool activa() const;

        //Setters
        bool activa(const bool = true);
        void anula_titular();

        //Destructor
        ~Tarjeta();

        //Exception stuff
        class Caducada
        {
            public:
                Caducada(const Fecha&);
                Fecha cuando() const;
            private:
                Fecha d;
        };

        class Num_duplicado
        {
            public:
                Num_duplicado(const Numero &);
                Numero que() const;
            private:
                Numero n;
        };

        class Desactivada{};
    private:
        Tipo type;
        Numero number;
        Usuario* user;
        Fecha date;
        Cadena titular_facial_;
        bool active;
        static set<Numero> Numbers;
};

//Operators
ostream& operator <<(ostream&, Tarjeta::Tipo);
ostream& operator <<(ostream&, const Tarjeta&);
bool operator <(const Tarjeta&, const Tarjeta&);
bool operator ==(const Numero&, const Numero&);

#endif