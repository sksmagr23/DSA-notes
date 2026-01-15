### Longest Common Subsequence (LCS) in two strings
- A subsequence of a string is a list of characters of the string where some characters are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original string.
- For a string of length n, the number of subsequences will be 2n.

`Memoization`
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

`Tabulation`
```cpp
class Solution{
public:
    int longestCommonSubsequence(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 

        // base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }
        // Fill in the DP table
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= m; i2++) {
                
                // Characters match, increment LCS length
                if (s1[i1 - 1] == s2[i2 - 1]) dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1]; 

                // Characters don't match, consider the maximum from left or above 
                else dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]); 
            }
        }
        return dp[n][m]; 
    }
};
```

### Print Longest Common Subsequence (LCS) of two strings

- similar after last question when we create a 2D DP table to store lengths of longest common subsequence, then we backtrack and construct the LCS string from dp[n][m] to find the actual LCS string.
  
```cpp
class Solution {
public:
    string longestCommonSubsequence(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill dp table using bottom-up
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct LCS string from dp table
        int i = n, j = m;
        string lcs = "";

        // Traverse dp table from bottom-right to top-left
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match, add to result and move diagonally
                lcs += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;   // Move up if top cell has greater value
            } else {
                j--;   // Move left otherwise
            }
        }

        reverse(lcs.begin(), lcs.end()); // Reverse string since it was built backwards
        return lcs;
    }
};
```

### Longest Common Substring

```cpp
class Solution {
public:
    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();  
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLen = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) { // Characters match, increment substring length
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLen = max(maxLen, dp[i][j]);
                } else {
                    dp[i][j] = 0; // Reset since substring must be contiguous
                }
            }
        }
        return maxLen;
    }
};
```

### Longest Palindromic Subsequence

- we reverse the given string and find the LCS between the original string and the reversed string.

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int i = 0; i < n; i++) dp[i][0] = 0;
        for (int i = 0; i < n; i++) dp[0][i] = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
```

### Minimum insertions to make string palindrome

- In order to minimize the insertions, we need to find the length of the longest palindromic component or in other words, the longest palindromic subsequence. Minimum Insertion required = n(length of string) - length of longest palindromic subsequence.

```cpp
class Solution {
public:
    int lcs(string s, string t){
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for (int i = 0; i < n; i++) dp[i][0] = 0;
        for (int i = 0; i < n; i++) dp[0][i] = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        int l = lcs(s, t);
        return n - l;
    }
};
```

