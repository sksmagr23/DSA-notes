#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hashar[13] = {0};
    for (int i = 0; i < n; i++) {
        hashar[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << "Then no. of times " << number << " occurs in arr is " << hashar[number] << endl;
    }
    return 0;
}