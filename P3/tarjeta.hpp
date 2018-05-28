/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #ifndef Tarjeta_hpp
  #define Tarjeta_hpp
  #include "fecha.hpp"
  #include "cadena.hpp"
  #include "usuario.hpp"
  #include "../luhn.hpp"
  #include <functional>
  #include <iomanip>
  #include <iostream>
  #include <cctype>
  #include <utility>
  #include <algorithm>

  using namespace std;

  class Usuario;

  class EsBlanco
  {
    public:
      bool operator ()(char c)  { return isspace(c); }
  };

  class EsDigito
  {
    public:
      bool operator()(char c) { return !isalpha(c); }
  };

  class Numero
  {
    private:

      Cadena numero_;

    public:

      enum Razon {LONGITUD, DIGITOS, NO_VALIDO};
      Numero(Cadena);
      operator const char*() const { return this -> numero_.c_str();}
      friend inline bool operator <(const Numero& n1, const Numero& n2)
      {
        return n1.numero_ < n2.numero_;
      }

      class Incorrecto
      {
        private:

          Razon r;

        public:

          Incorrecto(const Razon r_): r{r_} {}
          Razon razon() const { return this -> r;}
      };
  };


  class Tarjeta
  {
    public:

      enum Tipo {VISA, Mastercard, Maestro, JCB, AmericanExpress};

      explicit Tarjeta
      (const Tipo, const Numero&, Usuario&, const Fecha&);
      Tarjeta(const Tarjeta&) = delete;
      Tarjeta& operator =(const Tarjeta&) = delete;

      Tipo tipo() const { return this -> tipo_;}
      Numero numero() const { return this -> numero_;}
      Fecha caducidad() const  { return this -> caducidad_;}
      Cadena titular_facial() const  { return this -> titular_facial_;}
      const Usuario* titular() const  { return this -> titular_;}
      void anula_titular()  { this -> titular_ = nullptr;}
      ~Tarjeta();

      class Caducada
      {
        public:
           Caducada(const Fecha& f):  caducada_{f}
          {}
           Fecha cuando() const { return this -> caducada_;}

        private:
          Fecha caducada_;
      };

    private:
      Tipo tipo_;
      Numero numero_;
      const Usuario* titular_; //Enlace con titular
      Fecha caducidad_;
      Cadena titular_facial_;
  };

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>& os, const Tarjeta& t);

inline bool operator < (const Tarjeta& t1, const Tarjeta& t2)
{ return t1.numero() < t2.numero(); }

#endif
