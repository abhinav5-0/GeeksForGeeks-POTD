# Diameter of a Binary Tree

## Problem Statement
Given a binary tree, the **diameter** (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.

### **Examples**
#### **Example 1:**
**Input:**
```
        1
       / \
      2   3
```
**Output:** `2`

**Explanation:** The longest path is `2 -> 1 -> 3` (2 edges).

#### **Example 2:**
**Input:**
```
        5
       / \
      8   6
     / \   \
    3   7   9
```
**Output:** `4`

**Explanation:** The longest path is `3 -> 8 -> 5 -> 6 -> 9` (4 edges).

### **Constraints**
- `1 ≤ number of nodes ≤ 10^5`
- `0 ≤ node->data ≤ 10^5`

---

## Approach
1. **Recursive Depth-First Search (DFS):**
   - Use a helper function to compute the height of the tree.
   - While computing height, update the **diameter** dynamically.
   - The diameter at any node is the sum of the left and right subtree heights.
   
2. **Key Formula:**
   ```
   diameter = max(diameter, leftHeight + rightHeight)
   ```

3. **Base Case:**
   - If the node is `NULL`, return `0`.

---

## **Code Implementation (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

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

class Solution {
  private:
    int height(Node* root, int &diameter) {
        if (root == NULL) return 0;

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        // Update the diameter at this node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the subtree rooted at this node
        return 1 + max(leftHeight, rightHeight);
    }

  public:
    int diameter(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin.ignore();
        getline(cin, s);
        // Build tree function (not shown here)
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}
```

---

## **Complexity Analysis**
- **Time Complexity:** `O(N)`, as each node is visited once.
- **Space Complexity:** `O(H)`, where `H` is the tree height (worst case `O(N)` for skewed trees).

---

## **Alternative Approaches**
1. **Naïve Approach (O(N^2)):**
   - Compute height separately for left and right subtrees for each node.
   - Inefficient for large trees.

2. **Optimized DFS (O(N)) - Used Here:**
   - Calculates height and updates diameter in one pass.

---

## **Summary**
- Used **DFS and height computation** to find the **diameter** efficiently.
- **Optimized solution runs in O(N) time.**
- **Handles up to 100,000 nodes efficiently.**

---

## **Related Problems**
- **Maximum Depth of Binary Tree**
- **Balanced Binary Tree Check**
- **Lowest Common Ancestor in a Binary Tree**

Happy Coding! 🚀

