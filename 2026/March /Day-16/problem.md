# K Sum Paths

## Problem

Given the root of a binary tree and an integer `k`, determine the number of **downward-only paths** where the sum of the node values in the path equals `k`.

* A path can start and end at any node.
* The path must always move **downward** (from parent to child).

## Example 1

**Input:**

```
root = [8, 4, 5, 3, 2, N, 2, 3, -2, N, 1]
k = 7
```

**Output:**

```
3
```

**Explanation:**
The paths with sum `k` are:

* 4 → 3
* 4 → 2 → 1
* 5 → 2

## Example 2

**Input:**

```
root = [1, 2, 3]
k = 3
```

**Output:**

```
2
```

**Explanation:**
The paths with sum `k` are:

* 1 → 2
* 3

## Constraints

* `1 ≤ number of nodes ≤ 10^4`
* `-100 ≤ node value ≤ 100`
* `-10^9 ≤ k ≤ 10^9`

## Approach

Use **DFS traversal** with a running path list.

Steps:

1. Traverse the tree using DFS.
2. Maintain a vector storing the path from root to the current node.
3. For each node, check sums of all subpaths ending at that node.
4. If any sum equals `k`, increase the count.
5. Backtrack while returning from recursion.

**Time Complexity:** `O(N^2)` (worst case)

**Space Complexity:** `O(H)` where `H` is the tree height.

---

## Function Signature (C++)

```cpp
int sumK(Node *root, int k);
```
