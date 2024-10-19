// find & binary_search


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {5, 1, 4, 2, 8};

    // 1. 선형 탐색 (find)
    auto it = find(numbers.begin(), numbers.end(), 4);
    if (it != numbers.end()) {
        cout << "Found 4 at index: " << distance(numbers.begin(), it) << "\n";
    } else {
        cout << "4 not found\n";
    }

    // 2. 이진 탐색 (binary_search) - 정렬된 상태에서만 사용 가능
    sort(numbers.begin(), numbers.end());
    if (binary_search(numbers.begin(), numbers.end(), 4)) {
        cout << "4 is found (Binary search)\n";
    } else {
        cout << "4 is not found (Binary search)\n";
    }

    return 0;
}
