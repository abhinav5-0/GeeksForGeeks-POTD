# Form the Largest Number

**Difficulty:** Medium
**Accuracy:** 37.82%
**Submissions:** 196K+
**Points:** 4

---

## Problem Statement

Given an array of integers `arr[]` representing **non-negative integers**, arrange them such that after **concatenating** all of them in order, it results in the **largest possible number**.

Since the result may be very large, return it as a **string**.

---

## Examples

### Example 1

**Input:**

```
arr[] = [3, 30, 34, 5, 9]
```

**Output:**

```
9534330
```

**Explanation:**
Given numbers are `[3, 30, 34, 5, 9]`, the arrangement `[9, 5, 34, 3, 30]` gives the largest value.

---

### Example 2

**Input:**

```
arr[] = [54, 546, 548, 60]
```

**Output:**

```
6054854654
```

**Explanation:**
Given numbers are `[54, 546, 548, 60]`, the arrangement `[60, 548, 546, 54]` gives the largest value.

---

### Example 3

**Input:**

```
arr[] = [3, 4, 6, 5, 9]
```

**Output:**

```
96543
```

**Explanation:**
Given numbers are `[3, 4, 6, 5, 9]`, the arrangement `[9, 6, 5, 4, 3]` gives the largest value.

---

## Constraints

* (1 \leq arr.size() \leq 10^5)
* (0 \leq arr[i] \leq 10^5)

---

## Notes

* The result should be returned as a **string**.
* Be careful with edge cases like multiple zeros.
* Custom sorting logic is required to
