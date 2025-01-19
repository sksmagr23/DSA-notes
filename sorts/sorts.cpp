// SELECTION SORT:- TC: O(N**2)
// BUBBLE SORT:- TC: O(N**2) for worst/average, O(N) for best case optimized
// INSERTION SORT:- TC: O(N**2) for worst/average, O(N) for best case optimized

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    swap(arr[i], arr[mini]);
    /*  int temp = arr[mini]; Alternate: swap uisng temp
        arr[mini] = arr[i];
        arr[i] = temp;         */
  }
  cout << "Sorted array: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i <= n-1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
               swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "Sorted array: " << "\n";
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        for (int j = i; j > 0; j--) {
          if (arr[j - 1] > arr[j]) {
            swap(arr[j-1], arr[j]);
          }
        }
    }
    cout << "Sorted array: " << "\n";
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
}



int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
  selection_sort(arr, n);
  cout << "\n" ;
  bubble_sort(arr, n);
  cout << "\n" ;
  insertion_sort(arr, n);
  return 0;
}