#### Array rotation by k places right
```cpp 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // Handle case where k is larger than array size
        k = k % n;
        vector<int> rotated(n);  // Temporary array to hold rotated values

        // Move each element to its rotated position
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i];  // Element at i goes to (i+k)%n
        }

        // Copy back the rotated values to original array
        for (int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        }
    }
};
```

#### Array rotation by k places left
```cpp
class Solution {
public:
    void rotateLeft(vector<int>& nums, int k) {
        int n = nums.size();
        // Handle case where k is larger than array size
        k = k % n;
        vector<int> rotated(n);  // Temporary array to hold rotated values

        // Move each element to its rotated position
        for (int i = 0; i < n; i++) {
            // Element at i goes to (i-k) position, add n to handle negative indices
            rotated[(i - k + n) % n] = nums[i];
        }

        // Copy back the rotated values to original array
        for (int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        }
    }
};
```

#### XOR props
- XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
- XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

#### Kadane's Algorithm (Maximum Subarray Sum)
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxs = LONG_MIN;
        long long sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];

            if (sum > maxs){
                maxs = sum;
            }
            if (sum<0){
                sum = 0;
            }
        }
        return maxs;
    }
};
```

#### Sliding Window Technique (Fixed Size)
```cpp
class Solution {
public:
    int maxSumSubarrayOfSizeK(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return -1;
        
        // Compute sum of first window
        int windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += nums[i];
            
        int maxSum = windowSum;
        
        // Slide window and update maximum
        for (int i = k; i < n; i++) {
            windowSum = windowSum + nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};
```

#### Sliding Window Technique (Variable Size)
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            
            // Try to minimize window size while sum >= target
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }
        
        return minLength == INT_MAX ? 0 : minLength;
    }
};
```

#### Two Pointer Technique (Array Partition)
```cpp
class Solution {
public:
    // Dutch National Flag algorithm for 3-way partition
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            switch (nums[mid]) {
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};
```

#### Prefix Sum Array
```cpp
class Solution {
public:
    // Range sum query using prefix sum
    vector<int> buildPrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        return prefix;
    }
    
    // Get sum of elements from index i to j (inclusive)
    int rangeSum(vector<int>& prefix, int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
};
```

#### Boyer-Moore Voting Algorithm (Majority Element)
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        // Find potential candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
```

#### Two Sum (Optimal Solution)
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
               return {mpp[moreNeeded], i};
            }
           mpp[num] = i;
        }
        return { -1, -1};
    }
};
```

#### Three Sum (Optimal Solution)
```cpp
class Solution {
public:
    vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}
};
```