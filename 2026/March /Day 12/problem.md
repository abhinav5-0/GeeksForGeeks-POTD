# Minimum K Consecutive Bit Flips

**Difficulty:** Hard
**Accuracy:** 58.52%
**Points:** 8

## Problem Statement

You are given a binary array `arr[]` containing only `0`s and `1`s and an integer `k`.

In one operation, you can select a contiguous subarray of length `k` and flip all its bits:

* `0` becomes `1`
* `1` becomes `0`

Your task is to find the **minimum number of operations** required to make the entire array consist of only `1`s.

If it is **not possible**, return `-1`.

---

## Examples

### Example 1

**Input:**
`arr = [1,1,0,0,0,1,1,0,1,1,1], k = 2`

**Output:**
`4`

**Explanation:**
4 operations are required to convert all `0`s to `1`s.

Operations performed:

1. Flip subarray `[2,3]`
   Result: `[1,1,1,1,1,1,1,0,1,1,1]`

2. Flip subarray `[4,5]`
   Result: `[1,1,1,1,0,1,0,1,1,1,1]`

3. Flip subarray `[5,6]`
   Result: `[1,1,1,1,1,0,0,1,1,1,1]`

4. Flip subarray `[6,7]`
   Result: `[1,1,1,1,1,1,1,1,1,1,1]`

---

### Example 2

**Input:**
`arr = [0,0,1,1,1,0,0], k = 3`

**Output:**
`-1`

**Explanation:**
It is not possible to convert all elements to `1`s using operations of length `k`.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `1 ≤ k ≤ arr.size()`

---

## Approach

A greedy approach is used:

1. Traverse the array from left to right.
2. If the current bit becomes `0` after considering previous flips, start a flip operation from this index.
3. Track flips using a difference array or sliding window technique.
4. If a flip cannot be applied because the remaining length is smaller than `k`, return `-1`.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`
