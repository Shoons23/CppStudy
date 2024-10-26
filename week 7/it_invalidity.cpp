#include <iostream>
#include <vector>
#include <list>
#include "func.hpp"

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst ={1, 2, 3, 4, 5};

    auto v_it4 = vec.begin() +4;
    vec.insert(vec.begin() +2, 0);

    auto l_it4 = next(lst.begin(), 4);
    lst.insert(next(lst.begin(), 2), 0);
    
    print(vec);
    print(lst);

    // 무효화된 반복자 출력
    std::cout << "Vector's 4th element (v_it4): " << *v_it4 << std::endl; 
    std::cout << "List's 4th element (l_it4): " << *l_it4 << std::endl;   
}