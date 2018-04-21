/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "cadena.hpp"

  class Clave
  {
    private:
      Cadena clave_;

    public:
      Clave(const char*);

      class Incorrecta
      {
        private:
          const enum Razon { CORTA, ERROR_CRYPT};

        public:
          inline const char* razon()  { return Razon;}

      };

      Cadena clave() const;
      bool verifica(const char *);
  };
