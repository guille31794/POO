#ifndef Usuario_Pedido_hpp
#define Usuario_Pedido_hpp

#include <map>
#include "pedido.hpp"
#include "usuario.hpp"

using namespace std;

class Usuario_Pedido
{
    public:
        typedef set<Pedido*> Pedidos;
        void asocia(const Usuario&, const Pedido&);
        void asocia(const Pedido&, const Usuario&);
        Pedidos pedidos(const Usuario&) const;
        const Usuario& cliente(const Pedido&) const;
    private:
        map<Usuario*, Pedidos> DA;
        map<Pedido*, Usuario*> IA;
};

#endif