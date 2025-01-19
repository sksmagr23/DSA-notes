#include<bits/stdc++.h>
using namespace std;

// Standard Binary Search
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = (right + left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Lower Bound (first element >= target)
int lowerBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    
    while (left < right) {
        int mid = (right + left) / 2;
        
        if (arr[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// Upper Bound (first element > target)
int upperBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    
    while (left < right) {
        int mid = (right + left) / 2;
        
        if (arr[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// Binary Search on Descending Array
int descendingBinarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = (right + left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;
    
    cout << "Found at index: " << binarySearch(arr, target) << endl;
    
    cout << "Lower bound: " << lowerBound(arr, target) << endl;
    cout << "Upper bound: " << upperBound(arr, target) << endl;
    
    vector<int> desc = {6, 5, 4, 3, 2, 1};
    cout << "Descending search: " << descendingBinarySearch(desc, target) << endl;
    return 0;
}