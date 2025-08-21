# Maximize the Minimum Difference Between K Elements

**Difficulty:** Medium
**Accuracy:** 68.9%
**Submissions:** 8K+
**Points:** 4

---

## Problem Statement

Given an array `arr[]` of integers and an integer `k`, select `k` elements from the array such that the **minimum absolute difference** between any two of the selected elements is **maximized**. Return this maximum possible minimum difference.

---

## Examples

**Input:**
`arr[] = [2, 6, 2, 5], k = 3`
**Output:**
`1`
**Explanation:**

* Selecting `{2, 2, 5}` → min difference = 0
* Selecting `{2, 5, 6}` → min difference = 1 ✅ (best choice)

---

**Input:**
`arr[] = [1, 4, 9, 0, 2, 13, 3], k = 4`
**Output:**
`4`
**Explanation:**

* Selecting `{0, 4, 9, 13}` → min difference = 4 ✅

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i] ≤ 10^6`
* `2 ≤ k ≤ arr.size()`

---

## Approach

This is a **binary search on the answer** problem (similar to "Aggressive Cows").

1. **Sort the array** → differences are meaningful in sorted order.
2. **Binary Search** the answer (possible minimum difference).

   * `low = 0`, `high = max(arr) - min(arr)`
3. **Check feasibility:** For a given distance `mid`, check if we can pick `k` elements such that each new element is at least `mid` apart from the last chosen one.

   * If yes → try larger distance.
   * If no → reduce distance.
4. Return the maximum feasible `mid`.

---

## C++ Solution

```cpp
class Solution {
  public:
    bool canPlace(vector<int>& arr, int k, int dist) {
        int count = 1;   // first element always chosen
        int last = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= dist) {
                count++;
                last = arr[i];
                if (count >= k) return true;
            }
        }
        return false;
    }
    
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 0, high = arr.back() - arr.front();
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(arr, k, mid)) {
                ans = mid;     // mid is possible
                low = mid + 1; // try for bigger distance
            } else {
                high = mid - 1; // decrease distance
            }
        }
        return ans;
    }
};
```

---

## Complexity Analysis

* **Sorting:** `O(n log n)`
* **Binary Search:** `O(log(max(arr) - min(arr)))`
* **Feasibility Check:** `O(n)`

**Total:** `O(n log n + n log(maxDiff))`, efficient for `n ≤ 10^5`.

---

✅ This solution ensures we maximize the minimum difference possible between the selected `k` elements.
