/*
  Creado por Guillermo Girón García para la asignatura
  POO de la UCA.

  21/04/2018, GPL Licensed, all rights reserved */

  #include "usuario.hpp"

  Usuario::Comprobador comprobador;

  Clave::Clave(const char* clave):
  clave_{clave}
  {
    if(this -> clave_.length() < 5)
      throw Incorrecta(CORTA);

    this -> clave_ = cifrado(this -> clave_);
  }

Cadena Clave::cifrado(Cadena& c)
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
  */

  std::default_random_engine el(r());

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

  cifrada = crypt(c.c_str(), salt);

  if(c.c_str() == cifrada)
    throw Incorrecta(ERROR_CRYPT);
  else
    c = cifrada;

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


  Usuario::Usuario(const Cadena& id, const Cadena& nombre,
    const Cadena& apellidos, const Cadena& direccion,
    const Clave& clave):
    id_{id}, nombre_{nombre}, apellidos_{apellidos},
    direccion_{direccion}, clave_{clave}
    {
      bool insertado;
      std::pair <Comprobador::iterator, bool> par;

      par = comprobador.insert(id);
      insertado = par.second;

      if (!insertado)
        throw Id_duplicado(this -> id());
    }

    void Usuario::es_titular_de(Tarjeta &t)
    {
      tarjetas_.insert(make_pair(t.numero(), &t));
    }

    void Usuario::no_es_titular_de(Tarjeta &t)
    {
      this -> tarjetas_.erase(t.numero());
    }

    void Usuario::compra(Articulo& ar, unsigned cant /*= 1*/)
    {
      if(!cant)
        articulos_.erase(&ar);
      else
      {
        articulos_.erase(&ar);
        articulos_.insert(make_pair(&ar, cant));
      }
    }

    Usuario::~Usuario()
    {
      for (auto i = tarjetas_.begin(); i != tarjetas_.end(); i++)
      {
        i -> second -> anula_titular();
      }

      comprobador.erase(this -> id());

    }

    std::basic_ostream<char>& operator <<
    (std::basic_ostream<char>& os, const Usuario& u)
    {
      os << u.id() << " [" << u.clave() << "] " << u.nombre() << ' ' <<
      u.apellidos() << '\n' << u.direccion() << '\n' << "Tarjetas:" <<
      '\n';

      for(auto i = u.tarjetas().begin(); i != u.tarjetas().end(); ++i)
        os << i -> second << '\n';

      return os;
    }

    std::basic_ostream<char>& mostrar_carro
      (std::basic_ostream<char>& os, const Usuario& u)
    {
      char prev;
      int cont;

      prev = std::cout.fill('=');

      os << "Carrito de la compra de " << u.id() << " [Articulos: " <<
      u.compra().size() << ']' << '\n' << "\tCant. Artículo\n" <<
      "===========================================================";

      /*
      TODO sustituir esta funcion por la linea comentada
      std::cout.fill(prev);
      */

      cont = 1;

      for (auto i = u.compra().begin(); i != u.compra().end(); i++)
      {
        os << cont << '\t' << '[' << i -> first -> referencia()
        << "] " << '"' << i -> first -> titulo() << '"' <<
        ", " << i -> first -> f_publi().anno() << ". " <<
        i -> first -> precio() << " €\n";
      }

      return os;
    }
