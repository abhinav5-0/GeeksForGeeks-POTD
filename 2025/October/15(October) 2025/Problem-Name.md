## K-th Smallest in BST

**Difficulty:** Medium
**Accuracy:** 43.53%
**Submissions:** 152K+
**Points:** 4
**Average Time:** 40m

---

### 🧩 Problem Statement

Given the root of a **Binary Search Tree (BST)** and an integer **k**, the task is to find the **k-th smallest element** in the BST. If there is no k-th smallest element present, return **-1**.

---

### 🧠 Example

**Input:**
`root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 3`

**Output:**
`10`

**Explanation:**
The inorder traversal of the BST is `[4, 8, 10, 12, 14, 20, 22]`, and the 3rd smallest element is `10`.

**Input:**
`root = [2, 1, 3], k = 5`

**Output:**
`-1`

**Explanation:**
There is no 5th smallest element as the BST contains only 3 nodes.

---

### ⚙️ Constraints

* 1 ≤ number of nodes, k ≤ 10⁴
* 1 ≤ node->data ≤ 10⁴

---

### 💡 Approach

1. Perform **inorder traversal** (Left → Root → Right) of the BST, which visits elements in sorted order.
2. Keep a **counter** of visited nodes.
3. When the counter equals **k**, record the current node’s value as the answer.
4. If traversal completes without finding k elements, return **-1**.

---

### 🧮 Code Implementation

```cpp
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int count = 0; // Counter for visited nodes
    int ans = -1;  // Result holder

    void inorder(Node* root, int k) {
        if (!root || ans != -1) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            ans = root->data;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(Node *root, int k) {
        inorder(root, k);
        return ans;
    }
};
```

---

### 🧾 Example Walkthrough

**BST:** `[20, 8, 22, 4, 12, N, N, N, N, 10, 14]`
**Inorder Traversal:** `[4, 8, 10, 12, 14, 20, 22]`
**k = 3 → Output:** `10`

---

### ⏱️ Complexity Analysis

* **Time Complexity:** O(k) on average, O(N) in worst case
* **Space Complexity:** O(H), where H = height of tree (for recursion stack)

---

### 🧰 Alternative Approach

You can also implement an **iterative inorder traversal** using a stack to avoid recursion, which is more efficient for very large trees.
