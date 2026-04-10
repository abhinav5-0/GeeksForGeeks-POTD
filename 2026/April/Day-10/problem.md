# Sorted Subsequence of Size 3

## 🧩 Problem Statement

Given an array `arr[]`, find any subsequence of three elements such that:

```
arr[i] < arr[j] < arr[k] and i < j < k
```

If such a subsequence exists, return the three elements as an array. Otherwise, return an empty array.

---

## 📝 Notes

* The driver code will print **1** if the returned subsequence is valid and present in the array.
* The driver code will print **0** if no such subsequence exists.
* If the returned subsequence does not satisfy the required conditions, the output will be **-1**.

---

## 📌 Examples

### Example 1

```
Input: arr[] = [12, 11, 10, 5, 6, 2, 30]
Output: 1
Explanation: As 5 < 6 < 30, and they appear in order.
```

### Example 2

```
Input: arr[] = [1, 2, 3, 4]
Output: 1
Explanation: The array is already sorted.
```

### Example 3

```
Input: arr[] = [4, 3, 2, 1]
Output: 0
Explanation: No increasing subsequence of size 3 exists.
```

---

## ⚙️ Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^6`

---

## 💡 Approach

We need to find three indices `i < j < k` such that:

* There exists a smaller element before `j`
* There exists a greater element after `j`

### Steps:

1. Create an array `smaller[]` where:

   * `smaller[j]` stores index of a smaller element on the left of `j`
2. Create an array `greater[]` where:

   * `greater[j]` stores index of a greater element on the right of `j`
3. Traverse the array:

   * If both `smaller[j]` and `greater[j]` are valid, return the triplet

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## 🧠 Intuition

For every middle element `arr[j]`, we try to check:

* Is there a smaller element before it?
* Is there a greater element after it?

If yes, we found our sorted subsequence of size 3.

---

## 🚀 Summary

* Use preprocessing with two arrays
* Avoid brute force `O(n^3)`
* Efficient linear solution exists
