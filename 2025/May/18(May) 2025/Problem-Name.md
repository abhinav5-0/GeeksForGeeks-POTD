# Spiral Order Traversal of Binary Tree

## Problem Statement

Given a binary tree, return the spiral (zigzag) level order traversal of its nodes' values. In spiral order traversal:

* Start from level 0 (root node), for all **even levels**, print nodes from **right to left**.
* For all **odd levels**, print nodes from **left to right**.

### Constraints:

* 1 <= Number of nodes <= 10^5
* 0 <= Node->data <= 10^5

## Input

The binary tree is given as a space-separated string where `N` denotes a NULL child.

## Output

Return a list of integers representing the spiral order traversal of the binary tree.

## Examples

### Example 1:

**Input:**

```
root = [1, 3, 2]
```

**Output:**

```
[1, 3, 2]
```

**Explanation:**

* Level 0: \[1] → right to left
* Level 1: \[3, 2] → left to right

### Example 2:

**Input:**

```
root = [10, 20, 30, 40, 60]
```

**Output:**

```
[10, 20, 30, 60, 40]
```

### Example 3:

**Input:**

```
root = [1, 2, N, 4]
```

**Output:**

```
[1, 2, 4]
```

---

## Function Signature (C++)

```cpp
vector<int> findSpiral(Node* root);
```

## C++ Implementation

```cpp
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);
        bool reverse = true;  // Start with right to left

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();

                int index = reverse ? levelSize - 1 - i : i;
                level[index] = node->data;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            for (int val : level)
                result.push_back(val);

            reverse = !reverse;
        }

        return result;
    }
};
```

---

## Notes

* Uses BFS traversal with a queue.
* Alternates insertion direction by toggling a boolean flag `reverse`.
* Efficient for large trees due to linear time complexity O(N).
