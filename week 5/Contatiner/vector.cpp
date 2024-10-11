#include <iostream>
#include <vector>

// container : 저장 및 검색을 위해 자료 구조를 구현한 객체

// vectkr: 특정 자료형을 동적으로 받을 수 있다.

using namespace std;

//vector 정의시 크기를 주어야 한다.
int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v[0]=10;
    int m=v[2];
    v.at(2) = 5;


    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;

}


// vector<vector <int> > phone_book = {
//     {"David Hume",123456},
//     {"Karl Popper",234567},
//     {"Bertrand Arthur William Russell",345678}
// };


