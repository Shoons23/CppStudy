#include <iostream>
using namespace std;

// 가상함수를 통해 같은 메써드를 클래스에 각기 다르게 구현

class Car{
public:
    virtual void engine(){
        cout << "engine is good" << endl;
    }
};

class electric: public Car {
public:
    void engine(){
        cout << "electric car" << endl;
    }
};

class hybrid: public Car{
public:
    void engine() override {
        cout << "hybrid car" << endl;
    }
};

int main(){
    Car* myCar = new hybrid();
    myCar->engine(); 

    myCar = new electric();
    myCar->engine();

    delete myCar;
    return 0;
}