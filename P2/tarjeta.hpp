#ifndef Tarjeta__HPP__
#define Tarjeta__HPP__

#include "numero.hpp"
#include "fecha.hpp"

using namespace std;

class Usuario;

class Tarjeta
{
    public:
        enum Tipo{Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress};

        //Constructor
        Tarjeta(const Numero&, Usuario&, const Fecha&);
        Tarjeta(const Tarjeta&) = delete;
        Tarjeta& operator =(const Tarjeta&) = delete;

        //Getters
        Tipo tipo() const;
        Numero numero() const;
        Usuario* titular() const;
        Fecha caducidad() const;
        bool activa() const;

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

        class Num_Duplicado
        {
            public:
                Num_Duplicado(const Numero&);
                Numero que() const;
            private:
                Numero n;
        };

        class Desactivada
        {

        };
    private:
        Tipo type;
        Numero number;
        Usuario* user;
        Fecha date;
        bool active;
};

//Operators
ostream& operator <<(ostream&, const Tarjeta&);
bool operator <(const Tarjeta&, const Tarjeta&);

#endif