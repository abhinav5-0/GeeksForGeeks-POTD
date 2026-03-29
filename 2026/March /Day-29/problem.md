# Partitions with Given Difference

**Difficulty:** Medium
**Accuracy:** 36.76%
**Submissions:** 232K+
**Points:** 4
**Average Time:** 20m

---

## Problem Statement

Given an array `arr[]` and an integer `diff`, count the **number of ways** to partition the array into two subsets such that the difference between their sums is equal to `diff`.

### Note

A partition means dividing the array into two subsets `S1` and `S2` such that:

* Every element belongs to exactly one subset
* `S1 ∪ S2 = arr`

---

## Key Idea

Let:

* Sum of array = `totalSum`
* Sum of subset `S1` = `s1`
* Sum of subset `S2` = `s2`

We know:

```
s1 - s2 = diff
s1 + s2 = totalSum
```

Adding both:

```
2 * s1 = totalSum + diff
s1 = (totalSum + diff) / 2
```

👉 Problem reduces to **count subsets with sum = (totalSum + diff) / 2**

---

## Edge Cases

* If `(totalSum + diff)` is odd → return `0`
* If `totalSum < diff` → return `0`

---

## Approach (DP - Subset Sum Count)

Use Dynamic Programming to count number of subsets with given sum.

### Steps:

1. Compute `totalSum`
2. Check validity
3. Target = `(totalSum + diff) / 2`
4. Use DP to count subsets with given sum

---

## Example 1

**Input:**
`arr = [5, 2, 6, 4]`, `diff = 3`

**Output:**
`1`

**Explanation:**
Partition: `[6, 4]` and `[5, 2]`

---

## Example 2

**Input:**
`arr = [1, 1, 1, 1]`, `diff = 0`

**Output:**
`6`

---

## Example 3

**Input:**
`arr = [3, 2, 7, 1]`, `diff = 4`

**Output:**
`0`

---

## Constraints

* `1 ≤ arr.size() ≤ 50`
* `0 ≤ diff ≤ 50`
* `0 ≤ arr[i] ≤ 6`

---

## Complexity

* **Time Complexity:** `O(n * target)`
* **Space Complexity:** `O(target)`

---

## Summary

This is a classic **subset sum count** problem with a transformation trick:

✔ Convert partition problem → subset sum problem
✔ Use DP to count valid subsets
✔ Handle edge cases carefully
