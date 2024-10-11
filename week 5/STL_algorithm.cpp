#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;

    cout << "put 5 numbers";
    for(int i=0; i<5; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end()); // v.begin()~v.end()사이 모두 정렬

    vector<int>::iterator it;

    for(it=v.begin(); it < v.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;1
}