# Koko Eating Bananas

## Problem Statement

Koko is given an array `arr[]`, where each element represents a pile of bananas. She has exactly `k` hours to eat all the bananas.

Each hour, Koko can choose **one pile** and eat up to **s bananas** from it:

* If the pile has **at least `s` bananas**, she eats exactly `s` bananas.
* If the pile has **fewer than `s` bananas**, she eats the entire pile in that hour.

Koko can eat from **only one pile per hour**.

Your task is to find the **minimum value of `s` (bananas per hour)** such that Koko can finish all the piles within `k` hours.

---

## Examples

### Example 1

**Input:**
`arr = [5, 10, 3], k = 4`

**Output:**
`5`

**Explanation:**
If Koko eats at a rate of 5 bananas per hour:

* Pile 5 → 1 hour
* Pile 10 → 2 hours
* Pile 3 → 1 hour

Total time = `1 + 2 + 1 = 4 hours`

---

### Example 2

**Input:**
`arr = [5, 10, 15, 20], k = 7`

**Output:**
`10`

**Explanation:**
At 10 bananas/hour, Koko finishes all piles in 6 hours.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `1 ≤ arr[i] ≤ 10^6`

---

## Approach

This problem is a classic **Binary Search on Answer** problem.

### Key Observations

* Minimum eating speed = `1`
* Maximum eating speed = `max(arr)`
* As eating speed increases, total hours required **decreases** (monotonic behavior)

### Steps

1. Apply binary search on `s` (bananas/hour)
2. For each `s`, calculate total hours needed:

   `hours += ceil(arr[i] / s)`
3. If total hours ≤ `k`, try smaller `s`
4. Otherwise, increase `s`

---

## Time & Space Complexity

* **Time Complexity:** `O(n log max(arr))`
* **Space Complexity:** `O(1)`

---

## Notes

* Use `ceil(arr[i] / s)` carefully (avoid floating point where possible)
* Works efficiently even for large constraints

---

Happy Coding 🍌
