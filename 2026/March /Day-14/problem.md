# Top View of Binary Tree

## Difficulty

Medium

## Problem Statement

Given the **root** of a binary tree, return the **top view** of the binary tree.

The **top view** of a binary tree is the set of nodes visible when the tree is viewed from the top.

### Notes

* Return nodes from the **leftmost node to the rightmost node**.
* If multiple nodes overlap at the same horizontal position, only the **topmost (closest to the root)** node is included.

---

## Examples

### Example 1

**Input**

```
root = [1, 2, 3]
```

**Output**

```
[2, 1, 3]
```

**Explanation**
The nodes visible from the top are `2`, `1`, and `3`.

---

### Example 2

**Input**

```
root = [10, 20, 30, 40, 60, 90, 100]
```

**Output**

```
[40, 20, 10, 30, 100]
```

**Explanation**
From the top view of the tree, the visible nodes are `40`, `20`, `10`, `30`, and `100`.

---

## Constraints

* `1 ≤ number of nodes ≤ 10^5`
* `1 ≤ node->data ≤ 10^5`

---

## Approach

The idea is to track the **horizontal distance (HD)** of each node from the root.

* Root node has `HD = 0`
* Left child has `HD = parentHD - 1`
* Right child has `HD = parentHD + 1`

We perform **Breadth First Search (BFS)** and store the **first node encountered at every horizontal distance**.

### Steps

1. Use a **queue** for BFS traversal.
2. Store pairs of `(node, horizontalDistance)`.
3. Use a **map** to store the first node for each HD.
4. Traverse the tree level by level.
5. If a horizontal distance is not already present in the map, store that node.
6. Finally, extract values from the map in sorted order of HD.

---

## Time Complexity

`O(N log N)` (due to ordered map)

## Space Complexity

`O(N)`

---

## Tags

Binary Tree, BFS, HashMap, Tree Traversal
