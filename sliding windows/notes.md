## Longest Substring length Without Duplicate Characters
```cpp
int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int maxlen = INT_MIN;
        unordered_set<int> st;
        int l = 0;
        for (int r =0; r < s.length(); r++){
            if (st.find(s[r]) != st.end()){
                while (l < r && st.find(s[r]) != st.end()){
                    st.erase(s[l]);
                    l++ ;
                }
            }
            st.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
```