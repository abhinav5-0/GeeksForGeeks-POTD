# Unique Paths in a Grid

## Problem Statement

You are given a 2D list `grid[][]` of size `n x m` consisting of values 0 and 1.

* A value of **0** means that you can enter that cell.
* A value of **1** implies that entry to that cell is **not allowed**.

You start at the upper-left corner of the grid `(1, 1)` and must reach the bottom-right corner `(n, m)` by **only moving right or down** from each cell.

Your task is to calculate the total number of **unique paths** to reach the target.

### Note:

* The first `(1, 1)` and last `(n, m)` cell of the grid **can also be 1** (blocked).
* It is guaranteed that the total number of ways will fit within a **32-bit integer**.

---

## Examples

### Example 1:

**Input:**

```
n = 3, m = 3
grid = [[0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]]
```

**Output:** `2`

**Explanation:**
There are two valid paths:

1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

---

### Example 2:

**Input:**

```
n = 1, m = 3
grid = [[1, 0, 1]]
```

**Output:** `0`

**Explanation:**
Start is blocked. No path exists.

---

## Constraints

* `1 ≤ n * m ≤ 10^6`

---

## Solution (C++)

```cpp
class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();

        // If start or end cell is blocked
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0; // blocked cell
                } else {
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
```

---

## Time and Space Complexity

* **Time Complexity:** `O(n * m)`
* **Space Complexity:** `O(n * m)` (can be optimized to `O(m)`)

---

## Tags

`Dynamic Programming` `2D Grid` `Blocked Cells` `Unique Paths`
