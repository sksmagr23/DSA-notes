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


