#include "fecha.hpp"

fecha::fecha(const unsigned d, const unsigned m, const y):
day_{d}, month_{m}, year_{y}
{
        if(AnnoMaximo < year_ || AnnoMinimo > year_)
            throw Fecha::Invalida("Año fuera de rango.");
        if (month_ < 1 || month_ > 12)
            throw Fecha::Invalida("Mes fuera de rango.");
        if(day_ < 1)
            throw Fecha::Invalida("Dia fuera de rango.");           
        if (month_ == 2)
            if(bisiesto() && day_ > 29) 
                throw Fecha::Invalida("Dia fuera de rango.");
            else if(day_ > 28) 
                throw Fecha::Invalida("Dia fuera de rango.");
        else if(month_ <= 7)
                if(month_ % 2 == 0 && day_ > 30)
                    throw Fecha::Invalida("Dia fuera de rango.");
                else if(day_ > 31)
                    throw Fecha::Invalida("Dia fuera de rango.");
}

fecha::Invalida::Invalida(): error{s}
{}

fecha fecha::operator +=(unsigned n)
{
    tm* local;

    local -> tm_mday = this.day_ + n;
    local -> tm_mon = this.month_ - 1;
    local -> tm_year = this.year_ - 1900;

    mktime(local);

    this.day_ = local -> tm_mday;
    this.month_ = local -> tm_month + 1;
    this.year_ = local -> tm_year + 1900;

    if(year_ > fecha::AnnoMaximo || year_ < fecha::AnnoMinimo)
        throw fecha::Invalida("Out of range year");
    else
        return *this;
}

fecha fecha::operator -=(unsigned n)
{
    return *this += -n;
}

fecha fecha::operator ++()
{
    return *this += 1;
}

fecha fecha::operator --()
{
    return *this += -1; 
}

fecha fecha::operator ++(const unsigned n)
{
    fecha t(*this);
    *this += 1;
    return t; 
}

fecha fecha::operator --(const unsigned n)
{
    fecha t(*this);
    *this += -1;
    return t; 
}

fecha operator +(const fecha& f, const unsigned n)
{
    return f += n;
}

fecha operator +(const unsigned n, const fecha& f)
{
    return f += n;
}

fecha operator -(const fecha& f, const unsigned n)
{
    return f -= n;
}

fecha operator -(const unsigned n, const fecha& f)
{
    return f -= n;
}

bool operator <(const Fecha& f1, const Fecha& f2)
{
    tm* f1, f2;

    f1 -> tm_mday = f1.day_;
    f1 -> tm_mon = f1.month_ - 1;
    f1 -> tm_year = f1.year_ - 1900;
    f2 -> tm_mday = f1.day_;
    f2 -> tm_mon = f1.month_ - 1;
    f2 -> tm_year = f1.year_ - 1900;
        
    return mktime(f1) < mktime(f2); //mktime returns time_t type that is an alias from primitive c++ types
}

bool operator >(const Fecha& f1, const Fecha& f2)
{
    return f2 < f1; 
}

bool operator ==(const Fecha& f1, const Fecha& f2)
{

}

bool operator <=(const Fecha& f1, const Fecha& f2)
{

}

bool operator >=(const Fecha& f1, const Fecha& f2)
{

}

bool operator !=(const Fecha& f1, const Fecha& f2)
{
    
}