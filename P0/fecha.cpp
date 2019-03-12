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