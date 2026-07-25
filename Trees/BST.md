# Binary Search Tree (BST)

A **Binary Search Tree** is a binary tree where:

- Left child < Node < Right child
- Every left/right subtree is also a BST
- No duplicate values (in general)
- Duplicates, if allowed, are handled via special rules (e.g., frequency count)

> The inorder traversal of BST will always result in a sorted array

## Why Use BST?

- Faster search, insert, and delete: **O(log N)** on average everytime in BST
- Unbalanced binary trees can degrade to **O(N)** time when screwed, but not BST.

### Return Target val in BST O(log₂N)

```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    while (root != NULL && root->val != val ){
        root = root->val < val ? root->right : root->left;
    }
    return root;
}
```

### Floor in BST

- Floor of a value refers to the value of the largest node in the BST that is smaller than or equal to the given key.
  
```cpp
int floorInBST(TreeNode* root, int key){
    int floor = -1;
        
    while(root != nullptr){
        if(root->val == key){
            floor = root->val;
            return floor;
        }
            
        if(key > root->val){
            floor = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}
```

### Ceil in BST

- Ceil of a value refers to the value of the smallest node in the BST that is greater than or equal to the given key.
  
```cpp
int ceilInBST(TreeNode* root, int key){
    int ceil = -1;
        
    while(root != nullptr){
        if(root->val == key){
            ceil = root->val;
            return ceil;
        }
            
        if(key > root->val){
            root = root->right;
        } else {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}
```

### Insert a given Node in BST so as the tree remains a BST after insertion

```cpp
class Solution {
public:
    Node* insertNode(Node* root, int key) {
        if (root == nullptr) return new Node(key);

        if (key < root->val) // If key is less, insert in left subtree
            root->left = insertNode(root->left, key); 
        else // If key is greater, insert in right subtree
            root->right = insertNode(root->right, key);

        return root;
    }
};
```

### Delete a Node in Binary Search Tree

```cpp
class Solution {
public:
    // Find the minimum value node in a subtree
    Node* findMin(Node* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) // If key is less, go to left subtree
            root->left = deleteNode(root->left, key);
        else if (key > root->val) // If key is greater, go to right subtree
            root->right = deleteNode(root->right, key);
        else {
            // Node with only one child or no child
            if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;

            // Node with two children: get inorder successor from right
            Node* temp = findMin(root->right);
            root->val = temp->val; // swap
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
```

### Kth Smallest Element in a BST

- using the idea that inorder traversal of BST is always sorted, so we can maintain a count of nodes till k nodes.

```cpp
class Solution {
public:
    void inorder(TreeNode* root, int k, int &count, int &ans){
        if (root == nullptr) return;
        inorder(root->left, k, count, ans);
        count++;
        if (count == k){
            ans = root->val;
        }
        inorder(root->right, k, count, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        inorder(root, k, count, ans);
        return ans;
    }
};
```

---

### Validate Binary Search Tree

- **Intuition**: Each node in a BST must lie within a range `(minVal, maxVal)`. Root range is `(LONG_MIN, LONG_MAX)`. Left child range becomes `(minVal, root->val)` and right child range becomes `(root->val, maxVal)`.
- **TC**: $O(N)$, **SC**: $O(H)$.

```cpp
class Solution {
public:
    bool isValid(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;

        return isValid(root->left, minVal, root->val) &&
               isValid(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
```

---

### Lowest Common Ancestor (LCA) in BST

- **Intuition**: Leverage BST property. If both `p` and `q` are smaller than `root->val`, LCA lies in left subtree. If both are greater, LCA lies in right subtree. The split point where `p` and `q` diverge is the LCA.
- **TC**: $O(H)$, **SC**: $O(1)$ (iterative).

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root; // Split point is LCA
            }
        }
        return nullptr;
    }
};
```

---

### Construct BST from Preorder Traversal

- **Intuition**: Pass an upper bound limit for each node. Root takes `INT_MAX`. For left subtree, upper bound is `node->val`. For right subtree, upper bound remains the parent's upper bound.
- **TC**: $O(N)$, **SC**: $O(H)$.

```cpp
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return nullptr;

        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);

        return root;
    }
};
```

---

### BST Iterator ($O(1)$ Average Time, $O(H)$ Space)

- **Intuition**: Maintain a stack of leftmost nodes. `next()` returns top element and pushes all left children of `top->right` onto the stack. `hasNext()` checks if stack is non-empty.
- **TC**: $O(1)$ amortized for `next()`, **SC**: $O(H)$.

```cpp
class BSTIterator {
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        pushAllLeft(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
```

