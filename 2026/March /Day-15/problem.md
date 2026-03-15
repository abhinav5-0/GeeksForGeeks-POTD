# Vertical Tree Traversal

**Difficulty:** Medium

## Problem

Given the root of a binary tree, find the **vertical traversal** of the tree starting from the **leftmost level to the rightmost level**.

If multiple nodes fall in the same vertical line, they should appear in the order they are visited in **level order traversal (BFS)**.

---

## Example 1

**Input**

```
root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, 10, 11, N]
```

**Output**

```
[[4], [2], [1, 5, 6, 11], [3, 8, 9], [7], [10]]
```

**Explanation**
Each vertical line is printed from left to right using horizontal distance from root.

---

## Example 2

**Input**

```
root = [1, 2, 3, 4, 5, N, 6]
```

**Output**

```
[[4], [2], [1, 5], [3], [6]]
```

---

## Approach

1. Use **level order traversal (BFS)** with a queue.
2. Track the **horizontal distance (HD)** from the root.

   * Root → HD = 0
   * Left child → HD - 1
   * Right child → HD + 1
3. Store nodes in a **map<int, vector<int>>** where:

   * key → horizontal distance
   * value → nodes at that vertical line
4. Traverse the map from **smallest HD to largest HD**.

---

## Time Complexity

```
O(N log N)
```

* BFS traversal → O(N)
* Ordered map insertion → O(log N)

## Space Complexity

```
O(N)
```

---

## Key Concepts

* Binary Tree
* Breadth First Search (BFS)
* Hash Map / Ordered Map
* Horizontal Distance

---

## Tags

`Binary Tree` `BFS` `Map` `Traversal`
