#include <iostream>
#include <array>
#include <vector>
using namespace std;


template <size_t N>
void print(array<int, N> arr){
    for(auto ele : arr)
        cout << ele << " ";
    
    cout << endl;
}

// const를 사용하여 복사 없이 array 객체를 함수에 전달
template <size_t N>
void printArray(const array<int, N>& arr) {
    for (const int& ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
}


// 템플릿을 사용하여 array와 vector에 대한 print 함수 정의
template <typename T>
void print(const vector<T>& vec) {
    for (const auto& ele : vec) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    // array 예제
    array<int, 5> arr = {1, 2, 3, 4, 5};
    print(arr); // array 출력

    // vector 예제
    vector<int> vec = {6, 7, 8, 9, 10};

    vec.pop_back();
    print(vec); // vector 출력
    
    vec.erase(vec.begin());
    print(vec); // vector 출력

    vec.erase(vec.begin()+1, vec.begin()+4);
    print(vec);
   
}