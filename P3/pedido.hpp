#include "fecha.hpp"
#include "tarjeta.hpp"

class Pedido
{
    public:
        Pedido();

    private:
        unsigned num, totalPrize, lastBuyNumber, buysQuantity;
        const Tarjeta* card;
        Fecha date;
};

