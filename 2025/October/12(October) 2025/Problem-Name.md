## Distribute Candies

**Difficulty:** Hard
**Accuracy:** 63.24%
**Submissions:** 35K+
**Points:** 8

---

### 🧩 Problem Statement

You are given the root of a binary tree with `n` nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is `n`. In one move, you can select any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction.

The task is to determine the **minimum number of moves required** to ensure that every node in the tree has exactly one candy.

> Note: The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

---

### 💡 Example 1

**Input:**
`root = [5, 0, 0, N, N, 0, 0]`

**Output:**
`6`

**Explanation:**

```
Move 1 candy from root to left child
Move 1 candy from root to right child
Move 1 candy from right child to root->right->left node
Move 1 candy from root to right child
Move 1 candy from right child to root->right->right node
Move 1 candy from root to right child
Total moves = 6
```

---

### 💡 Example 2

**Input:**
`root = [2, 0, 0, N, N, 3, 0]`

**Output:**
`4`

**Explanation:**

```
Move 1 candy from root to left child
Move 1 candy from root->right->left node to root->right node
Move 1 candy from root->right node to root->right->right node
Move 1 candy from root->right->left node to root->right node
Total moves = 4
```

---

### ⚙️ Constraints

* 1 ≤ n ≤ 3 * 10³
* 0 ≤ Node->data ≤ n
* The sum of all Node->data = n

---

### 🧠 Approach

Each node must end up with **exactly 1 candy**.
We use a **postorder DFS traversal** to calculate the imbalance of candies at each node.

For each node:

1. Compute the net candy balance from left and right children.
2. Count how many moves are needed to balance candies between the node and its children.
3. Return the net candy balance of the node to its parent.

**Net balance formula:**

```
Balance = node->data + leftBalance + rightBalance - 1
```

The `-1` ensures the node keeps one candy for itself.

---

### 🧩 Code Implementation

```cpp
class Solution {
  public:
    int moves = 0;

    int dfs(Node* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        moves += abs(left) + abs(right);

        // Net balance of candies for this node
        return root->data + left + right - 1;
    }

    int distCandy(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
```

---

### 🧮 Example Walkthrough

**Input:**
`root = [3, 0, 0]`

**Steps:**

* Left child (0) → needs 1 candy → balance = -1
* Right child (0) → needs 1 candy → balance = -1
* Root (3) → gives 1 candy to each child

**Moves = |−1| + |−1| = 2**
**Output:** 2

---

### ⏱️ Complexity Analysis

| Type  | Complexity                                |
| ----- | ----------------------------------------- |
| Time  | **O(n)** (each node visited once)         |
| Space | **O(h)** (recursion stack height of tree) |

---

### ✅ Key Takeaway

The problem relies on **postorder traversal** to compute the local imbalances first and aggregate the total number of candy moves across the tree.
