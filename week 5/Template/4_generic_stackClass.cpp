#include <iostream>
using namespace std;

template <class T>
class MyStack{
    int tos;
    T data[100]; //stack에 최대 100개 원소
public:
    MyStack();
    void push(T element); // data[]에 푸시
    T pop(); // 스택 탑에 있는 원소를 data[]에서 팝
};

template <class T>
MyStack<T>::MyStack(){ // 생성자
    tos= -1;
}

template <class T>
void MyStack<T>::push(T element){ // 생성자
    if(tos == 99){
        cout << "stack full";
        return;
    }
    tos++;
    data[tos]= element;
}

template <class T> 
T MyStack<T>::pop(){
    T retData;
    if(tos == -1){
        cout << "stack empty";
        return 0;
    }
    retData= data[tos--];
    return retData;
}

int main(){
    MyStack<int> iStack;
    iStack.push(3);
    cout << iStack.pop() << endl;

    MyStack<double> dStack;
    dStack.push(3.5);
    cout << dStack.pop() << endl;

    MyStack<const char*> cStack;
    cStack.push("Hello, world");
    cout << cStack.pop() << endl;

    return 0;
}