# Problem: Equalize the Towers

**Difficulty:** Medium
**Accuracy:** 52.18%
**Submissions:** 11K+
**Points:** 4

---

## Problem Statement

You are given two arrays:

* `heights[]` representing the heights of towers
* `cost[]` where each element represents the cost of modifying the height of the respective tower.

The goal is to make all towers the **same height** by either **adding or removing** blocks from each tower.

Modifying the height of tower `i` (either increasing or decreasing it) by 1 unit costs `cost[i]`.

Return the **minimum total cost** to equalize the heights of all towers.

---

## Input

* `1 <= heights.length == cost.length <= 10^5`
* `1 <= heights[i] <= 10^4`
* `1 <= cost[i] <= 10^3`

---

## Output

* Return a single integer denoting the **minimum cost** to equalize all towers.

---

## Examples

### Example 1

**Input:**

```
heights = [1, 2, 3]
cost = [10, 100, 1000]
```

**Output:**

```
120
```

**Explanation:**
We can equalize by increasing heights\[0] from 1 to 3 and heights\[1] from 2 to 3.
Cost = (3-1)\*10 + (3-2)\*100 = 20 + 100 = 120.

### Example 2

**Input:**

```
heights = [7, 1, 5]
cost = [1, 1, 1]
```

**Output:**

```
6
```

**Explanation:**
Set all towers to height 5. Total cost = |7-5|\*1 + |1-5|\*1 + |5-5|\*1 = 2 + 4 + 0 = 6.

---

## Constraints

* Array sizes are up to 100,000
* Each modification has a cost associated
* Efficient algorithm required (preferably using ternary/binary search on height space)

---

## Tags

`Binary Search` `Optimization` `Greedy` `Prefix Sum` `Mathematics`
