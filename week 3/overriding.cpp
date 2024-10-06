// 오버라이딩의 목적
// 가상함수는 상속받는 파생클래스에서 구현해야 할 함수 인터페이스를 제공

#include <iostream>
using namespace std;

class Base{
public:
    virtual void f(){ cout << "Base::f() called" << endl; }
};

class Derived : public Base{
public:
    virtual void f(){ cout << "Derived::f() called" << endl;}
};

int main(){
    Derived d, *pDer;
    pDer = &d;
    pDer->f(); // Derived::f() 호출

    Base* pBase;
    pBase = pDer; // up casting, 객체 d를 가리킴
    pBase->f(); // 동적 바인딩: 가상함수가 호출되면, 객체 중 오버라이딩 된 가상함수를 호출 
    return 0;
}