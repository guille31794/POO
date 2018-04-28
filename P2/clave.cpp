/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  Clave::Clave(const char* clave):
  clave_{clave}
  {
    if(this -> clave_.length() < 5)
      throw Incorrecta(CORTA);

    this -> clave_ = cifrado(this -> clave_);
  }

bool Clave::cifrado(Cadena& c)
{
  //Variable necesaria para la llamada a crypt

  char* cifrada = new char[20];
  char* salt = new char[2];
  int n_aleatorio;
  const char *const seedchars =
  "./0123456789ABCDEFGHIJKLMNOPQRST"
  "UVWXYZabcdefghijklmnopqrstuvwxyz";

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
    a una Distribucion uniforme de enteros de parametros (0, 64)
    que es nuestro rango de valores
  */

  std::uniform_int_distribution<int> u_dist(0, 64);

  for(int i = 0; i < 2; ++i )
  {
    n_aleatorio = u_dist(el);
    salt[i] = seedchars[n_aleatorio];
  }

  if(!(c = crypt(c.c_str(), salt)))
    throw Incorrecta(ERROR_CRYPT);

  return c;
}

  bool Clave::verifica(const char *string)
  {
    bool boolean;

    if (const char* const comprobador =
      crypt(string, this -> clave_.c_str()))
    {
        boolean = comprobador == clave_;
    }
    else
    {
      throw Incorrecta(ERROR_CRYPT);
    }

    return boolean;
  }
