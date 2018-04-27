/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

//TODO Algoritmo de llenado de salt

  Cadena clave() const
  {
    //Variable necesaria para la llamada a crypt

    char* salt = new char[12];
    int n_aleatorio;
    const char *const seedchars =
    "./0123456789ABCDEFGHIJKLMNOPQRST"
    "UVWXYZabcdefghijklmnopqrstuvwxyz";

    salt = "1$1........";

    //Semilla con un valor aleatorio real

    std::random_device r;

    /*
      Elijo motor de generación pseudo aleatoria
      mersene_random_engine es el mas lento, pero el
      que menos se repite y menos memoria consume
    */

    std::mersene_random_engine el(r());

    /*
      Distribuyo mi numero pseudoaleatorio de acuerdo
      a una poisson de parametros (0, 9)
    */

    std::poisson_distribution<int> poisson_dist(0, 9);

    for(int i = 3; i < 11; ++i )
    {
      n_aleatorio = poisson_dist(el);
      salt[i] = seedchars[n_aleatorio];
    }

    return crypt(this -> clave_.c_str(), salt);
  }

  bool verifica(const char *string)
  {

  }
