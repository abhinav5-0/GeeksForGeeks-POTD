# Binary Search Tree (BST) Checker

## Overview
This repository contains an implementation to check whether a given binary tree is a Binary Search Tree (BST). The solution is implemented in C++ and uses a recursive approach with valid range checks.

## Implementation Details
- The `isBSTUtil` function validates the BST property by ensuring each node's value lies within a valid range.
- The `isBST` function initializes the validation process with minimum and maximum possible values.
- The algorithm has a time complexity of **O(N)** and a space complexity of **O(H)** (where H is the height of the tree).

## Code Structure
```cpp
class Solution {
  public:
    // Helper function to validate BST with a range
    bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
        if (!root) return true;
        
        if (root->data <= minVal || root->data >= maxVal) return false;
        
        return isBSTUtil(root->left, minVal, root->data) &&
               isBSTUtil(root->right, root->data, maxVal);
    }
    
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};
```


## License
This project is open-source and available under the MIT License.

