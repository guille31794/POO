#include <iostream>
#include <typeinfo>

using namespace std;

template <int id>
class B
{
        int *p;
    public:
        B(): p{new int} 
        {
            cout << typeid(*this).name() << "::"
            << typeid(*this).name() << "()" << endl;
        }
        B(const B& b) : p{new int{*(b.p)}}
        {
            cout << typeid(*this).name() << "::"
            << typeid(*this).name() << " (const " 
            << typeid(*this).name() << "&)" <<
            endl;
        }
        virtual ~B()
        {
            delete p;
            cout << typeid(*this).name() << "::~"
            << typeid(*this).name() << "()" << endl;
        }
};

class D:  public B<0>
{
    public:
        D() { cout << "D::D()" << endl; }
        D(const D& d): B<0>{static_cast<const B&>(d) }, 
        b1{d.b1}, b2{d.b2}
        {cout << "D::D(const D&)" << endl;}
        ~D() {cout << "D::~D()" << endl;}
    private:
        B<1> b1;
        B<2> b2;
};

int main(int argc, char const *argv[])
{
    B<0>& b{*new D};
    cout << "----------" << endl;
    D d{dynamic_cast<D&>(b)};
    cout << "----------" << endl;
    delete &b;
    cout << "----------" << endl;
    return 0;
}
