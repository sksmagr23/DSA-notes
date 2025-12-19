## Trie Implementation - I

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

