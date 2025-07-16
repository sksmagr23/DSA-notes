# Binary Trees

**Binary Tree:** Hierarchical data structure; each node has at most 2 children (left, right).
**Node:** Contains data and pointers to left/right children.
**Root Node:** Topmost node; entry point to the tree.
**Children:** Nodes directly connected to a parent node.
**Leaf Node:** Node with no children (terminal node).
**Ancestor:** Any node on the path from a node to the root.

## Types of Binary Trees

**Full Binary Tree:** Every node has 0 or 2 children (no node with only 1 child).
**Complete Binary Tree:** All levels filled except possibly last, which is filled left to right.
**Perfect Binary Tree:** All internal nodes have 2 children, all leaves at same level, all levels fully filled.
**Balanced Binary Tree:** Heights of left/right subtrees of any node differ by at most 1; height ≈ log₂N.
**Degenerate Tree:** Each parent has only one child; tree becomes a linear chain (like a linked list).

## Binary Tree in Cpp

```cpp
#include <iostream>

// Node Constructor
struct Node {
    int data;        
    Node* left;   // Reference pointer to the left child node
    Node* right;  // Reference pointer to the right child node

    Node(int val) {
        data = val;   
        left = right = NULL;  
    }
};

int main() {
    // Creating a new node for the root of the binary tree using dynamic allocation
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
}
```

## Binary Tree Traversals

### Traversal Types

- **DFS (Depth-First Search):**
  - Explores as deep as possible before backtracking.
  - Types:
    - **Inorder (L, Root, R):** Left subtree → Node → Right subtree
    - **Preorder (Root, L, R):** Node → Left subtree → Right subtree
    - **Postorder (L, R, Root):** Left subtree → Right subtree → Node
  - DFS uses recursion or a stack to traverse deeper levels of the tree before visiting nodes at the same level.

- **BFS (Breadth-First Search):**
  - Visits nodes level by level (Level Order Traversal).Nodes at a level are visited from left to right.
  - Uses a queue to process nodes at each level

### Traversing Binary tree from given root to array

#### 1. Inorder Traversal (O(N))

> Recursive
```cpp
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(Node* node, vector<int>& arr){
    if (node == nullptr) return;
    inorder(node->left, arr);
    arr.push_back(node->val);
    inorder(node->right, arr);
}
vector<int> inorderTraversal(Node* root) {
    vector<int> arr;
    inorder(root, arr);
    return arr;
}
```

> Iterative using Stack
```cpp
vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode* node = root;
        vector<int> inorder;

        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty() == true)
                    break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
};
```

#### 2. Preorder (O(N))

> Recursive
```cpp
void preorder(Node* node, vector<int>& arr){
    if (node == nullptr) return;
    arr.push_back(node->val);
    preorder(node->left, arr);
    preorder(node->right, arr);
}
vector<int> preorderTraversal(Node* root) {
    vector<int> arr;
    preorder(root, arr);
    return arr;
}
```

> Iterative using stack
```cpp
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
     
    if (root == nullptr) return preorder;
     
    stack<TreeNode*> st;
    st.push(root);
    
    while(!st.empty()) {
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        
        if (root->right != nullptr) st.push(root->right);
        if (root->left != nullptr) st.push(root->left);
    }
    
    return preorder;
}
```

#### 3. Postorder (O(N))

```cpp
void postorder(Node* node, vector<int>& arr){
    if (node == nullptr) return;
    postorder(node->left, arr);
    postorder(node->right, arr);
    arr.push_back(node->val);
}
vector<int> postorderTraversal(Node* root) {
    vector<int> arr;
    postorder(root, arr);
    return arr;
}
```

#### 4. Level order traversal (returns an array with levels array in order) eg: [ [3],[9,20],[15,7,9,12] ]

```cpp
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        vector<int> level;
        for (int i =0; i < n; i++){
            Node* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}
```