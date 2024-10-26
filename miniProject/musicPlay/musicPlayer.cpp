#include <iostram>

// 필요한 데이터 멤버를 가지는 구조체 정의 
template <typename T>
struct cir_list_node
{
    T* data;
    cir_list_node* next;
    cir_list_node* prev;

    ~cir_list_node(){
        delete data;
    }
};

