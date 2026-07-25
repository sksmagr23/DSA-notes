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

---

### Optimal K-th Largest Element (Min-Heap of size K)

- **Intuition**: Maintaining a full Max-Heap takes $O(N \log N)$ time and $O(N)$ space. Instead, use a **Min-Heap of size K**. At any time, the Min-Heap contains the $K$ largest elements seen so far, and the top element is the $K$-th largest.
- **TC**: $O(N \log K)$, **SC**: $O(K)$.

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove smallest element
            }
        }
        return minHeap.top(); // K-th largest
    }
};
```

---

### Find Median from Data Stream (Two Heaps Pattern)

- **Intuition**: Divide numbers into two halves:
  - `maxHeap` (lower half of numbers)
  - `minHeap` (upper half of numbers)
  Keep sizes balanced: `maxHeap.size() == minHeap.size()` or `maxHeap.size() == minHeap.size() + 1`.
- **TC**: `addNum`: $O(\log N)$, `findMedian`: $O(1)$, **SC**: $O(N)$.

```cpp
class MedianFinder {
    priority_queue<int> maxHeap; // Lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Upper half

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Rebalance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
```

---

### Merge K Sorted Lists

- **Intuition**: Put the head of all $K$ linked lists into a Min-Heap. Extract the smallest node, attach to result list, and push its next node into the heap.
- **TC**: $O(N \log K)$ where $N$ is total number of nodes, **SC**: $O(K)$.

```cpp
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto head : lists) {
            if (head) pq.push(head);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();

            tail->next = minNode;
            tail = tail->next;

            if (minNode->next) {
                pq.push(minNode->next);
            }
        }
        return dummy->next;
    }
};
```

---

### Task Scheduler

- **Problem**: CPU tasks with cooldown parameter $n$. Calculate minimum intervals needed to complete all tasks.
- **Intuition**: Use a Max-Heap to prioritize tasks with highest remaining frequency. Process tasks in blocks of $n + 1$ time slots.
- **TC**: $O(N)$, **SC**: $O(1)$ (since max 26 English letters).

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        priority_queue<int> maxHeap;
        for (auto& [ch, count] : freq) maxHeap.push(count);

        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            while (cycle > 0 && !maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                if (count > 1) temp.push_back(count - 1);
                time++;
                cycle--;
            }

            for (int count : temp) maxHeap.push(count);

            if (maxHeap.empty()) break; // All tasks finished
            time += cycle; // Idle time
        }
        return time;
    }
};
```

---

## Binary Heap Implementation from Scratch

```cpp
class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (i < n) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    MaxHeap() {}

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    // Build Heap in O(N) time from un-ordered array
    void buildHeap(vector<int>& arr) {
        heap = arr;
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }
};
```

