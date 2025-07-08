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