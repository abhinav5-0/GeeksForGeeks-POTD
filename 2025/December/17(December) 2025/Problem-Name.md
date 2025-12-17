# Overlapping Intervals (Merge Intervals)

**Difficulty:** Medium
**Accuracy:** 57.41%
**Average Time:** 20 minutes

---

## 🧩 Problem Statement

Given an array of intervals `arr[][]`, where each interval is represented as `[start, end]`, your task is to **merge all overlapping intervals** and return the resulting list of non-overlapping intervals.

Two intervals `[a, b]` and `[c, d]` overlap if:

```
c <= b
```

---

## 📥 Examples

### Example 1

**Input:**

```
[[1, 3], [2, 4], [6, 8], [9, 10]]
```

**Output:**

```
[[1, 4], [6, 8], [9, 10]]
```

**Explanation:**
Intervals `[1, 3]` and `[2, 4]` overlap and merge into `[1, 4]`.

---

### Example 2

**Input:**

```
[[6, 8], [1, 9], [2, 4], [4, 7]]
```

**Output:**

```
[[1, 9]]
```

**Explanation:**
All intervals overlap with `[1, 9]`, so the final merged interval is `[1, 9]`.

---

## ⚙️ Approach (Greedy + Sorting)

1. **Sort** the intervals by their starting values.
2. Initialize a result list and add the first interval.
3. Traverse the remaining intervals:

   * If the current interval overlaps with the last interval in the result, merge them.
   * Otherwise, add the current interval to the result.
4. Return the merged intervals.

---

## ⏱ Complexity Analysis

* **Time Complexity:** `O(n log n)` (due to sorting)
* **Space Complexity:** `O(1)` extra space (excluding output)

---

## 💻 C++ Implementation

```cpp
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        if (arr.empty()) return {};
        
        // Step 1: Sort intervals by start time
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> result;
        result.push_back(arr[0]);
        
        // Step 2: Merge overlapping intervals
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] <= result.back()[1]) {
                // Overlapping case
                result.back()[1] = max(result.back()[1], arr[i][1]);
            } else {
                // Non-overlapping case
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};
```

---

## ✅ Key Takeaways

* Sorting is essential before merging intervals.
* A single linear pass after sorting is sufficient.
* This is a **standard interview and competitive programming problem**.

---

✨ *Happy Coding!*
