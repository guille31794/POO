#ifndef Usuario_Pedido_hpp
#define Usuario_Pedido_hpp

#include <map>
#include <set>
#include <utility>
#include "usuario.hpp"
#include "pedido.hpp"

using namespace std;

class Pedido;
class Usuario;

class Usuario_Pedido
{
    public:
        typedef set<Pedido*> Pedidos;
        typedef map<Usuario*, Pedidos> Usuarios;
        void asocia(Usuario&, Pedido&);
        void asocia(Pedido&, Usuario&);
        Pedidos pedidos(Usuario&) const;
        const Usuario* cliente(const Pedido&) const;
    private:
        Pedidos pedidos_;
        Usuarios usuarios;
};

#endif