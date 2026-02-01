# K Sized Subarray Maximum

**Difficulty:** Medium
**Accuracy:** 26.04%
**Points:** 4

---

## Problem Statement

You are given:

* An array `arr[]` of **positive integers**
* An integer `k`

Your task is to find the **maximum element** in every **contiguous subarray of size `k`**.

Return an array containing these maximum values.

---

## Example 1

**Input:**
`arr = [1, 2, 3, 1, 4, 5, 2, 3, 6]`, `k = 3`

**Output:**
`[3, 3, 4, 5, 5, 5, 6]`

**Explanation:**

* Subarray `[1, 2, 3]` → max = 3
* Subarray `[2, 3, 1]` → max = 3
* Subarray `[3, 1, 4]` → max = 4
* Subarray `[1, 4, 5]` → max = 5
* Subarray `[4, 5, 2]` → max = 5
* Subarray `[5, 2, 3]` → max = 5
* Subarray `[2, 3, 6]` → max = 6

---

## Example 2

**Input:**
`arr = [5, 1, 3, 4, 2]`, `k = 1`

**Output:**
`[5, 1, 3, 4, 2]`

**Explanation:**
When `k = 1`, every element itself is a subarray, so the output is the same as the input array.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `1 ≤ k ≤ arr.size()`
* `0 ≤ arr[i] ≤ 10^9`

---

## Efficient Approach (Deque / Sliding Window)

### Key Idea

We use a **deque (double-ended queue)** to store indices of useful elements for the current window:

* The deque maintains elements in **decreasing order of values**
* The **front** of the deque always holds the index of the **maximum element** of the current window

### Steps

1. Remove indices from the front that are **out of the current window**
2. Remove indices from the back whose values are **smaller than the current element**
3. Insert the current index
4. Once the window size reaches `k`, store the value at the front of the deque

---

## Time & Space Complexity

* **Time Complexity:** `O(n)`
  Each element is pushed and popped from the deque at most once.

* **Space Complexity:** `O(k)`
  Deque stores at most `k` indices.

---

## Notes

* This problem is a **classic sliding window + deque** question
* Very important for **interviews and competitive programming**
* Brute force (`O(n*k)`) will **TLE** for large inputs

---

✔ This method works efficiently even for very large arrays.
