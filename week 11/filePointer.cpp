#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file("example.txt", ios::in | ios::out);
    if(!file){
        cerr << "file open error." << endl;
        return 1;
    }

    // 쓰기 포인터 이동 후 데이터 쓰기
    file.seekp(0, ios::end);
    file << "추가 데이터" << endl;

    // 읽기 포인터 이동 후 데이터 쓰기
    file.seekg(0, ios::beg);
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }

    file.close();
    return 0;
}


