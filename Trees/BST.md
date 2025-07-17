# Binary Search Tree (BST)

A **Binary Search Tree** is a binary tree where:

- Left child < Node < Right child
- Every left/right subtree is also a BST
- No duplicate values (in general)
- Duplicates, if allowed, are handled via special rules (e.g., frequency count)

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
