/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "usuario.hpp"

  Usuario::Usuario(const Cadena& id, const Cadena& nombre,
    const Cadena& apellidos, const Cadena& direccion,
    const Clave& clave):
    id_{id}, nombre_{nombre}, apellidos_{apellidos},
    direccion_{dirección}, contraseña_{clave}
    {
      bool bolean;
      std::pair <auto, bool> par;

      par = comprobador.insert(id);
      boolean = par.second;

      if (!b)
        throw Id_duplicado(this -> id_);
    }

    void es_titular_de(Tarjeta &t)
    {
      /*
      bool bolean;
      std::pair <auto, bool> par;

      par = tarjetas_.insert(t);
      boolean = par.second;

      if (!b)
        throw algun tipo de excepcion ;
      */

      tarjetas_.insert(t);
    }

    void no_es_titular_de(Tarjeta &t)
    {
      this -> tarjetas_.erase(t);
    }

    void compra(Articulo& ar, unsigned cant /*= 1*/)
    {
      if(!cant)
        articulos_.erase(ar);
      else
      {
        articulos_.erase(ar);
        articulos_.insert(make_pair(ar, cant));
      }
    }

    Usuario::~Usuario()
    {
      for (auto i = tarjetas_.begin(); i < tarjetas_.end(); i++)
      {
        tarjetas_[i] -> Tarjeta::anular_titular();
      }
    }

    std::basic_ostream<char>& operator <<
    (std::basic_ostream<char>& os, const Usuario& u)
    {
      os << u.id() << " [" << u.clave() << "] " << u.nombre() << ' ' <<
      u.apellidos() << '\n' << u.direccion() << '\n' << "Tarjetas:" <<
      '\n' << u.tarjetas() << endl;

      return os;
    }

    std::basic_ostream<char>& mostrar_carro
      (std::basic_ostream<char>& os, const Usuario& u)
    {
      os << "Carrito de la compra de " << u.id() << " [Articulos: " <<
      u.compra().size() << ']' << '\n' << ;
      for (auto i = u.compra().cbegin(); i < u.compra().cend(); i++)
      {
        os <<
      }

      return os;
    }
