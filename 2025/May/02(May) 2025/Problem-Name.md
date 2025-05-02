# Problem Statement: Bitonic Point

## Difficulty:

Easy

## Problem Description:

Given an array of integers `arr[]` that is first strictly increasing and then maybe strictly decreasing, find the **bitonic point**, that is, the maximum element in the array.

A Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.

> Note: It is guaranteed that the array contains **exactly one** bitonic point.

---

## Input:

* An array `arr[]` of size `n` where:

  * `3 ≤ n ≤ 10^5`
  * `1 ≤ arr[i] ≤ 10^6`

## Output:

* Return the **maximum** element of the array (the bitonic point).

---

## Examples:

### Example 1:

**Input:** `arr = [1, 2, 4, 5, 7, 8, 3]`

**Output:** `8`

**Explanation:** Elements before 8 are strictly increasing `[1, 2, 4, 5, 7]` and elements after 8 are strictly decreasing `[3]`.

### Example 2:

**Input:** `arr = [10, 20, 30, 40, 50]`

**Output:** `50`

**Explanation:** Elements before 50 are strictly increasing and there are no elements after 50.

### Example 3:

**Input:** `arr = [120, 100, 80, 20, 0]`

**Output:** `120`

**Explanation:** There are no elements before 120 and elements after 120 are strictly decreasing.

---

## Constraints:

* `3 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^6`

---

## Optimal Approach:

Use **Binary Search** to find the peak (bitonic point) in `O(log N)` time.

1. If `arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]` -> return `arr[mid]`.
2. If `arr[mid] < arr[mid+1]` -> move right.
3. If `arr[mid] > arr[mid+1]` -> move left.

---

## Time Complexity:

* **O(log N)** using binary search.

## Space Complexity:

* **O(1)** (in-place computation).
