# include <iostream>
using namespace std;

class Car{
    public: 
        string brand;
        string model;
        int year;

        // 생성자(Constructor): 객체 생성 시 호출됨
        Car(string b, string m, int y){
            brand= b;
            model= m;
            year= y;
            std:cout << "Car obect created!" << endl;
        }

        // 소멸자: 객체 소멸 시 호출
        ~Car() {
            cout << "Car object destroyed!" << endl;
    }

    void displayInfo(){
        cout << "Brand: " << brand << ", Model: " << model << ", Year" << year << endl;
    }
};

int main(){
    Car person2("BMW", "X5", 2019);
    person2.displayInfo();

    return 0;
}