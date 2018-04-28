/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */
  #ifndef Clave_hpp
  #define Clave_hpp
  #include "cadena.hpp"
  #include "unistd.h"
  #include <ctime>
  #include <random>

  class Clave
  {
    private:
      Cadena clave_;

    public:
      Clave(const char*);

      class Incorrecta
      {
        private:

          //¿Necesario el const en la enumeracion?
          //¿Necesaria la clase?
          //¿Necesario el tipo?
          //Metodo sin argumentos ¿Que valor toma r?
          //¿Necesario r?
          //¿r tiene valor por defecto al declararlo?
          //¿Necesaria asignacion?
          //TODO dudas descritas arriba

          enum class Razon { CORTA, ERROR_CRYPT};
          Razon r;

        public:
          Incorrecta();
          inline Razon razon() const  { return this -> r; }

      };

      inline Cadena clave() const { return this -> clave_;}
      bool verifica(const char *);
  };

#endif
