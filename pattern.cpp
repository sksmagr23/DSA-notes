#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int i=1; i<=9; i++){
        if ( i % 2 != 0){

            for (int k = 1; k <= (9-i)/2; k++) {
                cout << "  ";
            }
            for (int j=1; j<=i; j++){
                cout << "* ";
            }
        }
        else {
            continue;
        }

        cout << "\n";
    }
    return 0;
}

// Output :-
//         * 
//       * * * 
//     * * * * * 
//   * * * * * * * 
// * * * * * * * * * 
