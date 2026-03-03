# Longest Subarray with At Most Two Distinct Integers

**Difficulty:** Medium
**Accuracy:** 47.98%
**Submissions:** 143K+
**Points:** 4
**Average Time:** 30m

---

## Problem Statement

Given an array `arr[]` consisting of positive integers, your task is to find the length of the **longest subarray** that contains **at most two distinct integers**.

---

## Examples

### Example 1

**Input:**
`arr[] = [2, 1, 2]`

**Output:**
`3`

**Explanation:**
The entire array `[2, 1, 2]` contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is `3`.

---

### Example 2

**Input:**
`arr[] = [3, 1, 2, 2, 2, 2]`

**Output:**
`5`

**Explanation:**
The longest subarray containing at most two distinct integers is `[1, 2, 2, 2, 2]`, which has a length of `5`.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^5`

---

## Expected Approach

Use the **Sliding Window Technique** with a HashMap (or dictionary) to:

* Expand the window by moving the right pointer.
* Track the frequency of elements inside the window.
* If the number of distinct elements exceeds 2, shrink the window from the left.
* Keep updating the maximum length found.

**Time Complexity:** `O(N)`
**Space Complexity:** `O(1)` (at most 2 distinct elements stored in map)
