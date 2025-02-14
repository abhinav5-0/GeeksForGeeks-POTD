# Fixing Swapped Nodes in a Binary Search Tree (BST)

## Overview
This repository contains an implementation to correct a BST where exactly two nodes have been swapped by mistake. The algorithm restores the BST by swapping them back without changing the structure of the tree.

## Implementation Details
The solution follows these steps:
1. **Inorder Traversal:** Traverse the BST in an inorder manner, which should yield a sorted sequence.
2. **Identify Swapped Nodes:**
   - If a node is smaller than its previous node, it indicates a swapped pair.
   - The first occurrence is stored in `first` and `middle`.
   - If another occurrence is found, it is stored in `last`.
3. **Fix the BST:**
   - If two non-adjacent nodes are swapped, `first` and `last` are swapped.
   - If two adjacent nodes are swapped, `first` and `middle` are swapped.

## Code
```cpp
class Solution {
  public:
    Node *first, *middle, *last, *prev;
    
    void inorderTraversal(Node* root) {
        if (!root) return;
        
        inorderTraversal(root->left);
        
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        
        inorderTraversal(root->right);
    }
    
    void correctBST(Node* root) {
        first = middle = last = prev = nullptr;
        
        inorderTraversal(root);
        
        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }
};
```

## License
This project is open-source and available under the [MIT License](LICENSE).
