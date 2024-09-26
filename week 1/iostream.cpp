// C++에서 표준 입력과 출력을 처리하는 도구로, cin은 입력, cout은 출력, cerr은 에러 출력을 담당합니다.
#include <iostream>
#include <string>

void process(int value) {
    if (value < 0) {
        std::clog << "Warning: Negative value received: " << value << std::endl;  // 로그 출력
    } else {
        std::clog << "Processing value: " << value << std::endl;  // 일반 로그
    }
}

int main() {
    std::clog << "Program started." << std::endl;  // 프로그램 시작 로그

    process(10);   // 양수 처리
    process(-5);   // 음수 처리

    std::clog << "Program ended." << std::endl;  // 프로그램 종료 로그

    return 0;
}

