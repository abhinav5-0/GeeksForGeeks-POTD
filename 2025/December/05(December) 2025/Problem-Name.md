# Walls Coloring II — Solution (Hard)

## Problem Summary

You are given `n` walls and `k` colors. Each wall `i` has a painting cost for each color `j`: `costs[i][j]`. You must paint all walls such that:

* No two adjacent walls have the same color.
* Total painting cost is minimum.
* If impossible, return `-1`.

### Constraints

* `0 ≤ n ≤ 1000`
* `0 ≤ k ≤ 1000`
* `1 ≤ costs[i][j] ≤ 100000`

---

## Key Idea

A direct DP of `O(n * k * k)` is too slow (10^9 operations). We need to optimize.

For each wall `i`, instead of checking all other `k-1` colors to find the best previous option, we keep track of:

* **min1** → smallest cost up to previous wall
* **min2** → second smallest cost up to previous wall
* **idx1** → color index achieving min1

When painting wall `i` with color `j`:

* If `j != idx1`: `dp[i][j] = costs[i][j] + min1`
* Else: `dp[i][j] = costs[i][j] + min2` (because adjacent colors can't match)

This reduces time to `O(n * k)`.

---

## Edge Cases

* If `n == 0`: return 0
* If `k == 0`: return -1
* If `n >= 2` and `k == 1`: impossible → return -1

---

## C++ Code

```cpp
class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return -1;
        if (k == 1 && n > 1) return -1;

        vector<int> prev(k), curr(k);

        // initialize
        for (int j = 0; j < k; j++) prev[j] = costs[0][j];

        for (int i = 1; i < n; i++) {
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;

            // find min1, min2
            for (int j = 0; j < k; j++) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    idx1 = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }

            // compute current row
            for (int j = 0; j < k; j++) {
                if (j == idx1) curr[j] = costs[i][j] + min2;
                else curr[j] = costs[i][j] + min1;
            }

            prev = curr;
        }

        int ans = INT_MAX;
        for (int j = 0; j < k; j++) ans = min(ans, prev[j]);
        return ans;
    }
};
```

---

## Example Walkthrough

### Input

```
4 3
[[1,5,7],[5,8,4],[3,2,9],[1,2,4]]
```

Result = **8**

---

## Time Complexity

* **O(n * k)**

## Space Complexity

* **O(k)**

---

## Final Notes

This is the optimal solution used for the classic *Paint House II* problem.
