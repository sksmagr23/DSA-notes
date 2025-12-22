### Longest Substring length Without Duplicate Characters
```cpp
int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        int maxlen = INT_MIN;
        unordered_set<int> st;  // Set to track characters in current window
        int l = 0;  // Left pointer of sliding window
        
        // Right pointer moves through the string
        for (int r = 0; r < s.length(); r++){
            // If current character already exists in our window
            if (st.find(s[r]) != st.end()){
                // Shrink window from left until we remove the duplicate
                while (l < r && st.find(s[r]) != st.end()){
                    st.erase(s[l]);  // Remove character at left pointer
                    l++;  // Move left pointer right
                }
            }
            st.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
```

### Maximum number of consecutive 1's in the array if can flip at most k 0's.
```cpp
int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int maxlen = 0;
        int zeros = 0;   // Count of zeros in current window
        
        for (int end = 0; end < nums.size(); end++){
            // If we encounter a zero, increment our zero count
            if (nums[end] == 0) zeros++;
            
            // If we have more zeros than allowed (k), shrink window from start
            while (zeros > k) {
                // If the leftmost element is a zero, decrement zero count
                if (nums[start] == 0) zeros--;
                start++;
            }
            maxlen = max(maxlen, end - start + 1);
        }
        return maxlen;
    }
```

### Count number of subarrays that contain exactly k distinct characters.

```cpp
class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> mpp;
        int res = 0;
        int l = 0;
        for (int r = 0; r < n; r++){
            mpp[nums[r]]++;
            while (mpp.size() > k){
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }
};
```
