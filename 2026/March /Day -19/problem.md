# 🌳 Largest BST Subtree

## 📝 Problem Statement

You're given a binary tree. Your task is to find the size of the **largest subtree** within this binary tree that also satisfies the properties of a **Binary Search Tree (BST)**.

The size of a subtree is defined as the number of nodes it contains.

### ✅ BST Conditions:

A subtree is considered a BST if:

* All nodes in the left subtree are **less than** the root node.
* All nodes in the right subtree are **greater than** the root node.
* **No duplicate values** are allowed.

---

## 📌 Examples

### Example 1:

```
Input: root = [5, 2, 4, 1, 3]
```

```
        5
       / \
      2   4
     / \
    1   3
```

**Output:**

```
3
```

**Explanation:**
The largest BST subtree is:

```
      2
     / \
    1   3
```

Size = 3

---

### Example 2:

```
Input: root = [6, 7, 3, N, N, 2, 4]
```

```
        6
       / \
      7   3
         / \
        2   4
```

**Output:**

```
3
```

**Explanation:**
The largest BST subtree is:

```
      3
     / \
    2   4
```

Size = 3

---

## ⚙️ Constraints

* `1 ≤ number of nodes ≤ 10^5`
* `1 ≤ node values ≤ 10^5`

---

## 💡 Approach (Optimized)

We use **Postorder Traversal** and for each node we keep track of:

* Minimum value in subtree
* Maximum value in subtree
* Size of subtree
* Whether it is a BST or not

### 🔁 Logic:

* Traverse left and right subtree
* Check BST condition:

  * `left.max < root.data < right.min`
* If valid BST:

  * Update size = left.size + right.size + 1
* Else:

  * Mark as invalid BST and propagate max size

---

## 🚀 Complexity

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(H)` (Recursion stack)

---

## 🧾 Function Signature (C++)

```cpp
class Solution {
public:
    int largestBst(Node *root);
};
```

---

## 🏁 Summary

* Use DFS (postorder)
* Maintain min, max, and size
* Update answer dynamically
* Avoid recomputation

---

🔥 This is a classic tree DP problem and very important for interviews!
