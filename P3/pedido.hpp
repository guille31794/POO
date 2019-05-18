#ifndef Pedido_hpp
#define Pedido_hpp
#include "fecha.hpp"
#include "tarjeta.hpp"
#include "usuario.hpp"

class LineaPedido
{
    public:
        //Constructor
        explicit LineaPedido(const double, const unsigned = 1);
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
        Pedido(const Usuario_Pedido&, const Pedido_Articulo&, 
        const Usuario&, const Tarjeta&, const Fecha&);

        //Getters
        unsigned numero() const;
        const Tarjeta& tarjeta() const;
        Fecha fecha() const;
        double total() const;
        unsigned n_total_pedidos() const;

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
                SinStock(const Articulo&);
                const Articulo& articulo() const;
            private:
                const Articulo* a;
        };
        
    private:
        unsigned num, lastBuyNumber, buysQuantity;
        double totalPrize;
        const Tarjeta* card;
        Fecha date;
};

//Operators
ostream& operator <<(ostream&, const Pedido&);
ostream& operator <<(ostream&, const LineaPedido&);

#endif