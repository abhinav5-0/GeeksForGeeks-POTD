# K-th Smallest Element in a BST

## Problem Statement
Given a **Binary Search Tree (BST)** and an integer `k`, find the `k`-th smallest element in the BST. If there is no `k`-th smallest element, return `-1`.

### **Examples**
#### **Input 1:**
```plaintext
root = [2, 1, 3], k = 2
```
#### **Output 1:**
```plaintext
2
```
#### **Explanation:**
The inorder traversal of BST `[2, 1, 3]` is `[1, 2, 3]`, so the 2nd smallest element is `2`.

#### **Input 2:**
```plaintext
root = [2, 1, 3], k = 5
```
#### **Output 2:**
```plaintext
-1
```
#### **Explanation:**
The BST has only 3 elements, so there is no 5th smallest element.

#### **Input 3:**
```plaintext
root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 3
```
#### **Output 3:**
```plaintext
10
```
#### **Explanation:**
The inorder traversal of BST `[20, 8, 22, 4, 12, N, N, N, N, 10, 14]` is `[4, 8, 10, 12, 14, 20, 22]`, so the 3rd smallest element is `10`.

---

## **Approach**
We use **inorder traversal** (Left → Root → Right) to get elements in sorted order.

### **Time Complexity:**
- **O(N)** in the worst case (skewed BST)
- **O(k)** in the average case

### **Space Complexity:**
- **O(H)** (H = height of BST) due to the recursive stack in recursion or explicit stack in iteration.

---

## **Implementation (Iterative Using Stack)**
```cpp
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        stack<Node*> st;
        Node* curr = root;
        int count = 0;
        
        while (!st.empty() || curr != NULL) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;  // Move to leftmost node
            }
            
            curr = st.top();
            st.pop();
            
            count++;
            if (count == k) return curr->data;  // Found the k-th smallest element
            
            curr = curr->right;  // Move to right subtree
        }
        
        return -1;  // If k is larger than the number of nodes
    }
};
```

---

## **Alternative Approach (Recursive Inorder Traversal)**
```cpp
class Solution {
  public:
    int count = 0, result = -1;

    void inorder(Node* root, int k) {
        if (!root || result != -1) return;

        inorder(root->left, k);
        
        count++;
        if (count == k) {
            result = root->data;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(Node *root, int k) {
        inorder(root, k);
        return result;
    }
};
```

---

## **Final Thoughts**
- **Iterative Approach** is better in terms of avoiding recursion stack overflow in large trees.
- **Recursive Approach** is simpler and easier to read but may lead to stack overflow for skewed trees.
- **Edge Cases:**
  - When `k` is larger than the number of nodes, return `-1`.
  - When `k` is `1`, it should return the smallest element in the BST.

This solution efficiently finds the k-th smallest element in a BST using inorder traversal. 🚀
