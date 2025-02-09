# Maximum Path Sum from Any Node in a Binary Tree

## Problem Statement
Given a binary tree, the task is to find the **maximum path sum**. The path may start and end at **any node** in the tree.

### **Example 1**
**Input:**  
```
root = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
```
**Output:**  
```
42
```
**Explanation:**
The maximum path sum is **20 → 2 → 10 → 10** = **42**.

### **Example 2**
**Input:**  
```
root = [-17, 11, 4, 20, -2, 10]
```
**Output:**  
```
31
```
**Explanation:**
The maximum path sum is **20 → 11 → -17 → 4 → 10** = **31**.

---

## Solution Approach
- We use **Depth-First Search (DFS)** with recursion to traverse the tree.
- At each node, we calculate:
  - Maximum path sum from **left** subtree
  - Maximum path sum from **right** subtree
  - Maximum path sum including the **current node**
- We update the **global maximum sum** found so far.
- The function returns the **maximum path sum** that includes the root and either the left or right subtree.

---

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node Definition
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int maxPathSumUtil(Node* root, int &res) {
        if (root == NULL) return 0;

        int leftSum = max(0, maxPathSumUtil(root->left, res));
        int rightSum = max(0, maxPathSumUtil(root->right, res));

        int maxPathThroughRoot = root->data + leftSum + rightSum;

        res = max(res, maxPathThroughRoot);

        return root->data + max(leftSum, rightSum);
    }

    int findMaxSum(Node *root) {
        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** `O(N)` (Each node is visited once)
- **Space Complexity:** `O(H)` (Recursive stack, where `H` is the tree height)

---

## How to Run
1. Clone the repository:
   ```sh
   git clone https://github.com/your-repo-name.git
   cd your-repo-name
   ```
2. Compile the code:
   ```sh
   g++ -o main main.cpp
   ```
3. Run the executable:
   ```sh
   ./main
   ```

---

## Contributing
Feel free to open issues or submit pull requests to improve the implementation.

## License
This project is licensed under the MIT License.

