## Symmetric Tree

**Difficulty:** Easy  
**Accuracy:** 44.96%  
**Submissions:** 166K+  
**Points:** 2  
**Average Time:** 20m

---

### **Problem Statement:**
Given the root of a binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.

A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

---

### **Examples:**

**Input:**  
`root[] = [1, 2, 2, 3, 4, 4, 3]`  
**Output:** `True`  
**Explanation:** As the left and right halves of the tree are mirror images, the tree is symmetric.

**Input:**  
`root[] = [1, 2, 2, N, 3, N, 3]`  
**Output:** `False`  
**Explanation:** The left and right halves of the tree are not mirror images, so the tree is not symmetric.

---

### **Constraints:**
- `1 ≤ number of nodes ≤ 2000`

---

### **Tree Node Structure:**
```cpp
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
```

---

### **Function Signature:**
```cpp
class Solution {
  public:
    bool isSymmetric(Node* root);
};
```

---

### **Solution:**
```cpp
class Solution {
  public:
    bool isMirror(Node* left, Node* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->data == right->data) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(Node* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
```

---
