#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("example.txt");
    if(!inFile){
        cerr << "file open error." << endl;
        return 1;
    }

    string line;
    while(getline(inFile, line)){
        cout << line << endl;
    }

    inFile.close();
    return 0;
}

