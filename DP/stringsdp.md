# DP on Strings

Dynamic Programming problems involving strings often deal with finding optimal subsequences, substrings, or transformations between strings.

## Common String DP Patterns

1. **Two Strings Comparison**: LCS, Edit Distance
2. **Single String Analysis**: Longest Palindromic Subsequence
3. **Pattern Matching**: Wildcard Matching, Regular Expression
4. **Partitioning**: Palindrome Partitioning

---

### Longest Common Subsequence in two strings

- A subsequence of a string is a list of characters of the string where some characters are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original string.
- For a string of length n, the number of subsequences will be 2^n.

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

### Edit Distance (Levenshtein Distance)

Find minimum operations (insert, delete, replace) to convert string s1 to s2.

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
    
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // Base cases
        if (i < 0) return j + 1; // Insert all remaining chars of s2
        if (j < 0) return i + 1; // Delete all remaining chars of s1
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i] == s2[j]) {
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        } else {
            int insert = 1 + f(i, j-1, s1, s2, dp);
            int delete_op = 1 + f(i-1, j, s1, s2, dp);
            int replace = 1 + f(i-1, j-1, s1, s2, dp);
            return dp[i][j] = min({insert, delete_op, replace});
        }
    }
};
```

### Longest Common Substring

Find the longest contiguous substring common to both strings.

```cpp
class Solution {
public:
    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int maxLength = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return maxLength;
    }
};
```

### Longest Palindromic Subsequence

Find the length of the longest palindromic subsequence in a string.

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return longestCommonSubsequence(s, rev);
    }
    
    // Alternative direct approach
    int longestPalindromeSubseqDirect(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, s, dp);
    }
    
private:
    int f(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + f(i+1, j-1, s, dp);
        } else {
            return dp[i][j] = max(f(i+1, j, s, dp), f(i, j-1, s, dp));
        }
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
```

### Minimum Insertions to Make String Palindrome

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int lps = longestPalindromeSubseq(s);
        return n - lps;
    }
    
private:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return longestCommonSubsequence(s, rev);
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
```

### Wildcard Pattern Matching

Match string with pattern containing '?' (single character) and '*' (zero or more characters).

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, p, dp);
    }
    
private:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // Base cases
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;
        if (i < 0 && j >= 0) {
            // Check if remaining pattern is all '*'
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        } else if (p[j] == '*') {
            return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        } else {
            return dp[i][j] = false;
        }
    }
};
```

### Palindrome Partitioning II (Minimum Cuts)

Find minimum cuts needed to partition string into palindromes.

```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1; // -1 because we don't need cut after last partition
    }
    
private:
    int f(int i, string& s, vector<int>& dp) {
        if (i == s.size()) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        int minCuts = INT_MAX;
        
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                int cuts = 1 + f(j + 1, s, dp);
                minCuts = min(minCuts, cuts);
            }
        }
        
        return dp[i] = minCuts;
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
```

### Distinct Subsequences

Count number of distinct subsequences of s which equals t.

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n, vector<double>(m, -1));
        return (int)f(n-1, m-1, s, t, dp);
    }
    
private:
    double f(int i, int j, string& s, string& t, vector<vector<double>>& dp) {
        if (j < 0) return 1; // Empty target can be formed in 1 way
        if (i < 0) return 0; // Non-empty target cannot be formed from empty source
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) {
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        } else {
            return dp[i][j] = f(i-1, j, s, t, dp);
        }
    }
};
```