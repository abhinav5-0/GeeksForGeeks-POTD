# Missing Element in Range

**Difficulty:** Medium
**Points:** 4

---

## Problem Statement

Given an array `arr[]` of integers and a range `[low, high]`, find all the numbers within the range that are not present in the array. Return the missing numbers in **sorted order**.

---

## Examples

### Example 1

**Input:**

```
arr[] = [10, 12, 11, 15]
low = 10
high = 15
```

**Output:**

```
[13, 14]
```

**Explanation:**
Numbers 13 and 14 lie in the range [10, 15] but are not present in the array.

---

### Example 2

**Input:**

```
arr[] = [1, 4, 11, 51, 15]
low = 50
high = 55
```

**Output:**

```
[50, 52, 53, 54, 55]
```

**Explanation:**
Numbers 50, 52, 53, 54 and 55 lie in the range [50, 55] but are not present in the array.

---

## Constraints

* `1 ≤ arr.size(), low, high ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^5`

---

## Approach

1. Insert all elements of the array into a set for fast lookup.
2. Traverse from `low` to `high`.
3. For each number in this range, check if it is absent in the set.
4. If absent, add it to the result list.
5. Return the result list (already in sorted order due to sequential traversal).

---

## Time and Space Complexity

* **Time Complexity:** O(n + (high - low + 1))
* **Space Complexity:** O(n)
