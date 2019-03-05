// $Id: luhn.cpp 311 2016-04-01 19:03:07Z gerardo $
// Verifica un número de tarjeta empleando el algoritmo de Luhn
// Referencias:
//              http://en.wikipedia.org/wiki/Luhn_algorithm
//

#ifndef luhn_hpp
#define luhn_hpp

#include "cadena.hpp"
#include <cstddef>

bool luhn(const Cadena& numero);

#endif
