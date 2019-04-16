#include "fecha.hpp"
#include "cadena.hpp"
#include <sstream>
#include <iostream>

int main()
{
    ostringstream os;
    Cadena c{"hola"};
    Cadena s{c};

    for (Cadena::reverse_iterator r = s.rbegin(); r != s.rend(); ++r)
      os << ++*r;

    cout << os.str();
    for(Cadena::const_reverse_iterator r = c.rbegin(); r != c.rend(); ++r)
        os << *r;
    
    cout << os.str();
    for (auto r = c.crbegin(); r != c.crend(); ++r) 
        os << *r;
    
    cout << os.str() << endl;
    cout << c << endl;
    cout << s << endl;
    return 0;
}