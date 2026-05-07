# Check if Subtree

## Problem Statement
Given two binary trees with roots `root1` (for tree **T**) and `root2` (for tree **S**), determine whether tree **S** is a subtree of tree **T**.

Return `true` if **S** is a subtree of **T**, otherwise return `false`.

---

## Note
A tree **S** is considered a subtree of **T** if there exists a node in **T** such that the subtree rooted at that node is identical to **S**.

Two trees are identical if:
- They have the same structure
- Corresponding nodes contain the same values

---

# Examples

## Example 1

### Input
```txt
root1 = [1, 2, 3, N, N, 4]
root2 = [3, 4]
