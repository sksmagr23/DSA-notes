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

---

### Minimum Window Substring (LeetCode 76 - Hard)

- **Intuition**: Use a frequency array for characters in `t`. Expand right pointer `r`. When a character's count in window matches required count, increment `matched`. Once all characters match, shrink from `l` to minimize window.
- **TC**: $O(N)$, **SC**: $O(128)$.

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        vector<int> map(128, 0);
        for (char c : t) map[c]++;

        int count = t.size();
        int l = 0, r = 0, minLen = INT_MAX, startIndex = 0;

        while (r < s.size()) {
            if (map[s[r]] > 0) count--;
            map[s[r]]--;
            r++;

            while (count == 0) { // Valid window found
                if (r - l < minLen) {
                    minLen = r - l;
                    startIndex = l;
                }
                map[s[l]]++;
                if (map[s[l]] > 0) count++; // Invalidated
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
```

---

### Longest Repeating Character Replacement

- **Intuition**: In any window `[l, r]`, the number of replacements needed is `(windowLen - maxFreqChar)`. If `(r - l + 1 - maxFreq) > k`, shrink window by moving `l++`.
- **TC**: $O(N)$, **SC**: $O(26)$.

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, maxFreq = 0, maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // If replacements needed > k, shrink window
            if ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
```

---

### Fruit Into Baskets (At Most 2 Distinct Elements)

- **Intuition**: Find the length of the longest contiguous subarray containing at most 2 distinct integers. Use frequency map with sliding window.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l = 0, maxFruits = 0;

        for (int r = 0; r < fruits.size(); r++) {
            mpp[fruits[r]]++;

            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            maxFruits = max(maxFruits, r - l + 1);
        }
        return maxFruits;
    }
};
```

---

### Container With Most Water

- **Intuition**: Two pointers at ends `l = 0` and `r = n - 1`. Area $= \min(h[l], h[r]) \times (r - l)$. Move the pointer pointing to the shorter line inward because moving the taller line can never yield a larger area.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;

        while (l < r) {
            int h = min(height[l], height[r]);
            maxWater = max(maxWater, h * (r - l));

            if (height[l] < height[r]) l++;
            else r--;
        }
        return maxWater;
    }
};
```

---

### 4-Sum Problem (Two Pointers with Duplicate Handling)

- **Intuition**: Sort array. Fix outer loops `i` and `j`. Use two pointers `k = j + 1` and `l = n - 1` for remaining sum `target - (nums[i] + nums[j])`. Skip duplicates at each pointer.
- **TC**: $O(N^3)$, **SC**: $O(1)$ extra.

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate i

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate j

                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++; // Skip duplicate k
                        while (k < l && nums[l] == nums[l + 1]) l--; // Skip duplicate l
                    }
                }
            }
        }
        return ans;
    }
};
```

