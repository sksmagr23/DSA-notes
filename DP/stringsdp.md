### Longest Common Subsequence in two strings
- A subsequence of a string is a list of characters of the string where some characters are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original string.
- For a string of length n, the number of subsequences will be 2n.

```cpp
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s1, s2, dp);
    }
    // f(ind1, ind2) → Longest common subsequence of S1[0...ind1] and S2[0...ind2]
    int f(int i1, int i2, string s1, string s2, vector<vector<int>>& dp){
        if (i1 < 0 || i2 < 0) return 0;
        if (dp[i1][i2] != -1) return dp[i1][i2];
        if (s1[i1] == s2[i2]) {
            return dp[i1][i2] = 1 + f(i1-1, i2-1, s1, s2, dp);
        } else {
            return dp[i1][i2] = max(f(i1-1, i2, s1, s2, dp), f(i1, i2-1, s1, s2, dp));
        }    
    }
};
```