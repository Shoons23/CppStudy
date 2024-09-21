#include <iostream>
using namespace std;

class Car {  // 클래스 정의 : 객체를 생성하기 위해 변수와 메소드를 정의하는 템플릿
public:
    string brand;  // 멤버 변수
    string model;
    int year;

    void displayInfo() {  // 멤버 함수
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

// 다른 사람이 만들어 놓은 함수와 변수 등을 사용할 수 있다. 

int main() {
    Car HoonsCar;  // 객체 생성
    HoonsCar.brand = "KIA";  // 객체의 멤버 변수에 접근
    HoonsCar.model = "EV6";
    HoonsCar.year = 2020;

    HoonsCar.displayInfo();  // 객체의 멤버 함수 호출

    return 0;
}
