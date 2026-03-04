# Max XOR Subarray of Size K

**Difficulty:** Medium
**Accuracy:** 55.63%
**Submissions:** 25K+
**Points:** 4
**Average Time:** 15m

---

## Problem Statement

Given an array of integers `arr[]` and a number `k`. Return the **maximum XOR** of a subarray of size `k`.

> **Note:** A subarray is a contiguous part of any given array.

---

## Examples

### Example 1

**Input:**

```
arr[] = [2, 5, 8, 1, 1, 3]
k = 3
```

**Output:**

```
15
```

**Explanation:**
`arr[0] ^ arr[1] ^ arr[2] = 15`, which is maximum.

---

### Example 2

**Input:**

```
arr[] = [1, 2, 4, 5, 6]
k = 2
```

**Output:**

```
6
```

**Explanation:**
`arr[1] ^ arr[2] = 6`, which is maximum.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `0 ≤ arr[i] ≤ 10^6`
* `1 ≤ k ≤ arr.size()`

---

## Approach

* Compute XOR of first `k` elements.
* Use **sliding window technique**:

  * Remove left element using XOR.
  * Add new right element using XOR.
* Keep track of maximum XOR found.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

---

## Tags

* Arrays
* Sliding Window
* Bit Manipulation
