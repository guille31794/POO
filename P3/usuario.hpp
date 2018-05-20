/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */
  #ifndef Usuario_hpp
  #define Usuario_hpp
  #include "cadena.hpp"
  #include "tarjeta.hpp"
  #include "articulo.hpp"

  #include <locale>
  #include <unordered_map>
  #include <unordered_set>
  #include <map>
  #include <random>
  #include "unistd.h"

  using namespace std;

  class Tarjeta;
  class Numero;

  class Clave
  {
    private:
      Cadena clave_;

    public:
      Clave(const char*);

      //¿Necesaria la clase?

      //TODO

      enum Razon { CORTA, ERROR_CRYPT};

      class Incorrecta
      {
        private:

          Razon r_;

        public:
          Incorrecta(Razon r): r_{r}
          {}
          Razon razon() const  { return this -> r_; }

      };

      Cadena clave() const { return this -> clave_;}
      bool verifica(const char *) const;
      Cadena cifrado(Cadena& );
    };


  class Usuario
  {
    public:

      typedef map<Numero, Tarjeta*> Tarjetas;
      typedef unordered_map<Articulo*, unsigned int> Articulos;
      typedef unordered_set<Cadena> Comprobador;
      explicit Usuario(const Cadena&, const Cadena&,
      const Cadena&, const Cadena&, const Clave& );

      Usuario(const Usuario&) = delete;
      Usuario operator =(const Usuario&) = delete;

      class Id_duplicado
      {
        private:

          char* idd_;

        public:

           Id_duplicado(const Cadena& id):
           idd_{}
           {
             idd_ = new char[id.length()];
             strcpy(idd_, id.c_str());
           }
           char* const idd() const  { return this -> idd_;}
      };

      void es_titular_de(Tarjeta &);
      void no_es_titular_de(Tarjeta &);

      Cadena id() const  { return this -> id_;}
      Cadena nombre() const  { return this -> nombre_;}
      Cadena apellidos() const { return this -> apellidos_;}
      Cadena direccion() const { return this -> direccion_;}
      const Cadena clave() const
      { return this -> clave_.clave();}

      const Tarjetas& tarjetas() const { return this -> tarjetas_;}
      void compra(Articulo&, unsigned cant = 1);
      const Articulos& compra() const { return this -> articulos_;}
      size_t n_articulos() const { return this -> articulos_.size();}

      ~Usuario();

    private:
      Cadena id_, nombre_, apellidos_, direccion_;
      const Clave clave_;
      Tarjetas tarjetas_;
      Articulos articulos_;
  };

  std::basic_ostream<char>& operator <<
    (std::basic_ostream<char>& os, const Usuario&);
  void mostrar_carro(std::basic_ostream<char>&, const Usuario&);

#endif
