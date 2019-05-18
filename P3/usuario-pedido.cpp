#include "usuario-pedido.hpp"

void Usuario_Pedido::asocia(Usuario& u, Pedido& p)
{
    pedidos_.insert(&p);
    Usuarios::iterator it = usuarios.find(&u);

    if(it != usuarios.end())
        it -> second.insert(&p);
    else
    {   Pedidos pedidos;
        pedidos.insert(&p);
        usuarios.insert(make_pair(&u, pedidos));
    }
    
}

void Usuario_Pedido::asocia(Pedido& p, Usuario& u)
{
    asocia(u, p);
}

Usuario_Pedido::Pedidos Usuario_Pedido::pedidos(Usuario& u) const
{   
    return usuarios.find(&u)->second;
}

const Usuario* Usuario_Pedido::cliente(const Pedido& p) const
{
    return p.tarjeta() -> titular();
}