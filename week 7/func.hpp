/*
author : tshoons
e-mail : tshoon0723@gmail.com
*/


#ifndef FUNC_HPP
#define FUNC_HPP

#include <iostream>
#include <iterator>
#include <type_traits>

// begin과 end가 있는 모든 STL 컨테이너에 대해 사용할 수 있도록 설계
template <typename Container>
void print(const Container& container) {
    for (const auto& ele : container) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

// 크기를 알 수 있는 정적 배열을 위한 특수화
template <typename T, std::size_t N>
void print(const T(&arr)[N]) {
    for (const auto& ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

#endif // PRINT_H
