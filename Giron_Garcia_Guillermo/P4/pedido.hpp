#ifndef Pedido_hpp
#define Pedido_hpp

#include <iostream>
#include <locale>
#include "fecha.hpp"
#include "cadena.hpp"
#include "usuario.hpp"
#include "tarjeta.hpp"
#include "articulo.hpp"
#include "pedido-articulo.hpp"
#include "usuario-pedido.hpp"

using namespace std;

class Usuario_Pedido;
class Pedido_Articulo;

class LineaPedido
{
    public:
        //Constructor
        explicit LineaPedido(double, unsigned = 1);
        //Getters
        double precio_venta() const;
        unsigned cantidad() const;
    private:
        double prize;
        unsigned quantity;
};

class Pedido
{
    public:
        //Constructor
        explicit Pedido(Usuario_Pedido&, Pedido_Articulo&, Usuario&, const Tarjeta*, 
        const Fecha& = Fecha{});

        //Getters
        unsigned numero() const;
        const Tarjeta* tarjeta() const;
        Fecha fecha() const;
        double total() const;
        static unsigned n_total_pedidos();

        //Exception Stuff
        class Vacio
        {
            public:
                Vacio(const Usuario&);
                const Usuario& usuario() const;
            private:
                const Usuario* uP;
        };

        class Impostor
        {
            public:
                Impostor(const Usuario&);
                const Usuario& usuario() const;
            private:
                const Usuario* uP;
        };

        class SinStock
        {
            public:
                SinStock(Articulo&);
                Articulo& articulo() const;
            private:
                Articulo* a;
        };
        
    private:
        unsigned num; 
        const Tarjeta* card;
        Fecha date;
        double totalPrize;
        static int buysQuantity;
};

//Operators
ostream& operator <<(ostream&, const Pedido&);
ostream& operator <<(ostream&, const LineaPedido&);

#endif