#include <iostream>
#include <string>
using namespace std;

// 클래스마다 생성자, 소멸자가 하나씩 있으며, 객체가 생성되거나 소멸될 때 생성자와 소멸자가 각각 실행

// 파생 클래스의 생성자에서 기본 클래스의 생성자를 호출할 때 인자를 전달한다.

class TV{
    int size;
public:
    TV() {size= 20; }
    TV(int size) {this->size= size; }
    int getSize() {return size; }
};

class WideTV : public TV{
    bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size){
        this->videoIn= videoIn;
    }
    bool getVideoIn(){
        return videoIn;
    }
};

class  SmartTV : public WideTV {
	string ipAddr; 
public:
	 SmartTV(string ipAddr, int size) : WideTV(size,true){ 
		 this->ipAddr = ipAddr;
	}
	 string getIpAddr() { return ipAddr; }
};

// 객체 htv가 생생될 때, 생성자 SmartTV()가 호출, 클래스 WideTV 상속받고 있으므로, WideTV의 생성자 호출
int main(){
    SmartTV htv("192.0.0.1", 32);
    cout << "size= " << htv.getSize() << endl;
    cout << "videoIn= " << boolalpha << htv.getVideoIn() << endl;
    cout << "IP= " << htv.getIpAddr() << endl;
}