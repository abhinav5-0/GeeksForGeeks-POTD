# Boundary Traversal of a Binary Tree

## 🚀 Problem Statement
Given a Binary Tree, find its **Boundary Traversal** in the following order:

1. **Left Boundary** (excluding leaf nodes): Nodes from the root to the leftmost leaf, preferring left children over right.
2. **Leaf Nodes** (left to right): All leaf nodes that are not part of the left or right boundary.
3. **Reverse Right Boundary** (excluding leaf nodes): Nodes from the rightmost leaf to the root, preferring right children over left.

If the root has no left or right subtree, the root itself is considered the left or right boundary.

---

## 📝 Constraints
- `1 ≤ number of nodes ≤ 10^5`
- `1 ≤ node->data ≤ 10^5`

---

## 🔹 Example
### **Input:**
```
1 2 3 4 5 6 7 N N 8 9 N N N N
```
### **Tree Structure:**
```
        1
       / \
      2   3
     / \  / \
    4  5 6  7
       / \
      8   9
```
### **Output:**
```
1 2 4 8 9 6 7 3
```
---

## 💡 Solution Approach
The algorithm follows three steps:

### 1️⃣ **Left Boundary Traversal**
- Start from `root->left` and traverse down.
- Prefer left children over right.
- Exclude leaf nodes.

### 2️⃣ **Leaf Nodes Collection**
- Recursively traverse the entire tree to collect all leaf nodes.
- Maintain **left to right** order.

### 3️⃣ **Right Boundary Traversal (Reverse Order)**
- Start from `root->right` and traverse down.
- Prefer right children over left.
- Store nodes in a temporary vector and **add them in reverse order**.
- Exclude leaf nodes.

---

## 💻 C++ Solution
```cpp
class Solution {
  public:
    // Function to check if a node is a leaf node
    bool isLeaf(Node* node) {
        return (node && !node->left && !node->right);
    }

    // Function to get the left boundary (excluding leaf nodes)
    void leftBoundary(Node* node, vector<int>& result) {
        while (node) {
            if (!isLeaf(node)) result.push_back(node->data);
            node = (node->left) ? node->left : node->right;
        }
    }

    // Function to get all leaf nodes (left to right)
    void leafNodes(Node* node, vector<int>& result) {
        if (!node) return;
        if (isLeaf(node)) {
            result.push_back(node->data);
            return;
        }
        leafNodes(node->left, result);
        leafNodes(node->right, result);
    }

    // Function to get the right boundary in reverse order (excluding leaf nodes)
    void rightBoundary(Node* node, vector<int>& result) {
        vector<int> temp;
        while (node) {
            if (!isLeaf(node)) temp.push_back(node->data);
            node = (node->right) ? node->right : node->left;
        }
        // Add right boundary in reverse order
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }

    // Function to return the boundary traversal of a binary tree
    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};

        vector<int> result;

        // Root node (Only add if it's not a leaf)
        if (!isLeaf(root)) result.push_back(root->data);

        // Left boundary (excluding leaf nodes)
        leftBoundary(root->left, result);

        // Leaf nodes (from left to right)
        leafNodes(root, result);

        // Right boundary (in reverse order, excluding leaf nodes)
        rightBoundary(root->right, result);

        return result;
    }
};
```

---

## ⏳ Complexity Analysis
| Section               | Time Complexity |
|----------------------|----------------|
| Left Boundary       | O(H)           |
| Leaf Nodes          | O(N)           |
| Right Boundary      | O(H)           |
| **Total Complexity** | **O(N)**       |

📌 **`H` is the height of the tree and `N` is the total number of nodes.**

---

## ✅ Edge Cases Considered
- Tree with only one node.
- Tree with only left or right subtrees.
- Tree with only leaf nodes.

---

## 🏆 Summary
This solution efficiently performs a **Boundary Traversal** of a binary tree using **O(N) time complexity**. The approach ensures that the traversal order is followed correctly while handling edge cases.

Happy Coding! 🚀

