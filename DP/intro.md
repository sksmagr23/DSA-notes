## What is Dynamic Programming?

Dynamic Programming (DP) is a technique for solving problems by **breaking them down into overlapping sub-problems**, solving each sub-problem once, and storing their results for future use.

> **Goal:** Avoid redundant computations and improve efficiency.

---

### There are two primary approaches to dynamic programming:

### 1. **Memoization (Top-Down)**

- Recursive + cache (usually a `dp[]` array).
- Start solving from the main problem → break down to base cases.
- Store answers to sub-problems when first computed.
- Use them when needed again.

### 2. **Tabulation (Bottom-Up)**

- Iterative + table (typically a `dp[]` array).
- Solve from base cases up to the main problem.
- Eliminate recursion and stack overhead.

> **Note:** Base case doesn't always mean smallest input — it depends on the recursion logic.

---

## Fibonacci Numbers
```
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```
> Find the **nth Fibonacci number** where:
> 
> - `F(0) = 0`, `F(1) = 1`
> - `F(n) = F(n-1) + F(n-2)` for `n >= 2`

---

## 1: Memoization (Top-Down DP)

#### Steps:

1. Create a `dp[]` array initialized with `-1`
2. On each function call:
   - Return `dp[n]` if already computed
   - Otherwise, compute using recursion and store in `dp[n]`

```cpp
int fib(int n, vector<int>& dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main() {
    int n = 5;
    vector<int> dp(n+1, -1);
    cout << fib(n, dp);
    return 0;
}
```

#### Output:

```
5
```

#### Time Complexity: `O(N)`

#### Space Complexity: `O(N)`

---

## 2: Tabulation (Bottom-Up DP)

#### Steps:

1. Create a `dp[]` array of size `n+1`.
2. Initialize base cases:  
   - `dp[0] = 0`  
   - `dp[1] = 1`
3. Loop from `i = 2` to `n` and compute:
   - `dp[i] = dp[i-1] + dp[i-2]`

```cpp
int main() {
    int n = 5;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
    return 0;
}
```

#### Output:
```
5
```

#### Time Complexity: `O(N)`

#### Space Complexity: `O(N)`

---

## 3: Space Optimization

#### Observation:

We only need the last **two** values at any point (`dp[i-1]`, `dp[i-2]`).

So instead of a full `dp[]` array, we can use two variables:

```cpp
int main() {
    int n = 5;
    int prev2 = 0;
    int prev = 1;

    for(int i = 2; i <= n; i++) {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }

    cout << prev;
    return 0;
}
```

#### Output:
```
5
```

#### Time Complexity: `O(N)`

#### Space Complexity: `O(1)`

---

## 1D DP;

### Frog Jump Min cost (1 or 2 step and energy diff)

```cpp
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1, -1);
        return mincostdp(n-1, height, dp);
    }
    int mincostdp(int i, vector<int> &height, vector<int> &dp){
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];
        int jtwo = INT_MAX;
        int jone = mincostdp(i-1, height, dp) + abs(height[i]-height[i-1]);
        if (i > 1) jtwo = mincostdp(i-2, height, dp) + abs(height[i]-height[i-2]);
        dp[i] = min(jone, jtwo);
        return dp[i];
    }
};
```

### Maximum sum of non-adjacent elements

```cpp
class Solution {
public:
    int maxsum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return adjdp(n-1, nums, dp);
    }
    int adjdp(int i, vector<int> &nums, vector<int> &dp){
        if (i == 0) return nums[0];
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];
        int pick = nums[i] + adjdp(i-2, nums, dp);
        int notpick = 0 + adjdp(i-1, nums, dp);
        return dp[i] = max(pick, notpick);
    }
};
```

## 2D DP

### Ninja Training(striver)

```cpp
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> dp(n, vector<int>(4,-1)); // 4 choices to pick
        return f(n-1, 3, points, dp);
    }
    int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
        if (dp[day][last] != -1) return dp[day][last];
        if (day == 0){
            int maxi = 0;
            for (int i = 0; i <= 2; i++) {
                if (i != last) maxi = max(maxi, points[0][i]);
            }
            return dp[day][last] = maxi;   
        }
        int maxi = 0;
        for (int i = 0; i <=2; i++){
            if (i != last){
                int activity = points[day][i] + f(day-1, i, points, dp);
                maxi = max(maxi, activity);
            }
        }
        return dp[day][last] = maxi;
    }
};
```

### Unique paths in Grids(from top-left to bottom-right)

```cpp
class Solution {
public:
    // top-down memoziation
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // initially at bottom-right
        return gridpaths(m-1, n-1, dp);
    }
    int gridpaths(int i, int j, vector<vector<int>> &dp){
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0; // out of bounds
        if (dp[i][j] != -1) return dp[i][j];
        int up = gridpaths(i-1, j, dp);
        int left = gridpaths(i, j-1, dp);
        return dp[i][j] = up + left;
    }
};
```
