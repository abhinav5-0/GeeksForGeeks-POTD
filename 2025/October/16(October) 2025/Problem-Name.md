## Remove BST Keys Outside Given Range

**Difficulty:** Medium
**Accuracy:** 59.43%
**Points:** 4

---

### 🧩 Problem Statement

Given the root of a **Binary Search Tree (BST)** and two integers `l` and `r`, remove all the nodes whose values lie outside the range `[l, r]`.

**Note:** The modified tree should also be a valid BST, and the sequence of the remaining nodes should not be changed.

---

### 📘 Examples

**Input:**
`root = [6, -13, 14, N, -8, 13, 15, N, N, 7], l = -10, r = 13`

**Output:**
`[6, -8, 13, N, N, 7]`

**Explanation:**
All nodes outside the range `[-10, 13]` are removed and the modified tree remains a valid BST.

---

**Input:**
`root = [14, 4, 16, 2, 8, 15, N, -8, 3, 7, 10], l = 2, r = 6`

**Output:**
`[4, 2, N, N, 3]`

**Explanation:**
All nodes outside the range `[2, 6]` are removed and the modified tree remains a valid BST.

---

### ⚙️ Constraints

* `1 ≤ number of nodes ≤ 10^4`
* `1 ≤ node->data ≤ 10^4`
* `1 ≤ l ≤ r ≤ 10^4`

---

### 💡 Approach

Since the given tree is a **BST**, we can utilize its properties:

* If `root->data < l`, all nodes in its **left subtree** will also be smaller → skip the left subtree.
* If `root->data > r`, all nodes in its **right subtree** will also be greater → skip the right subtree.
* If `root->data` lies within `[l, r]`, recursively fix both subtrees.

---

### ✅ C++ Implementation

```cpp
class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // Base case: if tree is empty
        if (!root) return NULL;

        // Recursively fix left and right subtrees
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);

        // If root's data is less than l, remove root and return right child
        if (root->data < l) {
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        }

        // If root's data is greater than r, remove root and return left child
        if (root->data > r) {
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        }

        // Root is in range
        return root;
    }
};
```

---

### 🧠 Example Dry Run

**Input:**
`root = [6, -13, 14, N, -8, 13, 15, N, N, 7], l = -10, r = 13`

**Process:**

* 6 is within range → keep it.
* -13 < -10 → remove it.
* 14 > 13 → remove it.

**Result:**
`[6, -8, 13, N, N, 7]`

---

### 🕒 Complexity Analysis

* **Time Complexity:** O(N) → Each node is visited once.
* **Space Complexity:** O(H) → Due to recursion stack (H = height of BST).

---
