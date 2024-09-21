#include <iostream>
using namespace std;


// 캡슐화 예제 
class Car{
    private:
        std::string brand;
        std::string model;
        int year;

    public:
    // setter 함수: 외부에서 변수에 안전하게 값을 설정하는 함수
    void setModel(string b) {
        model = b;
    }

    // getter 함수: 외부에서 변수 값을 가져오는 함수
    string getModel() {
        return model;
    }

    void setYear(int y) {
        year = y;
    }

    int getYear() {
        return year;
    }
};

int main(){

    Car person1;

    //person1.brand = "KIA";
    //person1.model = "K7";
    person1.setModel("EV6");
    //person1.year = 2024;
    person1.setYear(2024);
    
    std::cout << "model: " << person1.getModel() << endl;

    std::cout << "year: " << person1.getYear() << endl;

    return 0;

}