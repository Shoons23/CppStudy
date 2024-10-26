#include <iostream>
#include <deque>
#include "func.hpp"

int main(){
    std::deque<int> deq = {1, 2, 3, 4, 5};
    deq.push_front(0);
    deq.push_back(6);
    print(deq);

    deq.insert(deq.begin()+2, 10);
    print(deq);

    deq.pop_back();
    deq.pop_front();
    print(deq);
    
    deq.erase(deq.begin()+1);
    deq.erase(deq.begin()+3, deq.end());
    print(deq);

}