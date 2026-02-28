# Find the Closest Pair from Two Arrays

## Difficulty: Easy

---

## Problem Statement

Given two **sorted arrays** `arr1[]` and `arr2[]` of size `n` and `m` and a number `x`, find the pair whose **sum is closest to x** and the pair must contain one element from each array.

If there are multiple closest pairs, return any one of them.

> **Note:** In the driver code, the absolute difference between the sum of the closest pair and `x` is printed.

---

## Examples

### Example 1

**Input:**

```
arr1[] = [1, 4, 5, 7]
arr2[] = [10, 20, 30, 40]
x = 32
```

**Output:**

```
[1, 30]
```

**Explanation:**
The closest pair whose sum is closest to 32 is `[1, 30]` → sum = 31.

---

### Example 2

**Input:**

```
arr1[] = [1, 4, 5, 7]
arr2[] = [10, 20, 30, 40]
x = 50
```

**Output:**

```
[7, 40]
```

**Explanation:**
The closest pair whose sum is closest to 50 is `[7, 40]` → sum = 47.

---

## Constraints

* 1 ≤ arr1.size(), arr2.size() ≤ 10^5
* 1 ≤ arr1[i], arr2[i] ≤ 10^9
* 1 ≤ x ≤ 10^9

---

## Expected Time Complexity

* **O(n + m)**

## Expected Auxiliary Space

* **O(1)**

---

## Approach (Two Pointer Technique)

Since both arrays are sorted:

1. Start one pointer at the beginning of `arr1`.
2. Start another pointer at the end of `arr2`.
3. Calculate the current sum.
4. Update the closest pair if needed.
5. If sum > x → move right pointer left.
6. If sum < x → move left pointer right.
7. Continue until one pointer goes out of range.

This ensures linear time complexity.

---

## Function Signature (C++)

```cpp
vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x);
```

---

**End of Problem**
