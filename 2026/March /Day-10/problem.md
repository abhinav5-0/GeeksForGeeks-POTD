# Subarrays with First Element Minimum

**Difficulty:** Medium
**Accuracy:** 72.88%
**Submissions:** 2K+
**Points:** 4

## Problem Statement

You are given an integer array `arr[]`. Your task is to **count the number of subarrays where the first element is the minimum element of that subarray**.

### Note

A subarray is valid if its **first element is not greater than any other element** in that subarray.

## Examples

### Example 1

**Input:**
`arr = [1, 2, 1]`

**Output:**
`5`

**Explanation:**

All possible subarrays:

```
[1], [1, 2], [1, 2, 1], [2], [2, 1], [1]
```

Valid subarrays:

```
[1], [1, 2], [1, 2, 1], [2], [1]
```

Total = **5**

### Example 2

**Input:**
`arr = [1, 3, 5, 2]`

**Output:**
`8`

**Explanation:**

Valid subarrays:

```
[1], [1, 3], [1, 3, 5], [1, 3, 5, 2], [3], [3, 5], [5], [2]
```

Total = **8**

## Constraints

* `1 ≤ arr.size() ≤ 4 * 10^4`
* `1 ≤ arr[i] ≤ 10^5`
