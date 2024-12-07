#include<bits/stdc++.h>
using namespace std;

int main() {
    for(int i=1;i<=5;i++){
        if (i % 2 !=0){
            for (int j=1;j<=i;j++){
                if (j % 2 !=0){
                    cout << true << " " ;
                }
                else{
                    cout << false << " " ;
                }
            }
        }
        else {
            for (int j=1;j<=i;j++){
                if (j % 2 !=0){
                    cout << false << " " ;
                }
                else{
                    cout << true << " " ;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}

// output:-
// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1 

