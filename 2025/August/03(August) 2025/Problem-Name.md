### 2D Difference Array Problem

**Problem Statement:**
You are given a 2D matrix `mat` of size `n x m` and `q` operations `opr[][]`. Each operation is of the form `[v, r1, c1, r2, c2]` which means you have to add value `v` to all elements of the submatrix from `(r1, c1)` to `(r2, c2)` (inclusive).

**Constraints:**
- 1 ≤ n × m, q ≤ 10^5
- 0 ≤ r1 ≤ r2 ≤ n - 1
- 0 ≤ c1 ≤ c2 ≤ m - 1
- -10^4 ≤ mat[i][j], v ≤ 10^4

**Approach:**
We use a 2D difference array to efficiently handle range updates:

1. Create a `diff` matrix initialized with 0s of size `(n+1) x (m+1)`.
2. For each operation `[v, r1, c1, r2, c2]`, update:
   ```
   diff[r1][c1]     += v
   diff[r1][c2+1]   -= v
   diff[r2+1][c1]   -= v
   diff[r2+1][c2+1] += v
   ```
3. Compute prefix sums row-wise and then column-wise.
4. Add the final `diff` matrix to the original `mat`.

---

**C++ Code:**
```cpp
class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));

        // Step 1: Apply all operations on the diff matrix
        for (auto& op : opr) {
            int v = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            diff[r1][c1] += v;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= v;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= v;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
        }

        // Step 2: Prefix sum row-wise
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j)
                diff[i][j] += diff[i][j - 1];

        // Step 3: Prefix sum column-wise
        for (int j = 0; j < m; ++j)
            for (int i = 1; i < n; ++i)
                diff[i][j] += diff[i - 1][j];

        // Step 4: Add diff to original matrix
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                mat[i][j] += diff[i][j];

        return mat;
    }
};
```

---

**Example:**
Input:
```cpp
mat = {{1, 2, 3},
       {1, 1, 0},
       {4,-2, 2}};
opr = {{2, 0, 0, 1, 1}, {-1, 1, 0, 2, 2}};
```
Output:
```cpp
[[3, 4, 3],
 [2, 2, -1],
 [3, -3, 1]]
```

**Time Complexity:** O(n * m + q)
**Space Complexity:** O(n * m)
