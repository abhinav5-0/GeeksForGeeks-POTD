# Problem Statement: Is Binary Tree Heap

## Difficulty:
Medium

## Accuracy:
34.41%

## Submissions:
122K+

## Points:
4

---

## Problem Description:

You are given a binary tree. Your task is to determine whether it satisfies the properties of a **max-heap**.

A binary tree is considered a **max-heap** if it satisfies the following conditions:

1. **Completeness:**
   - Every level of the tree, except possibly the last, is completely filled.
   - All nodes are as far left as possible.

2. **Max-Heap Property:**
   - The value of each node must be greater than or equal to the values of its children.

---

## Examples:

### Example 1:
- **Input:**
  ```
  root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
  ```
- **Output:**
  ```
  true
  ```
- **Explanation:**
  The tree is complete and satisfies the max-heap property.

### Example 2:
- **Input:**
  ```
  root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4]
  ```
- **Output:**
  ```
  false
  ```
- **Explanation:**
  The tree is not complete and does not follow the max-heap property.

---

## Constraints:
- 1 ≤ number of nodes ≤ 10^3
- 1 ≤ node->data ≤ 10^3

---

## Approach:

1. **Count the total number of nodes** in the binary tree.
2. **Check completeness** by verifying that no node appears after a missing spot (using index based logic).
3. **Check max-heap property** by ensuring that for every node, the node's value ≥ children's values.

---

## Pseudocode:

```cpp
int countNodes(Node* root);
bool isComplete(Node* root, int index, int totalNodes);
bool isMaxHeap(Node* root);

bool isHeap(Node* tree) {
    int totalNodes = countNodes(tree);
    return isComplete(tree, 0, totalNodes) && isMaxHeap(tree);
}
```

---

## Full C++ Solution:

```cpp
class Solution {
  public:
    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isComplete(Node* root, int index, int totalNodes) {
        if (root == NULL) return true;
        if (index >= totalNodes) return false;
        return isComplete(root->left, 2 * index + 1, totalNodes) &&
               isComplete(root->right, 2 * index + 2, totalNodes);
    }

    bool isMaxHeap(Node* root) {
        if (root == NULL) return true;
        if (!root->left && !root->right) return true;
        if (root->left && !root->right)
            return (root->data >= root->left->data) && isMaxHeap(root->left);
        if (root->left && root->right)
            return (root->data >= root->left->data) &&
                   (root->data >= root->right->data) &&
                   isMaxHeap(root->left) &&
                   isMaxHeap(root->right);
        return false;
    }

    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);
        return isComplete(tree, 0, totalNodes) && isMaxHeap(tree);
    }
};
```

---

## Notes:
- This approach traverses the tree multiple times but ensures correctness.
- Further optimization is possible using a BFS single pass approach.

