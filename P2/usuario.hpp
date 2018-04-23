/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "cadena.hpp"
  #include "tarjeta.hpp"
  #include "articulo.hpp"
  #include <unordered_map>
  #include "utility"
  #include <map>

  using namespace std;

  class Usuario
  {
    private:
      Cadena id_, nombre_, apellidos_, direccion_;
      Clave contraseña_;
      Tarjetas tarjetas_;
      unordered_map<Articulo*, unsigned int> articulos_;

      /*
        TODO ¿Funcionaría con char* en lugar de Cadena?
      */

      static unordered_set<Cadena*> comprobador;

    public:

      map<Numero, Tarjeta*> Tarjetas;
      explicit Usuario(const Cadena&, const Cadena&,
      const Cadena&, const Cadena&, const Clave& );

      class Id_duplicado
      {
        private:
          char* idd_;

        public:
          inline Id_duplicado(const Cadena& id):
          idd{id.c_str()}
          {}
          inline char* const idd() const
          { return this -> idd_;}
      }
      /*
        TODO dudas descritas abajo
        ¿Que hacer con el cosntructor de copia y asignacion?
        ¿Prohibirlos? ¿Declararlos con excepcion unicamente?
      */

      inline explicit Usuario(const Usuario&):
      {
        throw Id_duplicado((const char*)
        "Error. No puede duplicar un usuario.\n");
      }

      inline Usuario operator =(const Usuario&)
      {
        throw Id_duplicado((const char*)
        "Error. No puede duplicar un usuario.\n");
      }

      void es_titular_de(Tarjeta &);
      void no_es_titular_de(Tarjeta &);

      inline Cadena id() const  { return this -> id_;}
      inline Cadena nombre() const  { return this -> nombre_;}
      inline Cadena apellidos() const
      { return this -> apellidos_;}
      inline Cadena direccion() const
      { return this -> direccion_;}

      /*
        TODO Aqui hay fallo seguro. Aprender a manejar mapas.
      */

      inline const Tarjeta& tarjetas() const
      { return this -> tarjetas_;}
      void compra(Articulo&, unsigned cant = 1);
      const Articulo& compra() const;
      size_t n_articulos() const;

      ~Usuario();
  }
