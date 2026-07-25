# Advanced Dynamic Programming

Advanced DP covers non-linear structures and non-standard state spaces: **Partition DP (MCM)**, **DP on Trees**, and **DP with Bitmasking**.

---

## 1. Partition DP / Matrix Chain Multiplication (MCM) Pattern

### Concept
Used when a sequence (array or string) needs to be partitioned into sub-segments by placing cuts, and the cost of partitioning depends on sub-problems.
**Template**: Loop over chain length $len$, start index $i$, end index $j = i + len - 1$, and partition index $k \in [i, j-1]$.

### Matrix Chain Multiplication (MCM)
- **Problem**: Given dimension array $p$ of size $N$, find minimum scalar multiplications to multiply $N-1$ matrices where matrix $i$ has dimension $p[i-1] \times p[i]$.
- **Intuition**: $dp[i][j]$ stores min operations to multiply matrices from $i$ to $j$. Place cut at $k \in [i, j-1]$. Cost $= dp[i][k] + dp[k+1][j] + p[i-1] \times p[k] \times p[j]$.
- **TC**: $O(N^3)$, **SC**: $O(N^2)$.

```cpp
class Solution {
public:
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len is length of matrix chain
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int steps = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], steps);
                }
            }
        }
        return dp[1][n - 1];
    }
};
```

---

### Burst Balloons (LeetCode 312)

- **Intuition**: Think backwards! Instead of choosing which balloon to burst first, choose which balloon is burst **LAST** in the range `[i, j]`. If balloon $k$ is burst last in `[i, j]`, coins earned $= nums[i-1] \times nums[k] \times nums[j+1] + dp[i][k-1] + dp[k+1][j]$.
- **TC**: $O(N^3)$, **SC**: $O(N^2)$.

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> A;
        A.push_back(1);
        for (int x : nums) A.push_back(x);
        A.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxi = INT_MIN;
                for (int k = i; k <= j; k++) {
                    int coins = A[i - 1] * A[k] * A[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};
```

---

## 2. DP on Trees

### House Robber III (LeetCode 337)

- **Problem**: Binary tree where nodes are houses. Cannot rob two directly-linked houses. Maximize total value.
- **Intuition**: Return a pair `{robThis, skipThis}` for each subtree.
  - `robThis = node->val + left.skipThis + right.skipThis`
  - `skipThis = max(left.robThis, left.skipThis) + max(right.robThis, right.skipThis)`
- **TC**: $O(N)$, **SC**: $O(H)$.

```cpp
class Solution {
public:
    // returns {robCurrentNode, skipCurrentNode}
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int robCurrent = root->val + left.second + right.second;
        int skipCurrent = max(left.first, left.second) + max(right.first, right.second);

        return {robCurrent, skipCurrent};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
```

---

## 3. DP with Bitmasking

### Travelling Salesperson Problem (TSP)

- **Problem**: Visit $N$ cities starting from city $0$, returning to city $0$ with minimum path cost.
- **Intuition**: State `dp(mask, u)` represents minimum cost to visit remaining unvisited cities (given by bitmask `mask`) starting from current city `u`.
- **Bitmask representation**: $i$-th bit of `mask` is 1 if city $i$ has been visited, 0 otherwise. Full mask with all cities visited $= (1 \ll N) - 1$.
- **TC**: $O(N^2 \cdot 2^N)$, **SC**: $O(N \cdot 2^N)$.

```cpp
class Solution {
    int n;
    int FULL_MASK;
    vector<vector<int>> dp;

public:
    int solve(int mask, int u, vector<vector<int>>& dist) {
        if (mask == FULL_MASK) {
            return dist[u][0]; // Return to starting city 0
        }
        if (dp[mask][u] != -1) return dp[mask][u];

        int ans = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!(mask & (1 << v))) { // If city v not visited
                int cost = dist[u][v] + solve(mask | (1 << v), v, dist);
                ans = min(ans, cost);
            }
        }
        return dp[mask][u] = ans;
    }

    int total_cost(vector<vector<int>>& dist) {
        n = dist.size();
        FULL_MASK = (1 << n) - 1;
        dp.assign(1 << n, vector<int>(n, -1));

        return solve(1, 0, dist); // Start at city 0 with mask 1
    }
};
```
