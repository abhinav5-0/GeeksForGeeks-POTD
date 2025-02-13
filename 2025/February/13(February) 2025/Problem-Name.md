# Pair Sum in BST

## Problem Statement
Given a Binary Search Tree (BST) and a target sum, check whether there exists a pair of nodes in the BST whose values sum up to the given target.

## Examples
### Example 1
**Input:**
```
root = [7, 3, 8, 2, 4, N, 9]
target = 12
```
**Output:**
```
True
```
**Explanation:**
Nodes 8 and 4 add up to 12.

### Example 2
**Input:**
```
root = [9, 5, 10, 2, 6, N, 12]
target = 23
```
**Output:**
```
False
```
**Explanation:**
No such pair exists.

## Constraints
- 1 ≤ Number of Nodes ≤ 10⁵
- 1 ≤ Target ≤ 10⁶

## Solution Approach
We use an **inorder traversal with a hash set** to efficiently find the pair. The approach works in **O(N) time complexity and O(N) space complexity**.

## Implementation
```cpp
class Solution {
  public:
    bool findTarget(Node *root, int target) {
        unordered_set<int> seen;
        return inorder(root, target, seen);
    }
    
  private:
    bool inorder(Node* root, int target, unordered_set<int>& seen) {
        if (!root) return false;
        
        if (seen.count(target - root->data)) return true;
        
        seen.insert(root->data);
        
        return inorder(root->left, target, seen) || inorder(root->right, target, seen);
    }
};
```


## License
This project is open-source and available under the MIT License.

