**Postorder Traversal**
**Difficulty:** Easy
**Accuracy:** 74.96%
**Submissions:** 138K+
**Points:** 2
**Average Time:** 15m

---

### **Problem Statement:**

Given the root of a Binary Tree, your task is to return its Postorder Traversal.

**Note:** A postorder traversal first visits the left child (including its entire subtree), then visits the right child (including its entire subtree), and finally visits the node itself.

---

### **Examples:**

**Input:**
`root = [19, 10, 8, 11, 13]`

**Output:**
`[11, 13, 10, 8, 19]`

**Explanation:**
The postorder traversal of the given binary tree is `[11, 13, 10, 8, 19]`.

---

**Input:**
`root = [11, 15, N, 7]`

**Output:**
`[7, 15, 11]`

**Explanation:**
The postorder traversal of the given binary tree is `[7, 15, 11]`.

---

### **Constraints:**

* 1 ≤ number of nodes ≤ 3 * 10^4
* 0 ≤ node->data ≤ 10^5

---

### **Code Implementation:**

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
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        postOrderTraversal(root, ans);
        return ans;
    }
    
  private:
    void postOrderTraversal(Node* node, vector<int>& ans) {
        if (node == NULL) return;
        
        // 1. Traverse left subtree
        postOrderTraversal(node->left, ans);
        
        // 2. Traverse right subtree
        postOrderTraversal(node->right, ans);
        
        // 3. Visit current node
        ans.push_back(node->data);
    }
};
```

---

### **Explanation:**

* **Postorder Traversal Order:** Left → Right → Root
* The recursive function `postOrderTraversal()`:

  * Calls itself for the left child.
  * Calls itself for the right child.
  * Then stores the current node’s data.

---

### **Example Walkthrough:**

**Input Tree:**

```
      19
     /  \
    10   8
   / \
  11 13
```

**Output:**
`[11, 13, 10, 8, 19]`
