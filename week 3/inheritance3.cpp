// 다중 상속

#include <iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) { return a+b; }
};

class Subtractor {
protected:
	int minus(int a, int b)  { return a-b; }
};

class Calculator : public Adder, public Subtractor{
public:
    int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b){
    int result= 0;
    switch(op){
        case '+': result = add(a, b); break;
        case '-': result = minus(a, b); break;
    }
    return result;
}

int main(){
    Calculator handCalculator;
    char op;
    int a, b; 
    cout << "put an equation" << endl;
    cin >> a >> op >> b;

    cout << a << op << b << "= " << handCalculator.calc(op, a, b) << endl;

}

// 다중 상속을 받을 때 상속해준 클래스끼리 멤버 중복 생성 문제가 일어날 수 있다.

// 따라서 파생 클래스를 선언할 때 vitual을 섞으면 된다.