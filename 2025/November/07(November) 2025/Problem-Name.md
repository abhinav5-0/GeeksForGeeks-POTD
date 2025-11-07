## Weighted Job Scheduling

**Difficulty:** Medium
**Accuracy:** 67.38%
**Points:** 4

### Problem Statement

Given a 2D array `jobs[][]` of size `n × 3`, where each row represents a single job with the following details:

* `jobs[i][0]`: Start time of the job
* `jobs[i][1]`: End time of the job
* `jobs[i][2]`: Profit earned by completing the job

Find the **maximum profit** you can earn by scheduling non-overlapping jobs.

Two jobs are said to be non-overlapping if the end time of one job is **less than or equal to** the start time of the next job. If a job ends at time X, another job can start exactly at time X.

---

### Example 1

**Input:**

```cpp
jobs = [[1, 2, 50], [3, 5, 20], [6, 19, 100], [2, 100, 200]]
```

**Output:**

```
250
```

**Explanation:**
The first and fourth jobs with time range [1, 2] and [2, 100] can be chosen to give a maximum profit of **50 + 200 = 250**.

---

### Example 2

**Input:**

```cpp
jobs = [[1, 3, 60], [2, 5, 50], [4, 6, 70], [5, 7, 30]]
```

**Output:**

```
130
```

**Explanation:**
The first and third jobs with time range [1, 3] and [4, 6] can be chosen to give a maximum profit of **60 + 70 = 130**.

---

### Constraints

* `1 ≤ jobs.size() ≤ 10^5`
* `1 ≤ jobs[i][0] < jobs[i][1] ≤ 10^9`
* `1 ≤ jobs[i][2] ≤ 10^4`

---

### Approach

This is a **Dynamic Programming + Binary Search** problem.

1. **Sort** all jobs by their **end time**.
2. For each job `i`, we can either:

   * **Include** the job: profit = `jobs[i][2] + profit of last non-overlapping job`
   * **Exclude** the job: profit = `dp[i-1]`
3. Use **binary search** to find the index of the **last non-overlapping job** (whose end time ≤ start time of current job).
4. Store the best profit up to each job in a **DP array**.
5. The last value in `dp` is the maximum profit.

---

### Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // Sort jobs by their end time
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int n = jobs.size();
        vector<int> dp(n);
        vector<int> endTimes;
        
        for (auto &job : jobs) endTimes.push_back(job[1]);
        
        dp[0] = jobs[0][2];
        
        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i][2];
            
            // Find last non-overlapping job using binary search
            int idx = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][0]) - endTimes.begin() - 1;
            
            if (idx >= 0)
                includeProfit += dp[idx];
            
            dp[i] = max(dp[i-1], includeProfit);
        }
        
        return dp[n-1];
    }
};
```

---

### Dry Run

**Input:** `[[1,2,50], [3,5,20], [6,19,100], [2,100,200]]`

After sorting by end time:

```
[1,2,50], [3,5,20], [6,19,100], [2,100,200]
```

| i | Job (Start, End, Profit) | Last Non-Overlap | Include Profit | dp[i] |
| - | ------------------------ | ---------------- | -------------- | ----- |
| 0 | [1,2,50]                 | -                | 50             | 50    |
| 1 | [3,5,20]                 | 0                | 70             | 70    |
| 2 | [6,19,100]               | 1                | 170            | 170   |
| 3 | [2,100,200]              | 0                | 250            | 250   |

✅ **Maximum Profit = 250**

---

### Complexity Analysis

* **Time Complexity:** O(n log n)

  * Sorting: O(n log n)
  * Binary search for each job: O(n log n)
* **Space Complexity:** O(n)

---

### Key Idea

> The problem is an extension of the Activity Selection problem but uses **Dynamic Programming** to maximize profit instead of simply maximizing the number of activities.
