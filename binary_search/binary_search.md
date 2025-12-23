## Standard binary search implementation (Divide & conquer) 

- TC:- `O(logN)`
  
```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            left = mid + 1; // Search in right half
        else
            right = mid - 1; // Search in left half
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

### Elements in range [a, b]

- Given an unsorted array arr[] and a 2D array queries[][] of size q, where each query is in the form of [a, b]. For each query, count how many elements in arr[] lie within the range [a, b], i.e., elements satisfying a ≤ x ≤ b.

```cpp
class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(arr.begin(), arr.end());

        for (const auto &q : queries) {
            int l = q[0], r = q[1];
            int lb = lower_bound(arr.begin(), arr.end(), l) - arr.begin(); // lower bound index
            int rb = upper_bound(arr.begin(), arr.end(), r) - arr.begin(); // upper bound index
            ans.push_back(rb - lb);
        }
        return ans;
    }
};
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

### Find Peak Element

- A peak element is an element that is strictly greater than its neighbors. To return the index of any peak element.

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int low=1, high=n-2;

        while (low<=high) {
            int mid = (low+high)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            if (nums[mid] < nums[mid-1]) {
                high = mid-1; // If mid is smaller than the element on its left, hen a peak must lie to the left, so we can discard the right half.
            } else {
                low = mid+1; // If mid is smaller than the element on its right, then a peak must lie to the right, allowing us to discard the left half.
            }
        }
        return -1;
    }
};
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

- When each row is sorted in non-decreasing order & the first integer of each row is greater than the last integer of the previous row.
  
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

- When integers in each row are sorted in ascending from left to right & integers in each column are sorted in ascending from top to bottom. But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // to start from top-right corner
        int row = 0, col = m-1;
        while (row < n && col >= 0){
            if (matrix[row][col] == target){
                return true;
            } else if (matrix[row][col] < target){
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
};
```

### Peak Element in 2D matrix

- The search will cover the column range from 0 to col-1, where col is the total number of columns.
- We choose a middle column and identify the row with the largest element in that column.
- We apply similar logic as in 1-D: if this element is bigger than both its side neighbors, we’ve found the peak.
- If the left neighbor is bigger, we only search the left part; if the right neighbor is bigger, we search the right part.

```cpp
// O(n*log(m))
class Solution {
public:
    int maxrow(vector<vector<int>>& mat, int col){
        int n = mat.size();
        int max_val = INT_MIN;
        int index = -1;
  
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > max_val) {
                max_val = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = maxrow(mat, mid);

            int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid + 1 < m ? mat[row][mid+1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            } else if (left > mat[row][mid]){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};
```


