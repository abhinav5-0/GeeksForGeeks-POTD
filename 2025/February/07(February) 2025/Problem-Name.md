# Inorder Traversal

## Problem Statement  
Given a Binary Tree, your task is to return its In-Order Traversal.

An **in-order traversal** first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

### **Example 1:**
#### **Input:**  
```
root[] = [1, 2, 3, 4, 5]
```
#### **Output:**  
```
[4, 2, 5, 1, 3]
```
#### **Explanation:**  
The in-order traversal of the given binary tree is `[4, 2, 5, 1, 3]`.

---

### **Example 2:**
#### **Input:**  
```
root[] = [8, 1, 5, N, 7, 10, 6, N, 10, 6]
```
#### **Output:**  
```
[1, 7, 10, 8, 6, 10, 5, 6]
```
#### **Explanation:**  
The in-order traversal of the given binary tree is `[1, 7, 10, 8, 6, 10, 5, 6]`.

---

## Constraints:
- **1 <= number of nodes <= 10⁵**
- **0 <= node->data <= 10⁵**

## Approach
### **Recursive Implementation:**
```cpp
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    
  private:
    void inorderTraversal(Node* root, vector<int>& result) {
        if (root == NULL) return;
        inorderTraversal(root->left, result);
        result.push_back(root->data);
        inorderTraversal(root->right, result);
    }
};
```

### **Iterative Implementation (Using Stack):**
```cpp
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> result;
        stack<Node*> st;
        Node* curr = root;
        
        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            result.push_back(curr->data);
            
            curr = curr->right;
        }
        
        return result;
    }
};
```

## **Time Complexity Analysis**
- **Recursive Approach:**  
  - Time Complexity: **O(N)**
  - Space Complexity: **O(N)** (for recursion stack in worst case)
  
- **Iterative Approach:**  
  - Time Complexity: **O(N)**
  - Space Complexity: **O(N)** (for stack in the worst case)
  
## **Example Walkthrough**
### **Binary Tree Representation:**
```
      1
     / \
    2   3
   / \
  4   5
```
### **In-order Traversal Steps:**
1. Traverse left subtree: `[4]`
2. Visit root `2`: `[4, 2]`
3. Traverse right subtree: `[4, 2, 5]`
4. Visit root `1`: `[4, 2, 5, 1]`
5. Traverse right subtree `[3]`
6. **Final Output:** `[4, 2, 5, 1, 3]`

This problem helps in understanding **tree traversal techniques**, which are fundamental in tree-based data structures. 🚀

