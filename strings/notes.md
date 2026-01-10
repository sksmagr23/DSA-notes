### Reverse Words in a String

- Given an input string s, reverse the order of the words. The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space without any leading or trailing spaces.

```cpp
class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        stack<string> st;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) st.push(str);
                str = "";
            } else {
                str += s[i];
            }    
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " ";
        }
        return ans;
    }
};
```

### Valid Anagram

- An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> hash1;
        map<char, int> hash2;

        for (char c : s) hash1[c]++;

        for (char c : t) hash2[c]++;

        return hash1 == hash2;
    }
};
```

### Roman to integer

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }
        return res + roman[s.back()];
    }
};
```

---

### Count Palindromic Substrings - Expand Around Center

- *Intution*:- `Every palindrome has a center. For each index, treat it as the center of an odd-length palindrome and the gap after it as the center of an even-length palindrome. Expand outward while characters match, and count each valid expansion as one palindromic substring.`
  
```cpp
class Solution {
public:
    void expandAroundCenter(string s, int l, int r, int &count) {
        int n = s.size();
        // Keep expanding while indices are inside bounds & characters at left and right are equal
        while (l >= 0 && r < n && s[l] == s[r]) {
            count++;
            l--;       // Expand left
            r++;       // Expand right
        }
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            expandAroundCenter(s, i, i, count); // Odd length (single character center)
            expandAroundCenter(s, i, i + 1, count); // Even length (center between two characters)
        }
        return count;
    }
};
```

### Longest Palindromic Substring (using dp)

```cpp
class Solution {
public:
    string longestPalindrome(string s) { // Tabulation
        int n = s.size();
        if (n == 1) return s;
        int start = 0, maxlen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // dp[i][j] = true if substring s[i..j] is a palindrome

        for (int i = 0; i < n; ++i) dp[i][i] = true; // length 1

        for (int i = 0; i < n - 1; ++i) { // for length 2
            if (s[i] == s[i + 1]) { // Two characters form a palindrome if both are equal
                dp[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }
        
        // We increase length gradually so dp[i+1][j-1] is already computed
        for (int len = 3; len <= n; ++len) { // for length >= 3
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) { // if outer characters match and inner substring is palindrome
                    dp[i][j] = true;
                    start = i;
                    maxlen = len;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
```

### Count palindromic subsequence in given string

```cpp
class Solution {
public:
    int countPalindromicSubsequences(string s) { // Tabulation
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1; // If characters match

                else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]; // Remove overlapping part
            }
        }
        return dp[0][n - 1];
    }
};
```

### Count number of substrings that contain exactly k distinct characters.

```cpp
// Function to count substrings with at most k distinct characters
int atMostKDistinct(string s, int k) {
    int l = 0;
    int res = 0;
    unordered_map<char, int> mpp;

    for (int r = 0; r < s.size(); r++) {
        mpp[s[r]]++;

        while (mpp.size() > k) {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        res += (r - l + 1);
    }
    return res;
}

// Function to count substrings with exactly k distinct characters
int countSubstrings(string s, int k) {
    // Exactly k = atMost(k) - atMost(k-1)
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}
```

---

## Hashing in Strings

- Hashing refers to the process of converting a string into a numeric value, called a hash value, using a mathematical formula. Hashing is essential as it helps in following operations:-
1. ***Efficient Comparisons***: Comparing large strings is slow. Hash values allow comparison in constant time.
2. ***Faster Lookups***: Hash tables like dictionaries or unordered maps use hash values to store and retrieve strings quickly.
3. ***Detect Duplicates or Anagrams***: Hashing helps in checking duplicates or determining anagram groups efficiently.
4. ***Pattern Matching***: Algorithms like Rabin-Karp use string hashing to find substrings in linear time.

### Hashing Calculation

- String hashing treats each character as a number and combines them using a mathematical formula. A common formula is Polynomial Rolling Hash Function

***Hash(s) = (s[0] * p<sup>0</sup> + s[1] * p<sup>1</sup> + s[2] * p<sup>2</sup> + ... + s[n-1] * p<sup>n-1</sup>) % m***

where, s[i] is the character's ASCII or mapped value (like 'a' = 1),
p is a prime base (commonly 31 or 53) &
m is a large prime modulus to avoid overflow and reduce collisions.

- **Collisions** :- Two different strings can have the same hash, called a collision. To reduce this, we use a large m (like 1e9+7). We can also use double hashing (combine two different hash functions) or use a good base (p) that spreads values well.

