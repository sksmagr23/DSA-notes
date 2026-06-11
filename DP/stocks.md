### Best Time to Buy and Sell Stock II

- You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock. Return the maximum profit you can achieve.

```cpp
class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        if (i == n) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if (buy == 0){
            // We can either skip buying today, or buy today and move to sell state
            profit = max(0 + f(i+1, 0, prices, dp), -prices[i] + f(i+1, 1, prices, dp));
        }
        if (buy == 1){
            // We can either skip selling today, or sell today and move back to buy state
            profit = max(0 + f(i+1, 1, prices, dp), prices[i] + f(i+1, 0, prices, dp));
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][buy] stores max profit from day i with buy/sell state
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 0, prices, dp); // start from day 0 with buy state allowed
    }
};
```

### Best Time to Buy and Sell Stock IV (with atmost K transactions)

- You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve. Similar constraints as previous problem, only in this case we may complete at most K transactions.

```cpp
class Solution {
public:
    int f(int i, int buy, int left, vector<vector<vector<int>>>& dp, vector<int>& prices){
        int n = prices.size();
        if (i == n || left == 0) return 0;
        if (dp[i][buy][left] != -1) return dp[i][buy][left];

        int profit = 0;
        if (buy == 0) {
            profit = max(0 + f(i+1, 0, left, dp, prices), -prices[i] + f(i+1, 1, left, dp, prices));
        }
        if (buy == 1) { 
            profit = max(0 + f(i+1, 1, left, dp, prices), prices[i] + f(i+1, 0, left-1, dp, prices));
        }

        return dp[i][buy][left] = profit;
    }
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // dp[i][buy][left] stores max profit from day i with buy/sell state and remaining transactions
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 0, k, dp, prices);
    }
};
```

---