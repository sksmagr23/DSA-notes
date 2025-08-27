# Trie Data Structure

A **Trie** (also called a **Prefix Tree**) is a tree-like data structure that is used to store a collection of strings efficiently. Each node represents a character, and paths from the root to nodes represent prefixes of stored strings.

## Key Properties

- The root represents an empty string
- Each path from root to a node represents a prefix
- Nodes can be marked as "end of word" to indicate complete strings
- All descendants of a node share a common prefix

## Basic Trie Implementation

```cpp
class TrieNode {
public:
    TrieNode* children[26]; // for lowercase a-z
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the trie
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    
    // Search for a word in the trie
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }
    
    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
    
    // Delete a word from the trie
    bool deleteWord(string word) {
        return deleteHelper(root, word, 0);
    }
    
private:
    bool deleteHelper(TrieNode* node, string word, int index) {
        if (index == word.length()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return !hasChildren(node);
        }
        
        int charIndex = word[index] - 'a';
        TrieNode* child = node->children[charIndex];
        if (child == nullptr) return false;
        
        bool shouldDeleteChild = deleteHelper(child, word, index + 1);
        
        if (shouldDeleteChild) {
            delete child;
            node->children[charIndex] = nullptr;
            return !node->isEndOfWord && !hasChildren(node);
        }
        
        return false;
    }
    
    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) return true;
        }
        return false;
    }
};
```

## Time Complexity

- **Insert**: O(m) where m is the length of the word
- **Search**: O(m) where m is the length of the word  
- **StartsWith**: O(m) where m is the length of the prefix
- **Delete**: O(m) where m is the length of the word

## Space Complexity

- O(ALPHABET_SIZE * N * M) where N is number of words and M is average length

## Common Trie Problems

### 1. Word Search II (Leetcode 212)

Find all words from a dictionary that can be formed in a 2D board.

```cpp
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        
        vector<string> result;
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, trie.root, "", result);
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, 
             string word, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || 
            board[i][j] == '#') return;
        
        char c = board[i][j];
        int index = c - 'a';
        if (node->children[index] == nullptr) return;
        
        node = node->children[index];
        word += c;
        
        if (node->isEndOfWord) {
            result.push_back(word);
            node->isEndOfWord = false; // avoid duplicates
        }
        
        board[i][j] = '#'; // mark as visited
        
        // explore all 4 directions
        dfs(board, i+1, j, node, word, result);
        dfs(board, i-1, j, node, word, result);
        dfs(board, i, j+1, node, word, result);
        dfs(board, i, j-1, node, word, result);
        
        board[i][j] = c; // backtrack
    }
};
```

### 2. Maximum XOR of Two Numbers (Leetcode 421)

```cpp
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        
        // Insert all numbers into trie
        for (int num : nums) {
            TrieNode* curr = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (curr->children[bit] == nullptr) {
                    curr->children[bit] = new TrieNode();
                }
                curr = curr->children[bit];
            }
        }
        
        int maxXor = 0;
        
        // For each number, find maximum XOR
        for (int num : nums) {
            TrieNode* curr = root;
            int currentXor = 0;
            
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int oppositeBit = 1 - bit;
                
                if (curr->children[oppositeBit] != nullptr) {
                    currentXor |= (1 << i);
                    curr = curr->children[oppositeBit];
                } else {
                    curr = curr->children[bit];
                }
            }
            
            maxXor = max(maxXor, currentXor);
        }
        
        return maxXor;
    }
};
```

### 3. Replace Words (Leetcode 648)

Replace words with their shortest root from dictionary.

```cpp
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string root : dictionary) {
            trie.insert(root);
        }
        
        stringstream ss(sentence);
        string word, result;
        
        while (ss >> word) {
            if (!result.empty()) result += " ";
            result += trie.getShortestRoot(word);
        }
        
        return result;
    }
    
private:
    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string word) {
            TrieNode* curr = root;
            for (char c : word) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->isEndOfWord = true;
        }
        
        string getShortestRoot(string word) {
            TrieNode* curr = root;
            string result = "";
            
            for (char c : word) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    return word; // no root found
                }
                curr = curr->children[index];
                result += c;
                
                if (curr->isEndOfWord) {
                    return result; // found shortest root
                }
            }
            
            return word; // no root found
        }
    };
};
```

## Applications

1. **Autocomplete/Search Suggestions**: Efficiently find all words with a given prefix
2. **Spell Checkers**: Check if a word exists and suggest corrections
3. **IP Routing**: Store and lookup IP addresses efficiently
4. **DNA Sequencing**: Store and search DNA sequences
5. **Compression Algorithms**: Huffman coding and other compression techniques