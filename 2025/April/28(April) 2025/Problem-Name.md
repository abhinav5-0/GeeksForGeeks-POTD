# Maximum Sum of Non-Adjacent Nodes in a Binary Tree

## Problem Statement

Given a binary tree with an integer value associated with each node, select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected (i.e., if a node is included, its parent and children cannot be included).

### Input
- A binary tree where each node has an integer value.

### Output
- An integer representing the maximum sum of selected nodes with the given condition.

### Constraints
- 1 \u2264 Number of nodes \u2264 10\u2074
- 1 \u2264 Node value \u2264 10\u2075

---

## Examples

### Example 1
**Input:**
```
root[] = [11, 1, 2]
```
**Output:**
```
11
```
**Explanation:**
The maximum sum is obtained by selecting the node with value 11.

### Example 2
**Input:**
```
root[] = [1, 2, 3, 4, N, 5, 6]
```
**Output:**
```
16
```
**Explanation:**
The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected.

---

## Approach

We solve the problem using **Dynamic Programming on Trees**:

- For every node, we consider two scenarios:
  - **Include** the node: Add its value and recursively the maximum sum by **excluding** its children.
  - **Exclude** the node: Sum the maximum of including or excluding each child.

### Helper Function
Use a recursive function that returns a pair:
- `first`: Maximum sum including the current node.
- `second`: Maximum sum excluding the current node.

### Transition
- `include = node->data + left.second + right.second`
- `exclude = max(left.first, left.second) + max(right.first, right.second)`

Finally, take the maximum of including and excluding the root node.

---

## Code Implementation

```cpp
class Solution {
  public:
    pair<int, int> solve(Node* root) {
        if (root == NULL) return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int include = root->data + left.second + right.second;
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }

    int getMaxSum(Node *root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};
```

---

## Notes
- The solution runs in **O(N)** time, where **N** is the number of nodes, because each node is processed once.
- This approach is optimal for trees with up to 10\u2074 nodes.
- Memory usage is also efficient due to a simple recursion stack.

Would you also like a visual tree diagram showing how the DP values propagate from leaf to root? :seedling:

