/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  class Numero {
  private:
    Cadena numero_;

  public:
    operator const char*() const;
  };
