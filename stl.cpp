#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int, int>mpp;
    mpp[3] = 1;
    mpp.insert({1, 2});
    for (auto i : mpp){
        cout << i.first << " " << i.second << endl;
    }    
    return 0;
}