#include <iostream>
#include <map>
using namespace std;

int main(){
    // map<const char *, const char *> dic; 
    map<string, string> dic;

    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));
    dic["cherry"] = "체리";

    cout << "저장된 단어 수: " << dic.size() << endl;
}