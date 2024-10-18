#include <iostream>
using namespace std;


template <typename T>
void print(T arg){
    cout << arg << endl;
}

template <typename T, typename ... Types>
void print(T arg, Types ... args){
    cout << arg << " ";
    print(args...); // 재귀 함수
}

template <typename T, int count>
void print(T value){
    for(int i=0; i<count; i++)
        cout << value <<' ';
    cout << endl;
}

template <class T>
T add(T data [], int n){
    T sum = 0;
    for(int i=0; i<n; i++){sum+= data[i];}
    return sum;
}
int main(){
    // print(1, 2, 3, 4, 5, 6, 7);
    int x[] = {1,2,3,4,5};
    double d[] ={1.2,2.3,3.4,4.56};

    cout << "sum of x[] = " << add(x, 5) << endl;
    cout << "sum of d[] = " << add(d, 4) << endl;

    return 0;
}