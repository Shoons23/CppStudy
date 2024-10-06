// c에서 malloc, free : 값 초기화 없음, 캐스팅이 필요, 함수호출
// new, delete : 객체 초기화 및 생성자 호출, 자동으로 타입에 맞는 포인터 반환, 연산자

#include <iostream>
using namespace std;

int main(){
    int* p;

    p = new int;
    if(!p){
        cout << "memory allocation failed.";
        return 0;
    }

    *p= 5;
    int n= *p;
    cout << "*p= " << *p << endl;
    cout << "n= " << n << endl;

    delete p;
}