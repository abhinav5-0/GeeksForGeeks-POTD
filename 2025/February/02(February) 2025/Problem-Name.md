# Level Order Traversal of Binary Tree

## Overview
This repository contains a C++ implementation for performing **Level Order Traversal** of a binary tree. The level order traversal is done using a **Breadth-First Search (BFS)** approach utilizing a queue.

## Problem Statement
Given the root of a binary tree with `n` nodes, the task is to find its level order traversal. The traversal follows a breadth-first approach, visiting nodes level by level.

### **Example**
#### **Input:**
```
root[] = [1, 2, 3]
```
#### **Tree Structure:**
```
    1
   / \
  2   3
```
#### **Output:**
```
[[1], [2, 3]]
```

## Implementation
The `levelOrder` function performs the traversal using a queue.

### **Algorithm**
1. **Edge Case:** If the tree is empty, return an empty result.
2. **Use a Queue:** Start with the root node.
3. **Iterate Level by Level:**
   - Process each level by dequeuing all nodes at the current level.
   - Store their values in a temporary vector.
   - Enqueue their left and right children (if any).
4. **Store and Return Result:** Append the level vector to the final result.

## Code Implementation
```cpp
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (!root) return result; // Edge case: Empty tree
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->data);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};
```

## Complexity Analysis
- **Time Complexity:** `O(n)`, since we visit each node once.
- **Space Complexity:** `O(n)`, as we use a queue and store the traversal.



## Contributing
Feel free to submit issues or pull requests for improvements!

## License
This project is licensed under the MIT License.

