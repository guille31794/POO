/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #ifndef Tarjeta_hpp
  #define Tarjeta_hpp
  #include "fecha.hpp"
  #include "cadena.hpp"
  #include "numero.hpp"
  #include "usuario.hpp"
  #include <iomanip>
  #include <iostream>

  class Tarjeta
  {
    public:
      enum Tipo {VISA, Mastercard, Maestro, JCB, AmericanExpress};
      explicit Tarjeta
      (const Tipo, const Numero&, Usuario&, const Fecha&);
      Tarjeta(const Tarjeta&) = delete;
      Tarjeta operator =(const Tarjeta&) = delete;
      inline Tipo tipo() const { return this -> tipo_;}
      inline Numero numero() const { return this -> numero_;}
      inline Fecha caducidad() const  { return this -> caducidad_;}
      inline Cadena titular_facial() const  { return this -> titular_facial_;}
      inline const Usuario* titular() const  { return this -> titular_;}
      //TODO linea 28, posible corrección sobre el puntero constante
      inline void anula_titular()  { this -> titular_ = nullptr;}
      ~Tarjeta();

      class Caducada
      {
        public:
          inline Caducada(const Fecha& f):  caducada_{f}
          {}
          inline Fecha cuando() { return this -> caducada_;}

        private:
          Fecha caducada_;
      };

    private:
      Numero numero_;
      const Usuario* titular_; //Enlace con titular
      Fecha caducidad_;
      Cadena titular_facial_;
      Tipo tipo_;
  };

std::basic_ostream<char>& operator <<
(std::basic_ostream<char>& os, const Tarjeta& t);
inline bool operator < (const Tarjeta& t1, const Tarjeta& t2)
{ return t1.numero() < t2.numero(); }

  #endif
