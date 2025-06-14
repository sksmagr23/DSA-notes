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

> ⚠️ **Note:** Base case doesn't always mean smallest input — it depends on the recursion logic.

---

## 📌 Problem Example: Fibonacci Numbers
```
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```
> Find the **nth Fibonacci number** where:
> 
> - `F(0) = 0`, `F(1) = 1`
> - `F(n) = F(n-1) + F(n-2)` for `n >= 2`

---

## 🧩 Part 1: Memoization (Top-Down DP)

### ✅ Steps:

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

### ✅ Output:
```
5
```

### ⏱ Time Complexity: `O(N)`

### 💾 Space Complexity: `O(N)`

---

## 🧩 Part 2: Tabulation (Bottom-Up DP)

### ✅ Steps:

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

### ✅ Output:
```
5
```

### ⏱ Time Complexity: `O(N)`

### 💾 Space Complexity: `O(N)`

---

## 🧩 Part 3: Space Optimization

### 🔄 Observation:

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

### ✅ Output:
```
5
```

### ⏱ Time Complexity: `O(N)`

### 💾 Space Complexity: `O(1)`

---