# Problem: Print Leaf Nodes from Preorder Traversal of BST

## Difficulty

Medium

## Problem Statement

Given a preorder traversal of a Binary Search Tree (BST), find all the **leaf nodes** without constructing the BST.

### Definitions:

* **Preorder Traversal** of BST: Root -> Left Subtree -> Right Subtree
* **Leaf Node**: A node with no children.

---

## Input

* An integer array `preorder` of size `n` (1 <= n <= 10^3)
* All values in the array are distinct and in the range \[1, 1000].

## Output

* A list of integers representing all the leaf nodes in the BST, in the order they appear.

---

## Examples

### Example 1

**Input:**

```
preorder = [5, 2, 10]
```

**Output:**

```
[2, 10]
```

### Example 2

**Input:**

```
preorder = [4, 2, 1, 3, 6, 5]
```

**Output:**

```
[1, 3, 5]
```

### Example 3

**Input:**

```
preorder = [8, 2, 5, 10, 12]
```

**Output:**

```
[5, 12]
```

---

## Constraints

* 1 <= preorder.size() <= 1000
* 1 <= preorder\[i] <= 1000

---

## Optimal Solution Approach

We simulate BST construction using a recursive approach with **min-max constraints**, without actually building the tree.

### Key Steps

1. Use a helper function `findLeaves(preorder, idx, minVal, maxVal, result)`
2. Track valid range for each node (BST invariant).
3. Identify a leaf when no left or right child is possible for a node.

---

## Time and Space Complexity

* **Time:** O(n) — Each element is visited once
* **Space:** O(n) — Recursion stack + result array

---

## C++ Code

```cpp
class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> result;
        int idx = 0;
        findLeaves(preorder, idx, INT_MIN, INT_MAX, result);
        return result;
    }

  private:
    void findLeaves(vector<int>& preorder, int& idx, int minVal, int maxVal, vector<int>& result) {
        if (idx >= preorder.size() || preorder[idx] < minVal || preorder[idx] > maxVal)
            return;

        int root = preorder[idx++];
        int currentIdx = idx;

        // Left Subtree
        findLeaves(preorder, idx, minVal, root - 1, result);
        // Right Subtree
        findLeaves(preorder, idx, root + 1, maxVal, result);

        // If no child was added, it's a leaf
        if (currentIdx == idx)
            result.push_back(root);
    }
};
```

---

## Notes

* Avoids building actual tree nodes
* Fast and passes edge cases efficiently
* Suitable for competitive programming and interviews
