## DP on Subsequences

- A subset/subsequence is a contiguous or non-contiguous part of an array, where elements appear in the same order as the original array. For example, for the array: [2,3,1] , the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence because its elements are not in the same order as the original array.
- Genral thumb rule:- f(index, target)

### To check whether any Subset sum equal to target K

```cpp
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(n-1, k, arr, dp); // f(n-1, target) means that we need to find whether there exists a subsequence in the array from index 0 to n-1, whose sum is equal to the target
    }
    bool f(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
        // base case
        if (target == 0) return true;
        if (i == 0) return arr[i] == target;

        if (dp[i][target] != -1) return dp[i][target];
        
        bool notpick = f(i-1, target, arr, dp);
        bool pick = false;
        if (arr[i] <= target) pick = f(i-1, target-arr[i], arr, dp);
        
        return dp[i][target] = pick || notpick;
    }
};
```

### Check whether if we can partition array into two subsets of equal sum

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % 2 == 1) return false;
        else {
            int k = sum/2;
            vector<vector<int>> dp(n, vector<int>(k+1,-1));
            return subsetsum(n-1, k, nums, dp);
        }
        return false;
    }
    bool subsetsum(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if (target == 0) return true;
        if (i == 0) return nums[i] == target;
        if (dp[i][target] != -1) return dp[i][target];

        bool notpick = subsetsum(i-1, target, nums, dp);
        
        bool pick = false;
        if (nums[i] <= target) pick = subsetsum(i-1, target-nums[i], nums, dp);

        return dp[i][target] = pick || notpick;
    }
};
```

### Partition Array into 2 subsets with min absolute difference

```cpp
// used tabulation , same approach as subset sum check
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i  = 0; i < n; i++) sum += arr[i];
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        if (arr[0] <= sum) dp[0][arr[0]] = true;
        
        for (int i = 1; i < n; i++) { 
            for (int target = 1; target <= sum; target++) {
                bool notpick = dp[i-1][target];
                bool pick = false;
                if (arr[i] <= target) pick = dp[i-1][target - arr[i]];

                dp[i][target] = notpick || pick;
            }
        }
        
        int mini = 1e9;
        for (int i = 0; i <= sum; i++){
            if (dp[n-1][i] == true){
                int s1 = i;
                int s2 = sum - i;
                int diff = abs(s1 - s2);
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};
```

### Count subsets with sum K, (arr contains non negative elements, 0 included)

```cpp
class Solution {
  public:
    int subsetSumcount(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return count(n-1, target, arr, dp);
    }
    int count(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        } // as there will be elements 0 also, the base case changes slightly
        /* If only positive integers in array.
           if (target == 0) return 1;
           if (i == 0) return (arr[0] == target) ? 1 : 0;
        */

        if (dp[i][target] != -1) return dp[i][target];
        
        int notpick = count(i-1, target, arr, dp);
        int pick = 0;
        if (arr[i] <= target) pick = count(i-1, target-arr[i], arr, dp);
        
        return dp[i][target] = pick + notpick;
    }
};
```

### Count Partitions with given sum difference d

- S1 + S2 = D   – (i) , S1 >= S2     – (ii)

- If we calculate the total sum of elements of the array (say totSum), we can say that, S1 = totSum - S2  – (iii)

- Now solving for equations (i) and (iii), we can say that  S2 = (totSum - D)/2 , thus our problem becomes `Count Number of subsets with sum (totSum - D)/2`

```cpp
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];
        
        if (sum < d) return 0;
        if ((sum-d) % 2 == 1) return 0;
    
        int s2 = (sum - d)/2;
    
        vector<vector<int>> dp(n, vector<int>(s2+1, -1));
        
        return count(n-1, s2, arr, dp);
    }
    
    int count(int i, int target, vector<int>& arr, vector<vector<int>> &dp){
        if (i == 0){
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }
    
        if (dp[i][target] != -1) return dp[i][target];
        
        int notpick = count(i-1, target, arr, dp);
    
        int pick = 0;
        if (arr[i]<=target) pick = count(i-1, target-arr[i], arr, dp);
        
        return dp[i][target]= pick + notpick;
    }
};
```

### 0/1 Knapsack Problem

```cpp
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1)); // memoziation
        return f(n-1, W, val, wt, dp);
    }
    int f(int i, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if (i == 0){
            if (wt[i] <= w) return val[i];
            else return 0;
        }
        if (dp[i][w] != -1) return dp[i][w];
        
        int notpick = 0 + f(i-1, w, val, wt, dp);
        int pick = INT_MIN;
        if (wt[i] <= w) pick = val[i] + f(i-1, w-wt[i], val, wt, dp);
        
        return dp[i][w] = max(pick, notpick);
    }
};
```
