## Standard binary search implementation (Divide & conquer)
```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1; // Element not found
}
```

## Lower Bound
```cpp
int lowerBound(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching in left half
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return result;
}
```

## Upper Bound
```cpp
int upperBound(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching in right half
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return result;
}
```

## Search in rotated sorted array
```cpp
int searchRotatedArray(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
            
        // Check which part is sorted
        if (arr[left] <= arr[mid]) {
            // Left half is sorted
            if (arr[left] <= target && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            // Right half is sorted
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    
    return -1;
}
```
### To allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum
```cpp
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
```

### Search Target in 2D Matrix

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n*m - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            int row = mid/m;
            int col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
```