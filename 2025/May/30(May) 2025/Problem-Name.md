# Closest Neighbour in BST

**Difficulty:** Easy  
**Accuracy:** 36.98%  
**Submissions:** 58K+  
**Points:** 2

---

## Problem Statement

Given the root of a binary search tree (BST) and a number `k`, find the **greatest number in the BST that is less than or equal to `k`**.

---

## Examples

### Example 1:
```
Input: root = [10, 7, 15, 2, 8, 11, 16], k = 14
Output: 11
Explanation: The greatest element in the tree which is less than or equal to 14, is 11.
```

### Example 2:
```
Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 24
Output: 21
Explanation: The greatest element in the tree which is less than or equal to 24, is 21.
```

### Example 3:
```
Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 4
Output: 3
Explanation: The greatest element in the tree which is less than or equal to 4, is 3.
```

---

## Constraints
- 1 <= number of nodes <= 10^5
- 1 <= node->data, k <= 10^5
- All nodes are unique in the BST

---

## Approach

1. Initialize a variable `res` to -1 (or some default value indicating no valid node found).
2. Start from the root of the BST.
3. Traverse the tree:
   - If the current node's value is less than or equal to `k`, update `res` to current node's value and move to the right subtree (because greater values might still be valid).
   - If the current node's value is greater than `k`, move to the left subtree.
4. Continue this process until you reach a null node.
5. Return `res`.

---

## Python Code
```python
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def find_floor_in_bst(root, k):
    res = -1
    while root:
        if root.data == k:
            return root.data
        elif root.data < k:
            res = root.data
            root = root.right
        else:
            root = root.left
    return res
```

---

## Time and Space Complexity
- **Time Complexity:** O(h), where h is the height of the BST. In the worst case (unbalanced BST), this is O(n).
- **Space Complexity:** O(1), iterative traversal avoids recursion stack.
