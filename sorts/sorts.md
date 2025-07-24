## SORT ALGOS

### SELECTION SORT:- TC: O(N**2)

```cpp
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
```

### BUBBLE SORT:- TC: O(N**2) for worst/average, O(N) for best case optimized

```cpp
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
```

### INSERTION SORT:- TC: O(N**2) for worst/average, O(N) for best case optimized

```cpp
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
```

### MERGE SORT :- Divide and merge , TC:- O(N*logN) SC:- O(N)

```cpp
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left //
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int main() {
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;
    mergeSort(arr, 0, n - 1);
    cout << "Sorted by merge sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    return 0 ;
}
```

### QUICK SORT : Divide and conquer , TC:- O(N*logN)  SC:- O(1)

```cpp
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quick_sort(arr, low, pIndex - 1);
        quick_sort(arr, pIndex + 1, high);
    }
}


int main() {
    vector<int> arr = {4, 6, 12, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    quick_sort(arr, 0, n - 1);
    cout << "Sorted by quick sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    return 0 ;
}
```
