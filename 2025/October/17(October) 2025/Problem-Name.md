## BST to Greater Sum Tree

**Difficulty:** Medium
**Accuracy:** 66.73%
**Submissions:** 21K+
**Points:** 4

---

### 🧩 Problem Statement

Given the root of a **Binary Search Tree (BST)** with unique node values, transform it into a **Greater Sum Tree (GST)** where each node contains the sum of all nodes **greater than that node**.

---

### 📘 Examples

#### Example 1

**Input:**
`root = [11, 2, 29, 1, 7, 15, 40, N, N, N, N, N, N, 35, N]`

**Output:**
`[119, 137, 75, 139, 130, 104, 0, N, N, N, N, N, N, 40, N]`

**Explanation:**
Every node is replaced with the sum of nodes greater than itself.

---

#### Example 2

**Input:**
`root = [2, 1, 6, N, N, 3, 7]`

**Output:**
`[16, 18, 7, N, N, 13, 0]`

**Explanation:**
Every node is replaced with the sum of nodes greater than itself.

---

### ⚙️ Constraints

* `1 ≤ node->data ≤ 3 * 10^4`
* `1 ≤ number of nodes ≤ 3 * 10^4`

---

### 🧠 Approach

1. Perform a **reverse inorder traversal** (right → root → left).
   This ensures we visit nodes from the largest to the smallest.
2. Maintain a **running sum** (`sum`) of all previously visited nodes.
3. For each node:

   * Store its current value (`old_val`).
   * Replace it with the current `sum`.
   * Add `old_val` to `sum`.

---

### 💻 Code Implementation (C++)

```cpp
class Solution {
  public:
    int sum = 0;  // maintains sum of visited nodes

    void transformTree(Node *root) {
        if (!root) return;

        // Traverse right subtree first (greater values)
        transformTree(root->right);

        // Store original node value
        int old_val = root->data;

        // Update node with sum of greater nodes
        root->data = sum;

        // Update sum by adding old value
        sum += old_val;

        // Traverse left subtree
        transformTree(root->left);
    }
};
```

---

### 🧮 Example Walkthrough

For BST:

```
       2
      / \
     1   6
        / \
       3   7
```

**Reverse Inorder Traversal:** `7 → 6 → 3 → 2 → 1`

| Node | Sum before | New Value | Updated Sum |
| ---- | ---------- | --------- | ----------- |
| 7    | 0          | 0         | 7           |
| 6    | 7          | 7         | 13          |
| 3    | 13         | 13        | 16          |
| 2    | 16         | 16        | 18          |
| 1    | 18         | 18        | 19          |

✅ Final Greater Sum Tree:

```
       16
      /  \
     18   7
         / \
        13  0
```

---

### ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)` — each node is visited once.
* **Space Complexity:** `O(h)` — recursion stack height (`h` = height of BST).

---

**✅ Summary:**
The key idea is using **reverse inorder traversal** with a running cumulative sum to replace each node with the sum of greater nodes efficiently.
