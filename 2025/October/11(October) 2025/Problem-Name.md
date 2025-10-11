## Maximum Path Sum

**Difficulty:** Medium
**Accuracy:** 42.92%
**Submissions:** 111K+
**Points:** 4
**Average Time:** 45m

### 🧩 Problem Statement

Given the root of a binary tree, your task is to find the **maximum path sum**. The path may start and end at any node in the tree.

### 📥 Input

`root[]` - The elements of the binary tree.

### 📤 Output

Return the **maximum path sum** between any two nodes.

### 🧠 Examples

**Example 1:**

```cpp
Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
Output: 42
Explanation: Max path sum is represented using green color nodes in the binary tree.
```

**Example 2:**

```cpp
Input: root[] = [-17, 11, 4, 20, -2, 10]
Output: 31
Explanation: Max path sum is represented using green color nodes in the above binary tree.
```

### 📋 Constraints

```
1 ≤ number of nodes ≤ 10^3
-10^4 ≤ node->data ≤ 10^4
```

### 🧱 Node Structure

```cpp
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```

---

### 💡 Approach

We use **postorder traversal** to compute the maximum gain from each subtree and maintain a global maximum.

#### Steps:

1. For each node, calculate the maximum gain from its left and right child.
2. If a subtree path sum is negative, ignore it (take `0`).
3. Calculate the path sum passing through the node: `left + right + node->data`.
4. Update the global maximum if this sum is greater.
5. Return `node->data + max(left, right)` to continue the path upward.

---

### ✅ C++ Solution

```cpp
class Solution {
  public:
    int maxSum; // global variable to store the result

    int helper(Node* root) {
        if (!root) return 0;

        // recursively find max path sum for left and right subtrees
        int left = max(0, helper(root->left));   // ignore negative paths
        int right = max(0, helper(root->right));

        // compute the path sum passing through this node
        int currentSum = left + right + root->data;

        // update global max if current path is greater
        maxSum = max(maxSum, currentSum);

        // return the max path sum including this node and one of its subtrees
        return root->data + max(left, right);
    }

    int findMaxSum(Node *root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }
};
```

---

### 🧩 Example Walkthrough

For:

```
Input: [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
```

The tree structure:

```
          10
         /  \
        2    10
       / \     \
      20  1     -25
                /  \
               3    4
```

**Max Path:** `20 + 2 + 10 + 10 = 42`

➡️ **Output:** `42`

---

### 🕒 Time Complexity

* **O(N)** – Each node is visited once.

### 💾 Space Complexity

* **O(H)** – Recursive stack space (where H is the height of the tree).

---

**✅ Final Answer:** Maximum Path Sum in the binary tree is **the highest sum of node values along any path that may start and end at any node.**
