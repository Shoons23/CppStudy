#include <iostream>
#include <list>
#include "func.hpp"

int main(){
    std::list<int> list = {1, 2, 3, 4, 5};
    list.push_back(6);
    list.insert(next(list.begin()), 0);
    list.insert(list.end(), 7);

    print(list);

    list.pop_back();
    print(list);
}