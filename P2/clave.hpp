/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

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

          //Consultar con Pedro o Jose Fidel
          //¿Necesario el const en la enumeracion?
          //¿Necesaria la clase?
          //¿Necesario el tipo?
          //Metodo sin argumentos ¿Que valor toma r?
          //¿Necesario r?
          //¿r tiene valor por defecto al declararlo?
          //¿Necesaria asignacion?
          //TODO:

          const enum class Razon :char* { CORTA, ERROR_CRYPT};
          Razon r;

        public:
          inline const char* razon() const
          { return this -> r; }

      };

      Cadena clave() const;
      bool verifica(const char *);
  };
