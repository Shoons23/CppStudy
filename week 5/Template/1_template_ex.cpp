#include <iostream>
using namespace std;

template <typename type>
void print_ex(type a, type b, type c){
    cout << a << b << c << endl;
}

template <typename type1, typename type2, typename type3>
void print_ex2(type1 a, type2 b, type3 c){
    cout << a << " " << b << " " << c << endl;
}

int main(){
    print_ex(1, 5, 3);
    print_ex(4.6,2.3, 1.5);
    print_ex<char>('a', 'c', 'e');
    print_ex2<int, double, char>(3,1.5, 'c');

}