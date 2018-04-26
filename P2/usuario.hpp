/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */
  #ifndef Usuario_hpp
  #define Usuario_hpp
  #include "cadena.hpp"
  #include "tarjeta.hpp"
  #include "articulo.hpp"
  #include "clave.hpp"
  #include <unordered_map>
  #include <unordered_set>
  #include "utility"
  #include <map>

  using namespace std;

  class Usuario
  {
    public:

      typedef map<Numero, Tarjeta*> Tarjetas;
      typedef unordered_map<Articulo*, unsigned int> Articulos;
      explicit Usuario(const Cadena&, const Cadena&,
      const Cadena&, const Cadena&, const Clave& );

      Usuario(const Usuario&) = delete;
      Usuario operator =(const Usuario&) = delete;

      class Id_duplicado
      {
        private:

          char* idd_;

        public:

          inline Id_duplicado(const Cadena& id):
          idd_{id.c_str()}
          {}
          inline char* const idd() const  { return this -> idd_;}
      };

      void es_titular_de(Tarjeta &);
      void no_es_titular_de(Tarjeta &);

      inline Cadena id() const  { return this -> id_;}
      inline Cadena nombre() const  { return this -> nombre_;}
      inline Cadena apellidos() const { return this -> apellidos_;}
      inline Cadena direccion() const { return this -> direccion_;}
      inline const Cadena clave() const
      { return this -> clave_.clave();}

      inline const Tarjetas& tarjetas() const { return this -> tarjetas_;}
      void compra(Articulo&, unsigned cant = 1);
      inline const Articulos& compra() const { return this -> articulos_;}
      inline size_t n_articulos() const { return this -> articulos_.size();}

      ~Usuario();

    private:
      Cadena id_, nombre_, apellidos_, direccion_;
      const Clave clave_;
      Tarjetas tarjetas_;
      Articulos articulos_;

      /*
        TODO ¿Funcionaría con char* en lugar de Cadena?
      */

      static unordered_set<Cadena*> comprobador;
  };

  std::basic_ostream<char>& operator <<
    (std::basic_ostream<char>& os, const Usuario&);
  std::basic_ostream<char>& mostrar_carro(std::basic_ostream<char>&,
    const Usuario&);

#endif
