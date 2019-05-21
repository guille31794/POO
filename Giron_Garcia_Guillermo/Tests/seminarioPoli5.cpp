#include <iostream>
using namespace std;

class A { public: ~A() {cout << "A" << endl;}};
class B: public A { public: virtual ~B() { cout << "B" << endl; }};
class C: public B { public:
    virtual ~C() { cout << "C" << endl; }
};
class D: public C { public:
    ~D() { cout << "D" << endl; }
};

int main(int argc, char const *argv[])
{
    A *pa = new D;
    delete pa;
    D d;
    return 0;
}
