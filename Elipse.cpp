#include <iostream>

using namespace std;

class FiguraPlana
{
  public:
    FiguraPlana(const double x, const double y): rx{x}, ry{y} {}
    void escala(const double f) {rx *= f; ry *= f;}
    void escala(const double f1, const double f2) {rx *=f1; ry*= f2;}
    virtual void dibuja() { cout << "Figura plana" << endl;}
  protected:
    double rx, ry;
};

class Elipse: public FiguraPlana
{
  public:
    explicit Elipse(const double x = 1, const double y = 1): FiguraPlana(x, y) {}
    double radio_x() const {return rx;}
    double radio_y() const {return ry;}
    virtual void dibuja() { cout << "Elipse" << endl;}
};

class Circunferencia: public Elipse
{
  public:
    explicit Circunferencia(const double x): Elipse(x, 0) {}
    double radio() const { return rx; }
    double radio_y() const = delete;
    void escala(const double f1, const double f2) = delete;
    void dibuja() { cout << "Circulito" << endl;}
};

int main(int argc, char const *argv[]) {
  Circunferencia C(3);
  cout << C.radio() << endl;
  return 0;
}
