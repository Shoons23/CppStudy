#include <iostream>
#include <string>
using namespace std;

// 기존 클래스 특징들을 가지는 하위 클래스를 만들 떄 상속
// 소프트웨어의 생산성을 향상
// 코드의 재사용성 높임
// 관련 없는 클래스끼리 상속하도록 하지 않도록 주의하자!


class Point{
    int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point{ // Point 클래스를 상속받음
    string color;
public:
    void setColor(string color){this->color= color;}
    void showColorPoint();
};

void ColorPoint::showColorPoint(){
    cout << color << ":";
    showPoint();// Point의 showPoint() 호출
}

int main(){
    Point p; // 기본 클래스 객체 생성
    ColorPoint cp; // 파생 클래스 객체 생성
    
    cp.set(3,4);
    cp.setColor("Red");
    cp.showColorPoint();

}

