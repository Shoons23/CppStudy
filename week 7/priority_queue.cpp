#include <iostream>
#include <queue>
#include <string>

struct Person {
    std::string name;
    int age;

    // 비교 연산자 오버로드 (age 기준으로 정렬)
    bool operator<(const Person& other) const {
        return age < other.age; // 나이 내림차순 정렬
    }
};

int main() {
    std::priority_queue<Person> pq;

    pq.push({"Alice", 30});
    pq.push({"Bob", 25});
    pq.push({"Charlie", 35});

    while (!pq.empty()) {
        Person p = pq.top();
        std::cout << p.name << " (" << p.age << ")" << std::endl;
        pq.pop();
    }

    return 0;
}
