# Height of Binary Tree

This repository contains a C++ solution to find the height of a binary tree. The height of a binary tree is defined as the number of edges on the longest path from the root node to a leaf node.

## Problem Statement

Given a binary tree, find its height.

### Examples

**Example 1:**
Input: root[] = [12, 8, 18, 5, 11]
Output: 2
Explanation: The longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.



**Example 2:**
Input: root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]
Output: 3
Explanation: The longest path from the root (node 1) to a leaf node 6 has 3 edges.



### Constraints
- The number of nodes in the tree is between 1 and 10^5.
- The value of each node is between 0 and 10^5.

## Solution

The solution uses a recursive approach to calculate the height of the binary tree:

1. **Base Case**: If the node is `NULL`, return -1.
2. **Recursive Case**: Recursively calculate the height of the left and right subtrees. The height of the current node is the maximum of the heights of the left and right subtrees plus 1.

### Code Implementation

```cpp
class Solution {
public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // Base case: if the node is null, return -1
        if (node == NULL) {
            return -1;
        }
        
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // The height of the current node is the maximum of the left and right heights plus 1
        return max(leftHeight, rightHeight) + 1;
    }
};
```

## Contributing
If you'd like to contribute to this project, feel free to open an issue or submit a pull request. All contributions are welcome!

## License
This project is licensed under the MIT License. See the LICENSE file for details.