```cpp
int findHash(string s) {
    int n = s.length();

    int p = 31, m = 1e9 + 7; // p is a prime number & m is a large prime number

    int hash = 0; // to store hash value

    int pPow = 1; // to store p^i

    for (int i = 0; i < n; ++i) {
        hash = (hash + (s[i] - 'a' + 1) * pPow) % m;
        pPow = (pPow * p) % m;
    }
    return hash;
}
```

- ##### Calculation of Hashes of any substring of a given string in O(1) :-
  ***hash[i...j] * p<sup>i</sup> = hash[j +1] − hash[i]***

### <u>Rabin-Karp Algorithm</u>

- It is a *string matching algorithm* that uses *rolling hash* to find all occurrences of a pattern (s) in a text(t)
- used in Optimization for cases where multiple patterns or repeated matching is required
- Instead of comparing actual characters every time (Naive approach of O(s x t)), it converts both the pattern and parts of the text into numbers (hashes) and compares those numbers. This way, most of the time it can detect mismatches without looking at every character, making it much faster and scalable ***(O(s + t))***.

- Problem: Given two strings - a pattern s and a text t , determine if the pattern appears in the text and if it does, return all the indexes of occurences of s in t.

```cpp
vector<int> rabin_karp(string &s, string &t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    int n = max(S, T);

    vector<long long> p_pow(n); 
    p_pow[0] = 1; 
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    vector<long long> h(T+1, 0); // Prefix hash array for text t
    for (int i = 0; i < T; i++) {
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; // h[i] = hash of substring t[0 .. i-1]
    }

    long long h_s = 0; // Hash of the pattern string s
    for (int i = 0; i < S; i++) {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
    }

    vector<int> ans;
    for (int i = 0; i + S - 1 < T; i++) { // Slide window of length S over text t
        long long cur_h = (h[i+S] - h[i] + m) % m; // S = j - i + 1;
        if (cur_h == h_s * p_pow[i] % m){
            ans.push_back(i);
        }
    }
    return ans;
}
```

> Sometimes, We still compare the actual characters even after a hash match because different strings can sometimes produce the same hash value.

### <u>KMP algorithm</u> 
[GFG article](https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching)

- The *Knuth-Morris-Pratt (KMP)* algorithm is an efficient *string matching algorithm* used to search for a pattern within a text
- The KMP algorithm works by preprocessing the pattern using an auxiliary array called **LPS (Longest Prefix Suffix)**. This array stores the length of the longest proper prefix which is also a suffix for every prefix of the pattern. When a mismatch occurs, KMP uses this information to shift the pattern intelligently, skipping over positions that are guaranteed not to match — instead of starting over. This ensures that each character in the text is compared at most once, reducing the T.C. to O(n + m).

- ***Proper Prefix*** : A proper prefix of a string is a prefix that is not equal to the string itself. ex. proper prefixes of "abcd" are: "", "a", "ab", and "abc".

- #### Construction of LPS Array O(N)
  - The LPS array stores, for every position in the pattern, the length of the longest proper prefix which is also a suffix of the substring ending at that position.
  - lps[i] -> longest proper prefix of s[0...i] which is also a suffix.
- Basic ideas:-
  - If len = lps[i-1] & s[len] and s[i] are same, then lps[i] = len + 1, len++;
  - If s[len] and s[i] do not match :
    (a) if len == 0, then lps[i] = 0 
    (b) else len = lps[len - 1], and then compare s[len] and s[i]

```cpp
vector<int> computeLPSArray(string &s) {
    int n = s.size();
    vector<int> lps(n, 0); // lps[0] is always 0
        
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else {
            if (len == 0) {  
                lps[i] = 0;
                i++;
            } else {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}
```

- The KMP algorithm works in two main steps:-
  1. Preprocessing Step – Build the LPS Array
  2. Matching Step – Search the Pattern in the Text

- T.C :- `O(n + m)`

```cpp
void constructLps(string &pat, vector<int> &lps) {

    lps[0] = 0;
    int len = 0;
    int i = 1;

    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else {
            if (len == 0) {  
                lps[i] = 0;
                i++;
            } else {
                len = lps[len - 1];
            }
        }
    }    
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    constructLps(pat, lps);

    vector<int> res;

    int i = 0; // for traversing the text
    int j = 0; // for traversing the pattern

    while (i < n) {
        if (txt[i] == pat[j]) { // If characters match, move both pointers forward
            i++;
            j++;
            // If the entire pattern is matched store the start index and continue searching
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j == 0)
                i++;
            else
                j = lps[j - 1]; // Use lps value of previous index to avoid redundant comparisons
        }
    }
    return res;
}
```
