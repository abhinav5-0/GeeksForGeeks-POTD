# Lowest Common Ancestor in a BST

## Problem Statement
Given a Binary Search Tree (BST) with all unique values and two nodes `n1` and `n2` (where `n1 != n2`), find the Lowest Common Ancestor (LCA).

### Definition
LCA between two nodes `n1` and `n2` is defined as the lowest node in the BST that has both `n1` and `n2` as descendants (including the node itself).

## Example Inputs & Outputs
### Example 1:
**Input:**
```
root = [5, 4, 6, 3, N, N, 7, N, N, N, 8], n1 = 7, n2 = 8
```
**Output:**
```
7
```
### Example 2:
**Input:**
```
root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], n1 = 8, n2 = 14
```
**Output:**
```
8
```

## Approach
1. **Recursive Traversal:**
   - If both `n1` and `n2` are smaller than `root->data`, search in the left subtree.
   - If both `n1` and `n2` are greater than `root->data`, search in the right subtree.
   - Otherwise, the root is the LCA.

## Code Implementation
```cpp
class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (!root) return NULL;
        if (n1->data < root->data && n2->data < root->data)
            return LCA(root->left, n1, n2);
        if (n1->data > root->data && n2->data > root->data)
            return LCA(root->right, n1, n2);
        return root;
    }
};
```

## Complexity Analysis
- **Time Complexity:** O(h) (where `h` is the height of the BST; O(log N) for a balanced BST, O(N) for a skewed BST).
- **Space Complexity:** O(h) (due to recursive call stack).


## Contributing
Feel free to fork this repository and contribute. Open an issue for discussion before making a pull request.

## License
This project is licensed under the MIT License.

