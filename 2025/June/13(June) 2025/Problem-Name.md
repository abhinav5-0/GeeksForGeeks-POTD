# Koko Eating Bananas

**Difficulty:** Medium
**Accuracy:** 50.27%
**Submissions:** 33K+
**Points:** 4
**Average Time:** 20m

---

## Problem Statement

Koko is given an array `arr[]`, where each element represents a pile of bananas. She has exactly `k` hours to eat all the bananas.

Each hour, Koko can choose **one pile** and eat up to `s` bananas from it.

* If the pile has at least `s` bananas, she eats exactly `s` bananas.
* If the pile has fewer than `s` bananas, she eats the entire pile in that hour.

Koko can only eat from one pile per hour.

Your task is to find the **minimum value of `s` (bananas per hour)** such that Koko can finish all the piles within `k` hours.

---

## Examples

### Example 1:

**Input:**

```text
arr[] = [5, 10, 3], k = 4
```

**Output:**

```text
5
```

**Explanation:**
Koko eats at least 5 bananas per hour to finish all piles within 4 hours:

* 5 (1 hour)
* 10 (2 hours)
* 3 (1 hour)
  Total = 4 hours.

### Example 2:

**Input:**

```text
arr[] = [5, 10, 15, 20], k = 7
```

**Output:**

```text
10
```

**Explanation:**
At 10 bananas per hour, Koko finishes in 6 hours, which is within the limit of 7 hours.

---

## Constraints

* 1 ≤ arr.size() ≤ 10^5
* 1 ≤ arr\[i] ≤ 10^6
* arr.size() ≤ k ≤ 10^6

---

## Function Signature

```cpp
class Solution {
  public:
    int kokoEat(vector<int>& arr, int k);
};
```

---

## Approach

* Use **binary search** to find the minimum `s`.
* For each `s`, calculate total hours required using `ceil(pile / s)` for each pile.
* Narrow down the binary search based on whether the total hours is within `k`.

---

## Time Complexity

* **Binary Search:** O(log(max(arr)))
* **Per check:** O(n), where n is the number of piles
* **Total:** O(n \* log(max(arr)))
