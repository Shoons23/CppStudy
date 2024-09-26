#include <iostream>
using namespace std;

class Car{
public:
    void engine(){
        cout << "engine is good" << endl;
    }
};

//기존 클래스 특징들을 가지는 하위 클래스를 만들 떄 상속
//코드의 재사용성 높임

class brand: public Car {
public:
    void price(string option, string option2){
        cout << "price: $20000 " << option << " " << option2 << endl;
    }
};


int main(){
    brand tesla;
    tesla.engine();
    tesla.price("FSD", "speaker" );
    return 0;
}