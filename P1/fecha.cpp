#include "fecha.hpp"

//Const deffinitions
const unsigned Fecha::AnnoMaximo{2037};
const unsigned Fecha::AnnoMinimo{1902};

//Constructors

Fecha::Fecha(const unsigned d, const unsigned m, const unsigned y):
day_{d}, month_{m}, year_{y}
{
        time_t ti = time(nullptr);
        tm* date = localtime(&ti);
        mktime(date);

        if(day_ == 0)
            day_ = date -> tm_mday;

        if (month_ == 0) 
            month_ = date -> tm_mon + 1;

        if(year_ == 0)
            year_ = date -> tm_year + 1900;
        
        if(AnnoMaximo < year_ || AnnoMinimo > year_)
            throw Fecha::Invalida("Año fuera de rango.");
        if (month_ < 1 || month_ > 12)
            throw Fecha::Invalida("Mes fuera de rango.");
        if(day_ < 1)
            throw Fecha::Invalida("Dia fuera de rango.");       
        if (month_ == 2)
        {
            if(bisiesto() && day_ > 29) 
                throw Fecha::Invalida("Dia fuera de rango.");
            else if(day_ > 28) 
                {   throw Fecha::Invalida("Dia fuera de rango.");   }
        }
        else if(month_ <= 7)
            {
                if(month_ % 2 == 0 && day_ > 30)
                    throw Fecha::Invalida("Dia fuera de rango.");
                else if(day_ > 31)
                    {   throw Fecha::Invalida("Dia fuera de rango.");   }
            }
}

Fecha::Fecha(const char* s)
{
    unsigned d, m, a, format;
    time_t date;
    tm* tim;

    format = sscanf(s, "%d/%d/%d", &d, &m, &a);

    if(format != 3)
        throw Invalida((char*)"Incorrect date format");
    else
    {
        this -> day_ = d;
        this -> month_ = m;
        this -> year_ = a;
    }

    date = time(nullptr);
    tim = localtime(&date);

    mktime(tim);

    if(year_ == 0)
        year_ = tim -> tm_year + 1900;

    if(day_ == 0)
        day_ = tim -> tm_mday;

    if(month_ == 0)
        month_ = tim -> tm_mon + 1;

    //Check date

    if(AnnoMaximo < year_ || AnnoMinimo > year_)
            throw Fecha::Invalida("Out of range year");
        if (month_ < 1 || month_ > 12)
            throw Fecha::Invalida("Out of range month");
        if(day_ < 1)
            throw Fecha::Invalida("Out of range day");       
        if (month_ == 2)
        {
            if(bisiesto() && day_ > 29) 
                throw Fecha::Invalida("Dia fuera de rango.");
            else if(day_ > 28) 
                {   throw Fecha::Invalida("Dia fuera de rango.");   }
        }
        else if(month_ <= 7)
            {
                if(month_ % 2 == 0 && day_ > 30)
                    throw Fecha::Invalida("Dia fuera de rango.");
                else if(day_ > 31)
                    {   throw Fecha::Invalida("Dia fuera de rango.");   }
            }
}

Fecha::Invalida::Invalida(const char* s): error{new char[strlen(s)+1]}
{
    strcpy(error, s);
}

//Operators

Fecha& Fecha::operator +=(int n)
{
    tm local{0};

    local.tm_mday = this -> day_ + n;
    local.tm_mon = this -> month_ - 1;
    local.tm_year = this -> year_ - 1900;

    mktime(&local);

    this -> day_ = local.tm_mday;
    this -> month_ = local.tm_mon + 1;
    this -> year_ = local.tm_year + 1900;

    if(year_ > Fecha::AnnoMaximo || year_ < Fecha::AnnoMinimo)
        throw Fecha::Invalida("Out of range year");
    
    return *this;
}

Fecha& Fecha::operator -=(int n)
{
    return *this += -n;
}

Fecha& Fecha::operator ++()
{
    return *this += 1;
}

Fecha& Fecha::operator --()
{
    return *this += -1; 
}

Fecha Fecha::operator ++(const int n)
{
    Fecha t(*this);
    *this += 1;
    return t; 
}

Fecha Fecha::operator --(const int n)
{
    Fecha t(*this);
    *this += -1;
    return t; 
}

Fecha operator +(Fecha& f, const unsigned n)
{
    Fecha f2{f};
    return f2 += n;
}

Fecha operator +(const unsigned n, Fecha& f)
{
    return f + n;
}

Fecha operator -(Fecha& f, const unsigned n)
{
    return f -= n;
}

Fecha operator -(const unsigned n, Fecha& f)
{
    return f -= n;
}

bool operator <(const Fecha& f1, const Fecha& f2)
{
    tm* d1;
    tm* d2;

    d1 -> tm_mday = f1.dia();
    d1 -> tm_mon = f1.mes() - 1;
    d1 -> tm_year = f1.anno() - 1900;
    d2 -> tm_mday = f1.dia();
    d2 -> tm_mon = f1.mes() - 1;
    d2 -> tm_year = f1.anno() - 1900;
        
    return mktime(d1) < mktime(d2); //mktime returns time_t type that is an alias from primitive c++ types
}

bool operator >(const Fecha& f1, const Fecha& f2)
{
    return f2 < f1; 
}

bool operator ==(const Fecha& f1, const Fecha& f2)
{
    return (f1.dia() == f2.dia()) && (f1.mes() == f2.mes()) && (f1.anno() == f2.anno());
}

bool operator <=(const Fecha& f1, const Fecha& f2)
{
    return f1 < f2 || f1 == f2;
}

bool operator >=(const Fecha& f1, const Fecha& f2)
{
    return f1 > f2 || f1 == f2;
}

bool operator !=(const Fecha& f1, const Fecha& f2)
{
    return !(f1 == f2);
}

const char* Fecha::cadena() const
{
    setlocale(LC_ALL, "es_ES");

    tm time{0};
    char* date{new char[250]};

    time.tm_mday = this -> day_;
    time.tm_mon = this -> month_ - 1;
    time.tm_year = this -> year_ - 1900;

    mktime(&time);

    strftime(date, 250, "%A %d de %B de %Y", &time);

    Cadena str{date};
    delete[] date;

    return str.c_str();
}

Fecha Fecha::operator=(const Fecha& f)
{
    day_ = f.day_;
    month_ = f.month_;
    year_ = f.year_;

    return *this;
}

ostream& operator <<(ostream& os, const Fecha& f)
{
    return os << f.cadena();
}

istream& operator >>(istream& is, Fecha& f)
{
    char* string = new char[11];

    is.getline(string, 11);

    try
    {
        f = Fecha{string};
    }   catch(Fecha::Invalida &f)
    {
        is.setstate(std::ios_base::failbit);
        throw f;
    }

    delete[] string;

    return is;
}

//Getters

int Fecha::dia() const
{
    return day_;
}

int Fecha::mes() const
{
    return month_;
}

int Fecha::anno() const
{
    return year_;
}

const char* Fecha::Invalida::por_que() const
{
    return error;
}

const bool Fecha::bisiesto() const
{
    return year_ % 4 == 0 && (year_ % 400 == 0 || year_ % 100 != 0);
}