# The Painter's Partition Problem - II

**Difficulty:** Hard
**Accuracy:** 27.52%
**Submissions:** 166K+
**Points:** 8

---

## 📝 Problem Statement

Given an array `arr[]` where each element represents the length of a board, and an integer `k` representing the number of painters available.

* Each painter takes **1 unit of time** to paint **1 unit length** of a board.
* Each painter can paint only a **contiguous sequence of boards**.
* A board cannot be split between painters.

Your task is to determine the **minimum amount of time** required to paint all the boards.

---

## 📌 Examples

### Example 1

```
Input:  arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
```

**Explanation:**
Optimal allocation:

* Painter 1 → [5, 10] → 15
* Painter 2 → [30] → 30
* Painter 3 → [20, 15] → 35

Total time = max(15, 30, 35) = **35**

---

### Example 2

```
Input:  arr[] = [10, 20, 30, 40], k = 2
Output: 60
```

**Explanation:**
Valid optimal partition:

* Painter 1 → [10, 20, 30] → 60
* Painter 2 → [40] → 40

Total time = max(60, 40) = **60**

---

### Example 3

```
Input:  arr[] = [100, 200, 300, 400], k = 1
Output: 1000
```

**Explanation:**
Only one painter paints all boards.

Total time = 100 + 200 + 300 + 400 = **1000**

---

## 🔒 Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^4`
* `1 ≤ k ≤ 10^5`

---

## 💡 Key Observation

* The answer lies between:

  * **Maximum board length** (minimum possible time)
  * **Sum of all board lengths** (maximum possible time)

This problem can be efficiently solved using:

> ✅ **Binary Search on Answer** + **Greedy Feasibility Check**

---

## 🚀 Expected Approach

1. Set:

   * `low = max(arr[])`
   * `high = sum(arr[])`
2. Perform Binary Search on this range.
3. For each mid value, check if it is possible to paint all boards using ≤ `k` painters.
4. Return the minimum valid time.

---

✍️ Recommended Time Complexity: **O(n log(sum))**
📦 Space Complexity: **O(1)**
