#include <iostream>
using namespace std;

struct B
{
    B(){ cout << "Constructor de B" << endl;}
    virtual ~B() {cout << "Destructor de B" << endl;}
};

struct D : B
{
    D() { cout << "Constructor de D" << endl;}
    ~D() { cout << "Destructor de D" << endl; }
};

int main(int argc, char const *argv[])
{
    B *pb = new D;
    delete pb;

    return 0;
}