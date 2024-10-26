#include <iostream>
#include <forward_list>
#include "func.hpp"

int main(){
    std::forward_list<int> fwd_list = {1, 2, 3, 4, 5};

    fwd_list.push_front(0);
    print(fwd_list);

    auto it = fwd_list.begin();
    fwd_list.insert_after(it,5); 
    print(fwd_list);

    fwd_list.emplace_front(3);
    fwd_list.emplace_after(++it, 8);
    print(fwd_list);

    fwd_list.pop_front();
    print(fwd_list);

    fwd_list.erase_after(it);
    print(fwd_list);

    it = fwd_list.begin();
    fwd_list.erase_after(it);
    print(fwd_list);
    fwd_list.erase_after(it, fwd_list.end());
    print(fwd_list);

    std::forward_list<int> fwd_list2 = {1, 2, 3, 4, 5};

    // remove: 리스트에서 값이 3인 모든 요소를 삭제
    fwd_list2.remove(3);
    std::cout << "After remove(3): ";
    print(fwd_list2);

    // remove_if: 리스트에서 4보다 큰 요소를 삭제
    fwd_list2.remove_if([](int x) { return x > 4; });
    std::cout << "After remove_if(x > 5): ";
    print(fwd_list2);
    
}