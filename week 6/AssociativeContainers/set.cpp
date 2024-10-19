#include <iostream>
#include <set>
using namespace std;

// 고유한 값들을 저장하고, 삽입된 값은 자동으로 정렬
// 집합

int main() {
    set<int> numberSet;

    // 값 추가
    numberSet.insert(10);
    numberSet.insert(5);
    numberSet.insert(20);
    numberSet.insert(10); // 중복된 값은 무시됨

    // 자동 정렬된 상태로 출력
    for (int num : numberSet) {
        cout << num << " "; // 출력: 5 10 20
    }
    cout << "\n";

    // 찾기(find) 사용
    if (numberSet.find(5) != numberSet.end()) {
        cout << "Found 5\n";
    } else {
        cout << "5 not found\n";
    }

    return 0;
}
