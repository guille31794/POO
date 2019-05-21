#include <iostream>
using namespace std;

struct B
{
    void f() { cout << "f de b" << endl;}
};

struct D: B
{
    void f() {cout << "f de d" << endl;}
};

int main(int argc, char const *argv[])
{
    B b, *bp;
    D d;
    bp = &d;

    bp -> f();
    d.f();

    return 0;
}
