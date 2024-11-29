#include <iostream>
#include <fstream>
using namespace std;

struct Person{
    char surname[20]; // 20byte
    char lastname [50]; // 50byte
    int age; // 4byte
    char sex; //1byte
};

// int main(){
//     ofstream outFile("data.bin", ios::binary);
//     if(!outFile){
//         cerr << "file open error." << endl;
//         return 1;
//     }

//     Person p1 = {"KIM", "CHEOLSU", 40, 'M'};
//     Person p2 = {"LEE", "YOUNGHEE", 38, 'F'};
//     outFile.write(reinterpret_cast<char*>(&p1), sizeof(p1));
//     outFile.write(reinterpret_cast<char*>(&p2), sizeof(p2));
    
//     outFile.close();
//     cout << "write complete!" << endl;
//     return 0;
// }

int main() {
    ifstream inFile("data.bin", ios::binary); // 이진 읽기 모드
    if (!inFile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    Person p1;
    Person p2;
    inFile.read(reinterpret_cast<char*>(&p1), sizeof(p1)); // 이진 데이터 읽기
    inFile.read(reinterpret_cast<char*>(&p2), sizeof(p2));
    inFile.close();

    cout << "성: " << p1.surname << ", 나이: " << p1.age << ", 키: " << p1.sex << endl;
    return 0;
}