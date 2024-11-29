#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream outFile("example.txt");
    if(!outFile){
        cerr << "file open error." << endl;
        return 1;
    }

    outFile << "C++ 스터디 파이팅!" << endl;
    outFile << "두번쨰 줄" << endl;
    
    outFile.close();
    cout << "로그 남기기 완료" << endl;
    return 0;
}
