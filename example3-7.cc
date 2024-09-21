#include <iostream>
using namespace std;

class Circle {
public:
    int radius;
    Circle();
    Circle(int r);
    ~Circle(); // 소멸자 선언
    double getArea();
};

Circle::Circle() {
    radius = 1;
    cout << "radius " << radius << " create a circle" << endl;
}

Circle::Circle(int r) {
    radius = r;
    cout << "radius " << radius << " create a circle" << endl;
}

Circle::~Circle() {
    cout << "radius " << radius << " remove a circle" << endl;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle donut;
    Circle pizza(30);
    return 0;
}