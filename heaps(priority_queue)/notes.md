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