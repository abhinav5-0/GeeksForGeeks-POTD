# Problem of the Day: Construct Tree from Inorder & Preorder

## Problem Statement
Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

**Note:** The output should be printed in postorder traversal.

---

## Examples

### Example 1:
**Input:**  
```plaintext
inorder[] = [1, 6, 8, 7]
preorder[] = [1, 6, 7, 8]
```
**Output:**  
```plaintext
8 7 6 1
```
**Explanation:**  
The constructed tree:
```
       1
      / \
     6   
      \  
       7
        \
         8
```
Postorder Traversal: 8 7 6 1

### Example 2:
**Input:**  
```plaintext
inorder[] = [3, 1, 4, 0, 2, 5]
preorder[] = [0, 1, 3, 4, 2, 5]
```
**Output:**  
```plaintext
3 4 1 5 2 0
```
**Explanation:**  
The constructed tree:
```
        0
       / \
      1   2
     / \   \
    3   4   5
```
Postorder Traversal: 3 4 1 5 2 0

### Example 3:
**Input:**  
```plaintext
inorder[] = [2, 5, 4, 1, 3]
preorder[] = [1, 4, 5, 2, 3]
```
**Output:**  
```plaintext
2 5 4 3 1
```

---

## Constraints:
- **1 ≤ Number of nodes ≤ 1000**
- **0 ≤ Node values ≤ 1000**

---

## Approach
1. **Understand Traversals:**
   - **Preorder (Root-Left-Right)**: First node is the root.
   - **Inorder (Left-Root-Right)**: Left subtree elements appear before the root.
   - **Postorder (Left-Right-Root)**: Needed for output.

2. **Efficient Construction:**
   - Use a **hashmap** to store the index of inorder elements for **O(1) lookups**.
   - Recursively construct left and right subtrees from preorder and inorder.

3. **Implementation Steps:**
   - Start with the first element of preorder as the root.
   - Find its position in inorder to divide left and right subtrees.
   - Recursively build left and right subtrees.
   - Use a global index to keep track of preorder elements.

---

## Code Implementation (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) { data = x; left = right = NULL; }
};

void printPostOrder(Node *root) {
    if (!root) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preIndex = 0;

    Node* constructTree(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        int curr = preorder[preIndex++];
        Node* node = new Node(curr);
        if (inStart == inEnd) return node;
        int inIndex = inorderMap[curr];
        node->left = constructTree(preorder, inorder, inStart, inIndex - 1);
        node->right = constructTree(preorder, inorder, inIndex + 1, inEnd);
        return node;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        inorderMap.clear();
        preIndex = 0;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        return constructTree(preorder, inorder, 0, inorder.size() - 1);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> inorder, preorder;
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num) inorder.push_back(num);
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num) preorder.push_back(num);
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);
        printPostOrder(root);
        cout << endl;
    }
    return 0;
}
```

---

## Complexity Analysis
- **Time Complexity:** `O(n)` (Each node is processed once, hashmap lookup is `O(1)`).
- **Space Complexity:** `O(n)` (Hashmap + recursion stack in worst case).

---

## Summary
✅ **Used Preorder for root selection.**  
✅ **Optimized Inorder index lookups with HashMap.**  
✅ **Built Tree Recursively.**  
✅ **Printed Postorder Traversal.**  

This method ensures an efficient and structured approach to reconstructing a binary tree from its traversals! 🚀

