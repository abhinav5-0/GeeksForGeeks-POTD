
# Pythagorean Triplet

**Difficulty:** Medium
**Points:** 4

## Problem Statement

Given an array `arr[]`, return **true** if there exists a triplet `(a, b, c)` in the array such that:

```
a^2 + b^2 = c^2
```

Where `a`, `b`, and `c` are elements of the array at **different indices**. Otherwise return **false**.

---

## Examples

### Example 1

**Input:**
`arr[] = [3, 2, 4, 6, 5]`

**Output:**
`true`

**Explanation:**
`3^2 + 4^2 = 5^2`, therefore `(3,4,5)` is a Pythagorean triplet.

---

### Example 2

**Input:**
`arr[] = [3, 8, 5]`

**Output:**
`false`

**Explanation:**
No such triplet exists.

---

### Example 3

**Input:**
`arr[] = [1, 1, 1]`

**Output:**
`false`

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^3`

---

## Approach

1. Square every element in the array.
2. Sort the squared array.
3. Fix the largest element as `c^2`.
4. Use **two pointers** to check if there exist `a^2` and `b^2` such that:

```
a^2 + b^2 = c^2
```

5. If found, return `true`, otherwise continue.

**Time Complexity:** `O(n^2)`
**Space Complexity:** `O(1)` (ignoring input modification)
