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

### 1. Inorder Traversal (O(N))

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
            if (st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
};
```

### 2. Preorder (O(N))

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

### 3. Postorder (O(N))

> Recursive

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

> Iterative using 2 stacks

```cpp
vector<int> postOrder(Node* root) {
    vector<int> postorder;

    if (root == NULL) return postorder;
    
    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left != NULL) st1.push(root->left);
        if (root->right != NULL) st1.push(root->right);
    }

    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}
```

### 4. Level order traversal (returns an array with levels array in order) eg: [ [3],[9,20],[15,7,9,12] ]

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

### Preorder Inorder PostOrder Traversals in one traversal

```cpp
vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;

    if (root == NULL) return {} ;

    // Stack to maintain nodes and their traversal state
    stack<pair<Node*, int>> st;
    // Start with the root node and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of preorder
        if (it.second == 1) {
            pre.push_back(it.first->data);
            // Move to state 2 (inorder) for this node
            it.second = 2;
            // Push the updated state back onto the stack
            st.push(it); 

            if (it.first->left != NULL) st.push({it.first->left, 1});
        }

        // this is a part of inorder
        else if (it.second == 2) {
            in.push_back(it.first->data);
            // Move to state 3 (postorder) for this node
            it.second = 3;
            // Push the updated state back onto the stack
            st.push(it); 

            if (it.first->right != NULL) st.push({it.first->right, 1});
        }

        // this is part of postorder
        else {
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
```

### MaxDepth/height of Binary tree O(N)

- we can use BFS(level order) but recursion suits as it can give ~ O(H)

```cpp
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
    }
```

### Check for a Balanced Binary tree O(N)

```cpp
bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1 ;
}
int dfsHeight(TreeNode* root){
    if (root == nullptr) return 0;

    int lh = dfsHeight(root->left);
    if (lh == -1) return -1;
    int rh = dfsHeight(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}
```

### Diameter of Binary Tree O(N)

- The Diameter of a Binary Tree is the longest distance between any two nodes of that tree. This path may or may not pass through the root.

```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int height(TreeNode* root, int& diameter){
    if (root == nullptr) return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}
```

### Maximum sum along any path within the tree O(N)

- A path in a binary tree is defined as a sequence of nodes where each pair of adjacent nodes is connected by an edge. Nodes can only appear once in the sequence, and the path is not required to start from the root.

```cpp
int maxPathSum(TreeNode* root) {
    int maxsum = INT_MIN;
    findmaxsum(root, maxsum);
    return maxsum;
}
int findmaxsum(TreeNode* root, int& maxsum){
    if (root == nullptr) return 0;
    int leftsum = max(0, findmaxsum(root->left, maxsum));
    int rightsum = max(0, findmaxsum(root->right, maxsum));

    maxsum = max(maxsum, leftsum + rightsum + root->val);

    return root->val + max(leftsum, rightsum);
}
```

### Check whether two trees are identical

```cpp
bool isIdenticalTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;

    return (p->val == q->val) && isIdenticalTree(p->left, q->left) &&
           isIdenticalTree(p->right, q->right);
}
```
