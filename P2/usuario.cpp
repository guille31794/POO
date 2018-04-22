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
      bool bolean;
      std::pair <auto, bool> par;

      par = tarjetas_.insert(t);
      boolean = par.second;

      if (!b)
        throw //TODO algun tipo de excepcion ;
    }

    void no_es_titular_de(Tarjeta &t)
    {
      //TODO
    }
