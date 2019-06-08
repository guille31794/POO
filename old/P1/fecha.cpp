//
//  Fecha.cpp
//  Fecha
//
//  Created by Guillermo Girón García on 7/3/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//


#include "fecha.hpp"

const int Fecha::AnnoMinimo = 1902;
const int Fecha::AnnoMaximo = 2037;

//Constructores

Fecha::Fecha(int d, int m, int a): day(d), month(m), year(a)
{
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);

    mktime(tiempo_descompuesto);
    if(year == 0)
        year = tiempo_descompuesto -> tm_year + 1900;

    if(day == 0)
        day = tiempo_descompuesto -> tm_mday;

    if(month == 0)
        month = tiempo_descompuesto -> tm_mon + 1;

    compruebaFecha();
};


Fecha::Fecha(int d, int m): day{d}, month{m}, year{}
{
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);

    mktime(tiempo_descompuesto);

    year = tiempo_descompuesto -> tm_year + 1900;

    if(day == 0)
        day = tiempo_descompuesto -> tm_mday;

    if(month == 0)
        month = tiempo_descompuesto -> tm_mon + 1;

    compruebaFecha();
};


Fecha::Fecha(int d): day{d}, month{}, year{}
{
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);

    mktime(tiempo_descompuesto);

    year = tiempo_descompuesto -> tm_year + 1900;
    month = tiempo_descompuesto -> tm_mon + 1;

    if(day == 0)
        day = tiempo_descompuesto -> tm_mday;

    CompruebadaysDelmonth();
}


Fecha::Fecha(): day{}, month{}, year{}
{
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);

    mktime(tiempo_descompuesto);

    year = tiempo_descompuesto -> tm_year + 1900;
    month = tiempo_descompuesto -> tm_mon + 1;
    day = tiempo_descompuesto -> tm_mday;
}

Fecha::Fecha(const char *s):
day{}, month{}, year{}
{
    int d, m, a, formato;
    time_t tiempo_calendario;
    tm* tiempo_descompuesto;

    formato = sscanf(s, "%d/%d/%d", &d, &m, &a);

    if(formato != 3)
    {
        throw Invalida((char*)"Formato de fecha incorrecto");
    }
    else
    {
        this -> day = d;
        this -> month = m;
        this -> year = a;
    }

    tiempo_calendario = time(nullptr);
    tiempo_descompuesto = localtime(&tiempo_calendario);

    mktime(tiempo_descompuesto);

    if(year == 0)
        year = tiempo_descompuesto -> tm_year + 1900;

    if(day == 0)
        day = tiempo_descompuesto -> tm_mday;

    if(month == 0)
        month = tiempo_descompuesto -> tm_mon + 1;

    compruebaFecha();
}

//Sobrecarga de operadores aritmeticos

Fecha& Fecha::operator +=(int n)
{
    tm tiempoInfo = {0};

    tiempoInfo.tm_mday = this -> day + n;
    tiempoInfo.tm_mon = this -> month - 1;
    tiempoInfo.tm_year = this -> year - 1900;
    tiempoInfo.tm_isdst --;

    mktime(&tiempoInfo);

    this -> day = tiempoInfo.tm_mday;
    this -> month = tiempoInfo.tm_mon + 1 ;
    this -> year = tiempoInfo.tm_year + 1900;

    compruebaFecha();
    return *this;
}

//Sobrecarga de operadores de comparacion

bool operator ==(const Fecha &f1, const Fecha &f2)
{
    bool v;

    v = (f1.dia() == f2.dia()) &&
    (f1.mes() == f2.mes()) &&
    (f1.anno() == f2.anno());

    return v;
}
bool operator ==(const Fecha &f1, const char* string)
{
  bool iguales;
  Fecha f2(string);

  iguales = (f1.dia() == f2.dia()) &&
  (f1.mes() == f2.mes()) &&
  (f1.anno() == f2.anno());

  return iguales;
}

bool operator ==(const char* string, const Fecha &f1)
{
  bool iguales;
  Fecha f2(string);

  iguales = (f1.dia() == f2.dia()) &&
  (f1.mes() == f2.mes()) &&
  (f1.anno() == f2.anno());

  return iguales;
}

