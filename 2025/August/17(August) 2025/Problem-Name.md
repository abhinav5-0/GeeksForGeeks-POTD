# Sort by Absolute Difference

**Difficulty:** Medium
**Accuracy:** 27.77%
**Submissions:** 51K+
**Points:** 4
**Average Time:** 5m

---

## Problem Statement

You are given a number `x` and an array `arr[]`. Your task is to rearrange the elements of the array according to the absolute difference with `x`, i.e., an element having minimum difference comes first, and so on.

**Note:** If two or more elements are at equal distances, arrange them in the same sequence as in the given array.

---

## Examples

### Example 1

**Input:**
`x = 7, arr[] = [10, 5, 3, 9, 2]`

**Output:**
`[5, 9, 10, 3, 2]`

**Explanation:**
Sorting the numbers according to the absolute difference with 7, we have array elements as 5, 9, 10, 3, 2.

---

### Example 2

**Input:**
`x = 6, arr[] = [1, 2, 3, 4, 5]`

**Output:**
`[5, 4, 3, 2, 1]`

**Explanation:**
Sorting the numbers according to the absolute difference with 6, we have array elements as 5, 4, 3, 2, 1.

---

## Constraints

* 1 ≤ x ≤ 10^5
* 1 ≤ arr.size() ≤ 10^5
* 1 ≤ arr\[i] ≤ 10^5

---

## Approach

1. Compute the absolute difference of each element in the array with `x`.
2. Sort the array according to the difference.
3. Use **stable sorting** to maintain the original order of elements when two or more have the same difference.

---

## C++ Implementation

```cpp
class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // Using stable_sort to preserve order in case of equal differences
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};
```

---

## Key Idea

* **Absolute Difference**: Distance between two numbers, always positive.
* **Stable Sort**: Keeps the original order of elements with equal difference.
* This ensures the problem condition is satisfied correctly.
