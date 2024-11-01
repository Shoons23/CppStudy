
// | **8주차** | **C/C++ 복습** <br>- C 언어 복습: 포인터, 메모리 관리, 구조체 개념 정리 <br> - 메모리 주소와 포인터, 동적 메모리 할당, 구조체와 포인터 실습  <br>- 가상함수와 다형성, 클래스 템플릿, 다중 상속과 가상상속 이해 및 실습 |

#include <stdio.h>

// 포인터 복습
/*
int main(){
    int a = 10; 
    int* ptr_a;  //int형 포인터
    ptr_a = &a;  //포인터 ptr_a에 a주소 저장
 
    printf("a: %d\n", a);
    printf("a address: %d\n", &a);
    printf("ptr_a: %d\n", ptr_a);
}
*/

// 이차원 배열과 포인터
/*void print_2by2(int (*arr_2by2)[3][3]) {
    printf("Printing 2x2 array:\n");
    for (int i = 0; i < 2; i++) {
        printf("arr[%d]:\n", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d ", arr_2by2[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void print_row(int (*arr_row)[3]) {
    printf("Printing row array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr_row[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int arr[2][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},         // arr[0]에 해당 (기존 arr)
        {{11, 22, 33}, {44, 55, 66}, {77, 88, 99}} // arr[1]에 해당 (기존 arr2)
    };

    int(*arr_2by2)[3][3] = arr; // 
    int(*arr_row)[3] = arr[1]; 

    print_2by2(arr_2by2);
    print_row(arr_row);
    printf("arr = %p, arr+1 = %p/n", (void*)&arr_2by2, (void*)(&arr_2by2+1)); // pointer크기 만큼 이동 8byte 차이]
    printf("arr = %p, arr+1 = %p/n", (void*)arr, (void*)(arr+1)); // 36byte 차이 3*3*sizeof(dataType)
}*/

// 구조체
/*
struct NstockInfo{
    int num;
    char name[4];
    double price;
    double volume;
};

typedef struct NstockInfo NstockInfo;

int main(){
    NstockInfo apple = {1, "AAPL", 150.00, 1000000 };
    NstockInfo *ptr = &apple;

    printf("종목 이름: %s\n", ptr->name);
    printf("가격: %.2f\n", (*ptr).price);
}*/

