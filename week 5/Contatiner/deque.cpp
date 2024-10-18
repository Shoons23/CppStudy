#include <iostream>
#include <deque>
using namespace std;

//deque는 양방향 que이다.

int main() {
    deque<int> d = {2, 3, 4};

    d.push_back(5);  // 뒤에 5 추가
    d.push_front(1); // 앞에 1 추가

    for (int i : d) {
        cout << i << " "; // 출력: 1 2 3 4 5
    }
    cout << "\n";

    d.pop_back(); // 마지막 요소 삭제
    d.pop_front(); // 첫 번째 요소 삭제

    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n"; // 출력: Front: 2, Back: 4

    return 0;
}