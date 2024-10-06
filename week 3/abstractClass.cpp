// 인스턴스를 생성할 목적(가상 함수)이 아닌, 상속을 위한 기본 클래스로 활용(인터페이스)
#include <iostream>
#include <String>

using namespace std;

class Shape{
public: 
    void paint(){
        draw();
    }
    virtual void draw() = 0; // 순수 가상함수
};

class Circle : public Shape{
public:
    virtual void draw(){cout << "Circle"};
    string toString(){return "Circle 객체"}
}


// 응용프로그램의 설계와 구현을 분리할 수 있다.
