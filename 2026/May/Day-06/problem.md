# Size of Binary Tree

## Problem Statement

Given the root of a binary tree, return the size of the tree.

The size of a binary tree is the total number of nodes present in the tree.

---

## Approach

We use **recursion** to count nodes.

### Steps:

1. If the node is `NULL`, return `0`.
2. Count the current node as `1`.
3. Recursively count nodes in the left subtree.
4. Recursively count nodes in the right subtree.
5. Return:

```cpp
1 + size(left subtree) + size(right subtree)
```

---

## Recursive Formula

genui{"math_block_widget_always_prefetch_v2":{"content":"Size(Tree)=1+Size(Left)+Size(Right)"}}

---

## C++ Solution

```cpp
class Solution {
public:
    int getSize(Node* root) {
        // Base case
        if(root == NULL)
            return 0;

        // Count current node + left subtree + right subtree
        return 1 + getSize(root->left) + getSize(root->right);
    }
};
```

---

## Dry Run

### Example Tree

```text
        1
       / \
      2   3
```

### Function Calls

```text
getSize(1)
= 1 + getSize(2) + getSize(3)
= 1 + 1 + 1
= 3
```

Output:

```text
3
```

---

## Time Complexity

```text
O(N)
```

Because every node is visited exactly once.

---

## Space Complexity

```text
O(H)
```

Where:

* `H` = height of the tree
* Recursive stack space is used.

---

## Key Points

* Base case handles empty tree.
* Recursion makes the solution simple.
* Total nodes = Left subtree nodes + Right subtree nodes + Current node.
