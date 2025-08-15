# Insert Interval

**Difficulty:** Medium
**Accuracy:** 50.61%
**Average Time:** 30m

---

## Problem Statement

You are given a sorted array of non-overlapping intervals `intervals[][]` where `intervals[i] = [start_i, end_i]` represents the start and end of the i-th event. You are also given a `newInterval[] = [newStart, newEnd]`.

Your task is to insert `newInterval` into `intervals` such that:

* The array remains sorted by `start_i`.
* There are no overlapping intervals (merge if necessary).

---

### Example 1:

**Input:**

```
intervals = [[1, 3], [4, 5], [6, 7], [8, 10]]
newInterval = [5, 6]
```

**Output:**

```
[[1, 3], [4, 7], [8, 10]]
```

**Explanation:**
The new interval \[5, 6] overlaps with \[4, 5] and \[6, 7]. They merge into \[4, 7].

---

### Example 2:

**Input:**

```
intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
newInterval = [4, 9]
```

**Output:**

```
[[1, 2], [3, 10], [12, 16]]
```

**Explanation:**
The new interval overlaps with \[3, 5], \[6, 7], and \[8, 10], merging into \[3, 10].

---

## Constraints:

* 1 ≤ intervals.size() ≤ 10^5
* 0 ≤ start\_i ≤ end\_i ≤ 10^9
* 0 ≤ newStart ≤ newEnd ≤ 10^9

---

## Approach

Since the intervals are already sorted by their start times, we can solve this in **O(n)**:

1. **Add all intervals before the new interval** (no overlap).
2. **Merge overlapping intervals** into the new interval.
3. **Add all intervals after the new interval** (no overlap).

---

### Algorithm Steps

1. Initialize an empty result vector `res`.
2. Iterate over intervals:

   * If `interval[i].end < newStart` → push directly to `res`.
   * If `interval[i].start > newEnd` → push `newInterval` to `res` and then push remaining intervals.
   * If overlap → merge into `newInterval` by adjusting start and end.
3. If `newInterval` has not been inserted, append it at the end.

---

### Code Implementation

```cpp
class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        // Step 1: Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Step 3: Add remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
```

---

### Complexity Analysis

* **Time Complexity:** O(n) — single pass through intervals.
* **Space Complexity:** O(n) — result storage.

---

**Key Insight:**
We leverage the sorted property of intervals to avoid re-sorting and merge on-the-fly.
