# Flip to Maximize 1s

**Difficulty:** Medium
**Accuracy:** 23.15%
**Submissions:** 71K+
**Points:** 4

---

## Problem Statement

Given an array `arr[]` consisting of `0`s and `1`s. A **flip operation** involves changing all `0`s to `1`s and all `1`s to `0`s within a contiguous subarray.

Formally, select a range `(l, r)` in the array `arr[]` such that:

```
0 ≤ l ≤ r < n
```

Flip all the elements in this range.

Your task is to **return the maximum number of `1`s** you can obtain in the array after performing **at most one flip operation**.

---

## Examples

### Example 1

**Input:**

```
arr[] = [1, 0, 0, 1, 0]
```

**Output:**

```
4
```

**Explanation:**
By flipping the subarray from index `1` to `2`, the array becomes:

```
[1, 1, 1, 1, 0]
```

Total number of `1`s = **4**, which is maximum.

---

### Example 2

**Input:**

```
arr[] = [1, 0, 0, 1, 0, 0, 1]
```

**Output:**

```
6
```

**Explanation:**
By flipping the subarray from index `1` to `5`, the array becomes:

```
[1, 1, 1, 0, 1, 1, 1]
```

Total number of `1`s = **6**, which is maximum.

---

## Constraints

```
1 ≤ n ≤ 10^6
0 ≤ arr[i] ≤ 1
```

---

## Notes

* You are allowed to perform **at most one flip**.
* If the array already contains all `1`s, the answer is simply the count of `1`s.
* Efficient solutions are expected due to large constraints.
