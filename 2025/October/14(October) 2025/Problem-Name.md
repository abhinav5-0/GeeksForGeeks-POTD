## Sum of Nodes in BST Range

**Difficulty:** Medium
**Accuracy:** 86.11%
**Submissions:** 6K+
**Points:** 4

---

### 🧩 Problem Statement

Given the root of a **Binary Search Tree (BST)** and two integers **l** and **r**, find the **sum of all nodes** that lie between *l* and *r* (inclusive).

---

### 💡 Example 1

**Input:**
`root = [22, 12, 30, 8, 20]`, `l = 10`, `r = 22`

**Output:**
`54`

**Explanation:**
Nodes within range [10, 22] are {12, 20, 22}.
Sum = 12 + 20 + 22 = **54**.

---

### 💡 Example 2

**Input:**
`root = [8, 5, 11, 3, 6, N, 20]`, `l = 11`, `r = 15`

**Output:**
`11`

**Explanation:**
Only node 11 lies within the range [11, 15].
Sum = **11**.

---

### ⚙️ Constraints

* 0 ≤ number of nodes ≤ 10⁴
* 0 ≤ node->data ≤ 10⁴
* 0 ≤ l ≤ r ≤ 10⁴

---

### 🧠 Approach

Use the **BST property**:

* Left subtree values < root value.
* Right subtree values > root value.

We recursively traverse the tree:

1. If node is NULL → return 0.
2. If node value is within [l, r] → include it in sum.
3. If node value > r → recurse only on left subtree.
4. If node value < l → recurse only on right subtree.

This ensures an **efficient** traversal (O(n) time, O(h) space).

---

### 🧾 Code Implementation (C++)

```cpp
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if (root == NULL)
            return 0;

        if (root->data >= l && root->data <= r)
            return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);

        else if (root->data > r)
            return nodeSum(root->left, l, r);

        else
            return nodeSum(root->right, l, r);
    }
};
```

---

### 🧮 Example Walkthrough

**Input:**
`root = [22, 12, 30, 8, 20]`, `l = 10`, `r = 22`

**BST Structure:**

```
      22
     /  \
   12    30
  /  \
 8   20
```

**Nodes in Range [10, 22]:** {12, 20, 22}
**Sum = 54** ✅

---

### 🕒 Complexity Analysis

* **Time Complexity:** O(n) (visiting each node once)
* **Space Complexity:** O(h), where *h* is the height of the tree (recursion stack)

---

**✔️ Efficient, recursive, and leverages BST properties for optimal traversal.**
