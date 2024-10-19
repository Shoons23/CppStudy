#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> squares;

    // transform을 사용하여 각 숫자의 제곱 계산
    transform(numbers.begin(), numbers.end(), back_inserter(squares),
              [](int n) { return n * n; });

    // 결과 출력
    cout << "Squares: ";
    for (int n : squares) {
        cout << n << " "; // 출력: 1 4 9 16 25
    }
    cout << "\n";

    return 0;
}