bool operator <(const Fecha &f1, const Fecha &f2)
{
    bool v;

    v = (f1.anno() < f2.anno());

    if(!v)
        v = (f1.mes() < f2.mes()) &&
        (f1.anno() <= f2.anno());

    if(!v)
        v = (f1.dia() < f2.dia()) &&
        (f1.mes() <= f2.mes()) &&
        (f1.anno() <= f2.anno());

    return v;
}

bool operator <(const Fecha &f1, const char* string)
{
    bool v;
    Fecha f2(string);

    v = (f1.anno() < f2.anno());

    if(!v)
        v = (f1.mes() < f2.mes()) &&
        (f1.anno() <= f2.anno());

    if(!v)
        v = (f1.dia() < f2.dia()) &&
        (f1.mes() <= f2.mes()) &&
        (f1.anno() <= f2.anno());

    return v;
}
bool operator <(const char* string, const Fecha&f2)
{
    bool v;
    Fecha f1(string);

    v = (f1.anno() < f2.anno());

    if(!v)
        v = (f1.mes() < f2.mes()) &&
        (f1.anno() <= f2.anno());

    if(!v)
        v = (f1.dia() < f2.dia()) &&
        (f1.mes() <= f2.mes()) &&
        (f1.anno() <= f2.anno());

    return v;
}

//Constructor de la excepcion

Fecha::Invalida::Invalida(const char *e):
string{e}
{}

//Comprobador de excepciones

void Fecha::compruebaFecha()
{
    if( this->year < AnnoMinimo || this->year > AnnoMaximo)
        throw Invalida((char*)"Año fuera de rango");

    if (this->month < 1 || this->month > 12)
        throw Invalida((const char*)"month fuera de rango");

    bisiesto();
    CompruebadaysDelmonth();

}

void Fecha::bisiesto()
{
    int a;

    a = this -> year;

    if (this->month == 2)
    {
        if (a % 4 == 0 && (a % 400 == 0 || a % 100 != 0))
        {
            if (this -> day < 1 || this -> day > 29)
            {
                throw Invalida((const char*)"Año bisiesto, febrero fuera de rango");
            }
        }
        else
        {
            if (this -> day < 1 || this -> day > 28)
            {
                throw Invalida((const char*)"Año no bisiesto, febrero fuera de rango");
            }
        }
    }
}

void Fecha::CompruebadaysDelmonth()
{
    if(this -> month == 1 || this -> month == 3
       || this -> month == 5 || this -> month == 7
       || this -> month == 8 || this -> month == 10
       || this -> month == 12)
    {
        if(this -> day < 1 || this -> day > 31)
            throw Invalida((const char*)"days del month fuera del rango");
    }
    else
    {
        if (this -> day < 1 || this -> day > 30)
        {
            throw Invalida((const char*)"days del month fuera del rango");
        }
    }
}

//Sobrecarga de operador de flujos

 ostream& operator << (ostream& os, const Fecha& f)
{
    setlocale(LC_ALL, "es_ES");
    return os << f.cadena();
}

istream& operator >> (istream& is, Fecha& f)
{
    char* string = new char[11];

    is.getline(string, 11);

    try
    {
        f = Fecha(string);
    }   catch(Fecha::Invalida &f)
    {
        is.setstate(std::ios_base::failbit);
        throw f;
    }

    return is;
}

const char* Fecha::cadena() const noexcept
{
  setlocale(LC_ALL, "es_ES");

  tm tiempo_descompuesto = {0};
  static char *fecha = new char[250];

  tiempo_descompuesto.tm_mday = this -> day;
  tiempo_descompuesto.tm_mon = this -> month - 1;
  tiempo_descompuesto.tm_year = this -> year - 1900;
  tiempo_descompuesto.tm_isdst --;

  mktime(&tiempo_descompuesto);

  strftime(fecha, 100, "%A %d de %B de %Y", &tiempo_descompuesto);

  return fecha;
}
