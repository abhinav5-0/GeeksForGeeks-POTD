## 🧩 Problem: Median of BST

**Difficulty:** Medium  
**Accuracy:** 27.43%  
**Points:** 4

### 📝 Problem Statement
You are given the root of a Binary Search Tree. Find the median of it.

Let the nodes of the BST, when written in ascending order (inorder traversal), be represented as `V1, V2, V3, …, Vn`, where `n` is the total number of nodes in the BST.

- If the number of nodes is **even**: return `V(n/2)`  
- If the number of nodes is **odd**: return `V((n+1)/2)`

---

### 💡 Examples

#### Example 1:
**Input:**  
`root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14]`

**Output:**  
`12`

**Explanation:**  
Inorder traversal = [4, 8, 10, 12, 14, 20, 22]  
Here `n = 7` (odd), so median = `(7+1)/2 = 4th` element = **12**.

---

#### Example 2:
**Input:**  
`root = [5, 4, 8, 1]`

**Output:**  
`4`

**Explanation:**  
Inorder traversal = [1, 4, 5, 8]  
Here `n = 4` (even), so median = `(4/2) = 2nd` element = **4**.

---

### 🎯 Constraints
- `1 ≤ number of nodes ≤ 10^5`
- `1 ≤ node.data ≤ 10^5`

---

### 🧠 Approach
1. Perform **inorder traversal** of BST to get sorted node values.
2. Let the number of nodes be `n`.
3. If `n` is **odd**, return element at index `n/2`.
4. If `n` is **even**, return element at index `(n/2 - 1)`.

---

### ✅ Code Implementation
```cpp
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    int findMedian(Node* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        
        if (n % 2 == 1) {
            // Odd number of elements -> middle one
            return arr[n / 2];
        } else {
            // Even number of elements -> (n/2)th element (1-based)
            return arr[(n / 2) - 1];
        }
    }
};
```

---

### ⏱️ Time Complexity
- **O(N)** — for inorder traversal and storing nodes.

### 💾 Space Complexity
- **O(N)** — for storing inorder traversal in vector.

---

Would you like to see the **O(1) space Morris Traversal version** next?
