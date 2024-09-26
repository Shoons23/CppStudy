#include <iostream>
using namespace std;

class Rectangle{
    // 캡슐화 
    private:
        int width;
        int height;

    public:
        Rectangle(int w, int h){
            width = w;
            height = h;
        }

        int getArea(){
            return width*height;
        }
        // compile 시간이 길어질 수 있음
    
};

int main(){
    Rectangle rect(5,10);

    cout << "Area of rectangle: " << rect.getArea() << endl; 

    return 0;
}