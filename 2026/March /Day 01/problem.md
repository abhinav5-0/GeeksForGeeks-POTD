# Move All Zeroes to End

## Problem Statement

You are given an array `arr[]` of non-negative integers. Your task is to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements.

The operation must be performed **in-place**, meaning you should not use extra space for another array.

---

## Examples

### Example 1

**Input:**
`arr[] = [1, 2, 0, 4, 3, 0, 5, 0]`

**Output:**
`[1, 2, 4, 3, 5, 0, 0, 0]`

**Explanation:**
There are three `0`s that are moved to the end.

---

### Example 2

**Input:**
`arr[] = [10, 20, 30]`

**Output:**
`[10, 20, 30]`

**Explanation:**
No change in array as there are no `0`s.

---

### Example 3

**Input:**
`arr[] = [0, 0]`

**Output:**
`[0, 0]`

**Explanation:**
No change in array as all elements are `0`s.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i] ≤ 10^5`

---

## Expected Time and Space Complexity

* **Time Complexity:** O(N)
* **Auxiliary Space:** O(1)

---

## Approach

1. Initialize a pointer `j = 0` to track the position of the next non-zero element.
2. Traverse the array from left to right.
3. Whenever a non-zero element is found, swap it with the element at index `j`.
4. Increment `j`.
5. Continue until the end of the array.

This ensures all non-zero elements maintain their relative order and zeros are pushed to the end.
