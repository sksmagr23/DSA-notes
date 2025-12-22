## Trie Implementation - I

![Trie](https://media.geeksforgeeks.org/wp-content/uploads/20250417113106950395/Triedatastructure1.webp)

The **Trie** data structure is used to store a set of keys represented as strings. It allows for efficient retrieval and storage of keys, making it highly effective in handling large datasets. Trie supports operations such as insertion, search, deletion of keys, and prefix searches.
A **Trie node** is a basic element used to build a Trie, consisting of:
- ***Child Node Links***: An array of pointers for each letter of the alphabet. Each pointer corresponds to a child node representing a letter. For example, index 0 points to 'a', index 1 to 'b', and so on.
- ***End-of-Word Flag***: A boolean flag that indicates if the node marks the end of a word, differentiating between prefixes and full words.

##### Key Functions for a Trie Node:
1. *Contains Key*: Checks if a specific letter exists as a child node of the current Trie node.
2. *Get Child Node*: Retrieves the child node corresponding to a given letter from the current Trie node.
3. *Put Child Node*: Creates a link between the current node and a child node representing a specific letter.
4. *Set End Flag*: Marks the current node as the end of a word by setting the end flag to true.
5. *Is End of Word*: Checks if the current node is the end of a word by examining the end flag.

- To implement Trie class with insert word, search word & startsWith the given prefix.

```cpp
// Node Structure for Trie
struct Node {
    Node* links[26] = {nullptr};  // Array to store links to child nodes, each index represents a letter
    bool flag = false; // flag indicating if the node marks the end of word 

    // Check if the node contains a specific key (letter)
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    // Insert a new node with a specific key into the Trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    // Get the node with a specific key from the Trie
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    // Set the current node as the end of a word
    void setEnd() {
        flag = true;
    }
    // Check if the current node marks the end of a word
    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;

    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node();
    }
    
    // Inserts a word into the Trie in O(N)
    void insert(string word) {
        Node* node = root; // start from root node
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node()); // Create a new node for the letter if not present
            }
            node = node->get(ch); // Move to the next node
        }
        node->setEnd(); // Mark the end of the word
    }
    
    // Returns true if the word is in the trie
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false; // letter not found 
            }
            node = node->get(ch);
        }
        return node->isEnd(); // Check if the last node marks the end of a word
    }
    
    // Returns True if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true; // Prefix Found
    }
};
```

- TC :- ``O(N)`` for all operations.

### Trie Implementation - II

In Trie , we have to implement the following:-
- insert(“WORD”): Insert the string “WORD” into the trie
- countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in trie.
- countWordsStartingWith(“PREFIX”): Return how many words are there in the trie that have the string “PREFIX” as a prefix.
- erase(“WORD”): Delete one occurrence of the string “WORD” from the trie.

```cpp
struct Node {
    Node* links[26]; // child links

    int cntEndWith = 0; // Counter for no. of words that end at this node

    int cntPrefix = 0; // Counter for no. of words that have this node as a prefix

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Func to increment the count of words that end at this node
    void increaseEnd() {
        cntEndWith++;
    }
    // Func to increment the count of words that have this node as a prefix
    void increasePrefix() {
        cntPrefix++;
    }
    // Func to decrement the count of words that end at this node
    void deleteEnd() {
        cntEndWith--;
    }
    //Func to decrement the count of words that have this node as a prefix
    void reducePrefix() {
        cntPrefix--;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            // Increment the prefix count for the node
            node->increasePrefix();
        }
        // Increment the end count for the last node of the word
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]); // move to the child
            } else {
                // character is not found
                return 0;
            }
        }
        // Return the count of words ending at the node
        return node->cntEndWith;
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        // Return the count of words with the prefix
        return node->cntPrefix;
    }

    void erase(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                // Decrement the prefix count for the node
                node->reducePrefix();
            } else {
                return;
            }
        }
        // Decrement the end count for the last node of the word
        node->deleteEnd();
    }
};
```

### Longest String with All Prefixes

- Problem: Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one.

```cpp
struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++){
            if (!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool foundAllPrefix(string word){
        Node* node = root;
        for (char ch : word){
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
            if (!node->isEnd()) return false; // prefix not marked as end
        }
        return true;
    }
};

class Solution {
public:    
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for (auto it : words){
            trie.insert(it);
        }
        
        string ans = "";
        for (auto it : words){
            if (trie.foundAllPrefix(it)){
                if (it.size() > ans.size()) ans = it;
                else if (it.size() == ans.size() && it < ans) ans = it;
            }
        }
        return ans;
    }
};
```

### Number of Distinct Substrings in a String Using Trie

- Using a Trie data structure significantly reduces the number of comparisons needed as we traverse the substring, resulting in better performance. The Trie also uses memory efficiently by storing only the necessary information and avoids redundancy by sharing common prefixes among substrings for better space utilisation especially for long strings with many repeated substrings.

```cpp
struct Node {
    Node* links[26] = {nullptr};

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size();
        Node* root = new Node();
        int count = 0;
        for (int i = 0; i < n; i++){
            Node* node = root;
            for (int j = i; j < n; j++){
                if (!node->containsKey(s[j])){
                    node->put(s[j], new Node());
                    count++; // Increment the counter since a new substring is found
                }
                node = node->get(s[j]);
            }
        }
        return count + 1; // +1 for empty substring
    }
};
```

### Bit PreRequisites

- <u>Binary Representation</u>
  - A standard 32-bit integer is represented as a sequence of bits from index 31 (Most Significant Bit - **MSB**) to index 0 (Least Significant Bit - **LSB**).
  - In Trie problems ,numbers are often treated as strings of bits. We represent them from the MSB to the LSB to build the Trie branches.

- <u>XOR Operation</u>(^)
  - Rule: The result is 1 if the bits are different, and 0 if they are the same.
  - `0 ^ 0 = 0` , `1 ^ 1 = 0` , `0 ^ 1 = 1` , `1 ^ 0 = 1`
  - If there are an even number of 1s , XOR will result in 0. If there are an odd number of 1s, XOR will result in 1. 
  - Key Property: `A ^ B = C` implies `A ^ C = B`

- ***How to Check if a Bit is Set***
  - *A bit is "set" if it is 1*. To check if the *i*-th bit of a number N is set:- Right Shift the *i*-th bit to the 0th position and checks if it is 1 using bitwise AND. ```(N >> i) & 1```
  - ```(N >> i) & 1``` gives the bit at ith position

- ***How to Turn On a Bit***
  - *To "turn on" a bit means to set it to 1.* To turn on the *i*-th bit of a number N:- Use the bitwise OR operator with a mask where only the *i*-th bit is 1. ```N | (1 << i)```

