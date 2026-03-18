# Distribute Candies

**Difficulty:** Hard
**Accuracy:** 63.24%
**Submissions:** 43K+
**Points:** 8

---

## Problem Statement

You are given the **root of a binary tree** with `n` nodes. Each node contains a certain number of candies, and the total number of candies across all nodes is `n`.

In one move, you can transfer **one candy** from one node to another. The transfer can occur between a parent and child node in either direction.

Your task is to determine the **minimum number of moves** required so that every node in the tree has **exactly one candy**.

> **Note:** It is always possible to achieve such a configuration.

---

## Approach (DFS + Greedy)

* Use **post-order DFS traversal**.
* For each node:

  * Calculate excess candies from left and right subtree.
  * Add absolute values of these excesses to the total moves.
  * Return net balance of candies:

```
net = node->data + left + right - 1
```

---

## Example 1

**Input:**

```
root = [5, 0, 0, N, N, 0, 0]
```

**Output:**

```
6
```

**Explanation:**

* Move candies step by step from root to children and further down.
* Total moves required = 6

---

## Example 2

**Input:**

```
root = [2, 0, 0, N, N, 3, 0]
```

**Output:**

```
4
```

**Explanation:**

* Redistribute candies optimally across tree.
* Total moves required = 4

---

## Constraints

* (1 \leq n \leq 3 * 10^3)
* (0 \leq Node->data \leq n)
* Sum of all node values = n

---

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(h) (recursion stack)

---

## Key Idea

Every node should have exactly **1 candy**.

* If a node has extra candies → pass them up.
* If a node lacks candies → request from parent.

Total moves = sum of absolute imbalances across edges.

---

## Pseudocode

```
function dfs(node):
    if node is null:
        return 0

    left = dfs(node.left)
    right = dfs(node.right)

    moves += abs(left) + abs(right)

    return node.data + left + right - 1
```

---

## Tags

* Tree
* DFS
* Greedy
* Binary Tree
