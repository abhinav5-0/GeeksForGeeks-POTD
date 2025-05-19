# Problem: Predecessor and Successor in BST

## Difficulty: Medium

### Accuracy: 47.36%

### Submissions: 139K+

### Points: 4

---

## Problem Statement:

You are given the root node of a Binary Search Tree (BST) and an integer key. You need to find the **in-order successor** and **predecessor** of the given key.

If either the predecessor or successor is not found, then set it to NULL.

### Note:

In an **inorder traversal**, the number just **smaller** than the target is the **predecessor** and the number just **greater** than the target is the **successor**.

---

## Examples:

### Example 1:

**Input:**

```
root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N]
key = 8
```

**Output:**

```
4 9
```

**Explanation:**
In the given BST, the inorder predecessor of 8 is 4 and the inorder successor of 8 is 9.

---

### Example 2:

**Input:**

```
root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N]
key = 11
```

**Output:**

```
10 -1
```

**Explanation:**
In the given BST, the inorder predecessor of 11 is 10. There is no inorder successor.

---

### Example 3:

**Input:**

```
root[] = [2, 1, 3]
key = 3
```

**Output:**

```
2 -1
```

**Explanation:**
In the given BST, the inorder predecessor of 3 is 2 and there is no inorder successor.

---

## Constraints:

* 1 <= no. of nodes <= 10^5
* 1 <= node->data <= 10^6
* 1 <= key <= 10^6

---

## Approach:

* Traverse the BST from the root.
* If the root's value equals the key:

  * The predecessor is the maximum value in the left subtree (rightmost node of the left child).
  * The successor is the minimum value in the right subtree (leftmost node of the right child).
* If the key is smaller than root, move to the left and mark current root as a potential successor.
* If the key is greater than root, move to the right and mark current root as a potential predecessor.

---

## Time Complexity:

* O(h), where h is the height of the BST (log n for balanced, n for skewed).

## Space Complexity:

* O(1), iterative solution.

---

## Tags:

* BST
* Inorder Traversal
* Tree Traversal
* Binary Tree
* Successor Predecessor
