#include <iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(){radius = 1;}
    Circle(int r){ radius = r;}
    double getchar();
};

double Circle::getchar(){
    return 3.14*radius*radius;
}

int main(){
    Circle donut;
    Circle pizza(30);

    cout << donut.getchar() << endl;


    Circle* p;
    p = &donut;
    cout << p->getchar() << endl;
    cout << (*p).getchar() << endl;

    p = &pizza;
    cout << p->getchar() << endl;
    cout << (*p).getchar() << endl;

}



