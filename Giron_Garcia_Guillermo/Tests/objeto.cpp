#include <iostream>
using namespace std;

class Objeto{
public:
Objeto(char const *nombre): nombre_(nombre) {
cout << "Constructor de Objeto para " << nombre_ << endl;
}
~Objeto() {
cout << "Destructor de Objeto para " << nombre_ << endl;
}
void lanzamiento() {
Objeto *o = new Objeto("'objeto local de lanzamiento()'");
cout << "Metodo lanzamiento() para " << nombre_ << endl;
throw o;
}
void saludo() {
  cout << "Hola de parte de " << nombre_ << endl;
}
private:
char const *nombre_;
};

int main() {
Objeto o("'objeto de main()'");
try { o.lanzamiento(); }
catch(Objeto *o) {
cout << "Excepción capturada" << endl;
o->saludo();
}
}

/* Constructor de objeto para objeto de main()
  Constructor de objeto para objeto local de lanzamiento()
  Metodo lanzamiento() para objeto de main()
  Destructor de objeto para objeto local de lanzamiento()
  Excepción capturada
  Hola de parte de #123?1x
  Destructor de Objeto para objeto de main()
*/
