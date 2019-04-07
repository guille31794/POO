#include <iostream>

struct B{
virtual void f ( ) { std::cout << "f ( ) de B" << std::endl;}
};

struct D:B{
void f ( ) { std::cout<<"f ( ) de D" << std::endl;}
};

void f(B &b){
std::cout << "f ( ) externa"<< std::endl;
b.f( );
}

int main( ){
  B b;
  D d;
  f(b);
  f(d);
}
