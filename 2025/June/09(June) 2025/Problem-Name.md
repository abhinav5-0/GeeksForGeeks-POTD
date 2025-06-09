# BST with Dead End

## Difficulty

Medium

## Accuracy

35.99%

## Submissions

88K+

## Points

4

---

## Problem Statement

You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

Your task is to determine whether the BST contains a **dead end**.

### Note:

A **dead end** is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be greater than 0.

---

## Examples

### Example 1:

**Input:** `root[] = [8, 5, 9, 2, 7, N, N, 1]`

**Output:** `true`

**Explanation:** Node 1 is a Dead End in the given BST.

### Example 2:

**Input:** `root[] = [8, 7, 10, 2, N, 9, 13]`

**Output:** `true`

**Explanation:** Node 9 is a Dead End in the given BST.

---

## Constraints

* `1 ≤ number of nodes ≤ 3000`
* `1 ≤ node->data ≤ 10^5`

---

## Structure of Node

```cpp
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
```

---

## Function Signature

```cpp
class Solution {
  public:
    bool isDeadEnd(Node *root);
};
```

---

## Expected Time Complexity

`O(N)`

## Expected Auxiliary Space

`O(H)` where H is the height of the tree

---

## Approach

1. Use recursion to check each node with a range `[min, max]` representing valid values that can be inserted.
2. A dead end is encountered if `min == max`.
3. Start the check with the range `[1, INT_MAX]`.

---

## Sample Implementation

```cpp
class Solution {
  public:
    bool checkDeadEnd(Node* root, int minVal, int maxVal) {
        if (!root) return false;

        if (minVal == maxVal) return true;

        return checkDeadEnd(root->left, minVal, root->data - 1) ||
               checkDeadEnd(root->right, root->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return checkDeadEnd(root, 1, INT_MAX);
    }
};
```
