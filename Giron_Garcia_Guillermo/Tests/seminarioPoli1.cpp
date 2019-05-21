#include <iostream>
using namespace std;

void mostrar(int i) { cout << i << " [entero]" << endl; }
void mostrar(float f) { cout << f << " [real]" << endl; }

int main(int argc, char const *argv[])
{
    mostrar(2);
    mostrar((float)(2.0));
    mostrar('a');
    return 0;
}
