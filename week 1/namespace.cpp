#include <iostream>

//  서로 다른 기능의 함수들을 동일한 이름으로 정의해도 충돌 없이 사용할 수 있음
// -> std::cin, std::cout 대신 cin, cout 사용 가능
namespace Math {
    int add(int a, int b) {
        return a + b;
    }
}

namespace Physics {
    int add(int a, int b) {
        return a - b;  // 물리학적으로 덧셈을 다르게 정의했다고 가정
    }
}

int main() {
    int result1 = Math::add(10, 5);  // Math 네임스페이스의 add 함수 호출
    int result2 = Physics::add(10, 5);  // Physics 네임스페이스의 add 함수 호출

    std::cout << "Math::add: " << result1 << std::endl;
    std::cout << "Physics::add: " << result2 << std::endl;
    
    return 0;
}
