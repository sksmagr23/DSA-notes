# Heaps and Priority Queues

## Introduction to Priority Queues using Binary Heaps

A Priority Queue is an abstract data type where each element has a "priority" assigned to it. Elements with higher priority are served before elements with lower priority.

In C++, `priority_queue` is implemented using binary heap data structure. By default, it creates a max heap (highest priority element at the top).

### Key Operations and Complexity

- **push**: Insert an element - O(log n)
- **pop**: Remove the highest priority element - O(log n)
- **top**: Access the highest priority element - O(1)
- **size**: Get number of elements - O(1)
- **empty**: Check if empty - O(1)

### Basic Usage in C++

```cpp
// Max Heap (default)
priority_queue<int> maxHeap;

// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Custom comparator
struct CompareHeight {
    bool operator()(const Person& p1, const Person& p2) {
        return p1.height > p2.height;  // Min heap based on height
    }
};
priority_queue<Person, vector<Person>, CompareHeight> pq;
```

### Kth largest element in array (using max heap)

```cpp
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i =0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        int remove = k - 1;
        while (remove){
            pq.pop();
            remove-- ;
        }
        return pq.top();
    }
```

### Kth smallest element in array (using min heap)

```cpp
int kthSmallest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq ;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]) ;
        }
        int remove = k - 1;
        while (remove){
            pq.pop();
            remove-- ;
        }
        return pq.top();
    }
```

### K most frequent elements in an array (Leetcode 347)

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> mpp;
       for (int num : nums) mpp[num]++;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       for (auto& [num, count] : mpp) {
           pq.push({count, num});
           if (pq.size() > k) pq.pop();
       }
       vector<int> res;
       while (!pq.empty()) {
           res.push_back(pq.top().second);
           pq.pop();
       }
       return res;
    }
```

#### Minimum number of conference rooms required so that all meetings can be done. given start and end time of meetings

```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(intervals[0][1]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= pq.top()) {
            pq.pop();
        }
        pq.push(intervals[i][1]);
    }
    return pq.size();
}
```

### Replace elements by its rank in the array

```cpp
class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mpp;
        for (auto it : arr) pq.push(it);
        int rank = 1;
        while (!pq.empty()){
            int it = pq.top();
            pq.pop();
            if (mpp.find(it) == mpp.end()){
                mpp[it] = rank;
                rank++;
            }
        }
        vector<int> ans;
        for (int i = 0 ; i < N; i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};
```
