## Longest Increasing Subsequence (LIS) - using binary search

- Intuition best using Binary Search:- We keep a temporary array `temp` that stores current increasing sequence of each length. For each number, if it is greater than the last value in `temp`, we extend the subsequence by appending it. Otherwise, we find the position where this number should replace an existing value using binary search by `lower_bound`, keeping the tails as small as possible. The length of `temp` after processing all numbers is the length of the LIS.
- Note:- The `temp` array does not necessarily represent a valid subsequence from the original array, but its length corresponds to the length of the longest increasing subsequence found so far.

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > temp.back()){
                temp.push_back(nums[i]);
            } else {
                // Index at which the current element must be placed
                int it = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[it] = nums[i];
            }
        }
        return temp.size();
    }
};
```
