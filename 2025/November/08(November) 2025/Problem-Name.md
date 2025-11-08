**Number of Paths in a Matrix with K Coins**
**Difficulty:** Medium
**Accuracy:** 16.96%
**Submissions:** 63K+
**Points:** 4

---

### 🧩 Problem Statement

You are given a matrix `mat[][]` of size `n x m`, where each of its cells contains some coins. Count the number of ways to collect exactly `k` coins while moving from the top-left cell of the matrix to the bottom-right cell.

From a cell `(i, j)`, you can only move to cell `(i+1, j)` or `(i, j+1)`.

It is guaranteed that the answer will not exceed 32-bit integer limits.

---

### 🧠 Example

**Input:**
`k = 12`
`mat = [[1, 2, 3], [4, 6, 5], [3, 2, 1]]`

**Output:**
`2`

**Explanation:**
There are 2 possible paths with exactly 12 coins:

* (1 + 2 + 6 + 2 + 1)
* (1 + 2 + 3 + 5 + 1)

**Input:**
`k = 16`
`mat = [[1, 2, 3], [4, 6, 5], [9, 8, 7]]`

**Output:**
`0`

**Explanation:**
No possible paths lead to a sum of 16 coins.

---

### ⚙️ Constraints

* `1 ≤ k ≤ 100`
* `1 ≤ n, m ≤ 100`
* `0 ≤ mat[i][j] ≤ 200`

---

### 💡 Approach

We use **Dynamic Programming (DP)** to count all valid paths that sum to `k`.

Define a 3D DP array:

```
dp[i][j][s] = number of ways to reach cell (i, j) with sum s
```

**Transition:**

```
dp[i][j][s] = dp[i-1][j][s - mat[i][j]] + dp[i][j-1][s - mat[i][j]]
```

(You can reach `(i, j)` from either the top `(i-1, j)` or left `(i, j-1)` cell.)

**Base Case:**

```
dp[0][0][mat[0][0]] = 1
```

**Answer:**

```
dp[n-1][m-1][k]
```

---

### 🧾 Code Implementation

```cpp
class Solution {
public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        if (mat[0][0] <= k)
            dp[0][0][mat[0][0]] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int s = 0; s <= k; s++) {
                    if (s - mat[i][j] >= 0) {
                        if (i > 0)
                            dp[i][j][s] += dp[i - 1][j][s - mat[i][j]];
                        if (j > 0)
                            dp[i][j][s] += dp[i][j - 1][s - mat[i][j]];
                    }
                }
            }
        }

        return dp[n - 1][m - 1][k];
    }
};
```

---

### ⏱️ Complexity Analysis

* **Time Complexity:** `O(n * m * k)`
* **Space Complexity:** `O(n * m * k)`

Can be optimized to **O(m * k)** using 2D DP arrays (rolling technique).

---

### ✅ Example Walkthrough

For `k = 12` and matrix:

```
1 2 3
4 6 5
3 2 1
```

Paths that sum to 12:

* 1 → 2 → 6 → 2 → 1
* 1 → 2 → 3 → 5 → 1

**Output:** `2`

---
