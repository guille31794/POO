#include <iostream>
using namespace std;

class Forma
{
  public:
    virtual double area() const = 0;
    virtual ~Forma() = default;
};

class Circulo: public Forma
{
  public:
    Circulo(double r): r_{r} {}
    double area() const { return (pi*r_*r_);}
    ~Circulo() = default;
  private:
    double r_;
    static constexpr double pi = 3.1415;
};

class Rectangulo: public Forma
{
  public:
    Rectangulo(double b, double a): b_{b}, a_{a} {}
    double area() const {return b_*a_;}
    virtual ~Rectangulo() = default;
  private:
    double b_, a_;
};

class Cuadrado: public Rectangulo
{
  public:
    Cuadrado(int l): Rectangulo(l, l) {}
    ~Cuadrado() = default;
};

int main(){
 Circulo cir(1.0);
 Cuadrado cua(2.0);
 Forma * formas[] = {&cir, &cua};

 for (int i=0;i<2;i++)
   cout << "Dl area de la figura " << (i+1) << "es: "
  << formas[i]->area();
}
