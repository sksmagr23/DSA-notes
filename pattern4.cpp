#include <bits/stdc++.h>
using namespace std;

int main(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i - 1; j++){
            cout << " ";
        }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++){
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        for (int j = 0; j < 4 - i - 1; j++){
            cout << " ";
        }

        cout << endl;
    }
    return 0;
}

// output:-
//    A   
//   ABA  
//  ABCBA 
// ABCDCBA
