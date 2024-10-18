#include <iostream>
#include <cstring>
using namespace std;

template <typename type>
int getSize(type arg){
    return sizeof(arg);
}

template<> int getSize(const char* str){
    return strlen(str);
}


int main(){
    cout << "할당 메모리 크기: " << getSize(5) << "byte\n" ;
    cout << "할당 메모리 크기: " << getSize(3.141592) << "byte\n" ;
    cout << "문자열 할당 메모리 크기: " << getSize("Hello, world") << "byte\n" ;
}