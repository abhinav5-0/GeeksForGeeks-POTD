Day# Maximize Number of 1's

**Difficulty:** Medium
**Accuracy:** 39.46%
**Submissions:** 77K+
**Points:** 4
**Average Time:** 20m

---

## Problem Statement

You are given a binary array `arr[]` containing only `0`s and `1`s and an integer `k`. You are allowed to flip **at most `k` zeros to ones**.

Your task is to find the **maximum number of consecutive `1`s** that can be obtained in the array after performing the operation at most `k` times.

---

## Examples

### Example 1

**Input:**
`arr[] = [1, 0, 1], k = 1`

**Output:**
`3`

**Explanation:**
By flipping the zero at index `1`, we get the longest subarray from index `0` to `2` containing all `1`s.

---

### Example 2

**Input:**
`arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2`

**Output:**
`5`

**Explanation:**
By flipping the zeros at indices `4` and `6`, we get the longest subarray from index `3` to `7` containing all `1`s.

---

### Example 3

**Input:**
`arr[] = [1, 1], k = 2`

**Output:**
`2`

**Explanation:**
The array already has the maximum consecutive `1`s, so no operation is required.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ k ≤ arr.size()`
* `0 ≤ arr[i] ≤ 1`

---

## Key Idea

This problem can be efficiently solved using the **Sliding Window / Two Pointer** technique.

We maintain a window that contains **at most `k` zeros** and try to maximize the window size.

---

👉 **Implementations in C++, Java, and Python can be written using the same sliding window logic.**
