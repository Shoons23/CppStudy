#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {5, 1, 4, 2, 8};

    // 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    // 정렬 결과 출력
    cout << "Sorted (Ascending): ";
    for (int n : numbers) {
        cout << n << " "; // 출력: 1 2 4 5 8
    }
    cout << "\n";

    // 내림차순 정렬
    sort(numbers.begin(), numbers.end(), greater<int>());

    cout << "Sorted (Descending): ";
    for (int n : numbers) {
        cout << n << " "; // 출력: 8 5 4 2 1
    }
    cout << "\n";

    return 0;
}
