#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int  i = 0; i<t; i++){
        long long x,y,k;
        cin >> x >> y >> k;
        long long xmov = (x + k - 1) / k;
        long long ymov = (y + k - 1) / k;
        long long total = max(xmov, ymov) * 2;
        cout << total << endl;
    }
    return 0;
}