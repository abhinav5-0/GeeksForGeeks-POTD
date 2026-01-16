## Minimum Number of Workers

### Problem Statement

You are given an array `arr[]` of size `n`, where each index represents a person and `arr[i]` represents the range of working hours that person can cover.

* If `arr[i] != -1`, then the person at index `i` can cover the interval:

  [ i - arr[i],; i + arr[i] ]

* If `arr[i] == -1`, then the person is unavailable and cannot cover any hour.

Your task is to find the **minimum number of people** required to cover the **entire working day from hour `0` to `n-1`**.

If it is **not possible** to cover all hours, return `-1`.

---

### Key Observations

* Each valid person provides an **interval of coverage**.
* The interval must be **clipped** within valid bounds `[0, n-1]`.
* The goal is to **cover the full range `[0, n-1]` using the minimum number of intervals**.
* This is a classic **minimum interval covering** (greedy) problem.

---

### Approach (Greedy Interval Covering)

1. Convert each valid `arr[i]` into a coverage interval:

   * `start = max(0, i - arr[i])`
   * `end   = min(n - 1, i + arr[i])`

2. Ignore all persons with `arr[i] = -1`.

3. Sort all intervals by:

   * Increasing `start`
   * If tie, decreasing `end`

4. Use a greedy strategy:

   * Start covering from hour `0`
   * At each step, select the interval that starts **at or before the current hour** and extends **farthest to the right**
   * Move the coverage forward

5. If at any point you cannot extend the coverage, return `-1`.

---

### Example Walkthrough

#### Input

```
arr = [1, 2, 1, 0]
```

* Person at index `1` covers `[-1, 3] → [0, 3]`
* This single person covers all hours `0 to 3`

**Answer:** `1`

---

### Time & Space Complexity

* **Time Complexity:** `O(n log n)` (due to sorting intervals)
* **Space Complexity:** `O(n)` (to store intervals)

---

### C++ Implementation

```cpp
class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Create intervals
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int start = max(0, i - arr[i]);
                int end = min(n - 1, i + arr[i]);
                intervals.push_back({start, end});
            }
        }

        // Step 2: Sort intervals
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int i = 0;
        int coveredTill = 0;

        // Step 3: Greedy covering
        while(coveredTill < n) {
            int farthest = coveredTill;
            while(i < intervals.size() && intervals[i].first <= coveredTill) {
                farthest = max(farthest, intervals[i].second + 1);
                i++;
            }

            if(farthest == coveredTill)
                return -1;  // cannot extend coverage

            count++;
            coveredTill = farthest;
        }

        return count;
    }
};
```

---

### Final Notes

* This problem is equivalent to **minimum number of intervals to cover a range**.
* Greedy works because choosing the interval with the **maximum reach** always gives the optimal solution.
* Be careful with edge cases where coverage is broken.

---

✅ **Now you can directly submit this solution on GFG!**
