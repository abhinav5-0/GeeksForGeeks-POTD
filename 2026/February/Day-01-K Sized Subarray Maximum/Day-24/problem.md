# Longest Span in Two Binary Arrays

**Difficulty:** Medium
**Accuracy:** 48.22%
**Submissions:** 36K+
**Points:** 4

---

## Problem Statement

Given two binary arrays `a1[]` and `a2[]` of equal length. Find the **length of the longest common span (i, j)** such that `i ≤ j` and:

```
a1[i] + a1[i+1] + ... + a1[j] =
a2[i] + a2[i+1] + ... + a2[j]
```

---

## Examples

### Example 1

**Input:**
`a1[] = [0, 1, 0, 0, 0, 0]`
`a2[] = [1, 0, 1, 0, 0, 1]`

**Output:**
`4`

**Explanation:**
The longest span with same sum is from index 1 to 4 (0-based indexing).

---

### Example 2

**Input:**
`a1[] = [0, 1, 0, 1, 1, 1, 1]`
`a2[] = [1, 1, 1, 1, 1, 0, 1]`

**Output:**
`6`

**Explanation:**
The longest span with same sum is from index 1 to 6 (0-based indexing).

---

### Example 3

**Input:**
`a1[] = [0, 0, 0]`
`a2[] = [1, 1, 1]`

**Output:**
`0`

**Explanation:**
There is no span where the sum of the elements in `a1[]` and `a2[]` is equal.

---

## Constraints

* `1 ≤ a1.size() = a2.size() ≤ 10^6`
* `0 ≤ a1[i], a2[i] ≤ 1`

---

## Notes

* Both arrays contain only binary values (0 or 1).
* The solution should be efficient enough to handle large input sizes up to `10^6`.
