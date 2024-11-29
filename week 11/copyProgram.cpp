#include <iostream>
#include <fstream>
#include <sys/stat.h> // linux/mAc

using namespace std;

int main(){
    
    ifstream inFile("example.txt");
    ofstream outFile("destination.txt");
    if (!inFile || !outFile) {
        cerr << "파일 열기에 실패했습니다." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();
    cout << "파일 복사가 완료되었습니다." << endl;
    return 0;
}
