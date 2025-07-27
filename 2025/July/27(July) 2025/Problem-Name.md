## Set Matrix Zeroes

**Difficulty:** Medium  
**Accuracy:** 52.54%  
**Submissions:** 47K+  
**Points:** 4

---

### Problem Statement:
You are given a 2D matrix `mat[][]` of size `n x m`. The task is to modify the matrix such that if `mat[i][j]` is `0`, all the elements in the `i-th` row and `j-th` column are set to `0`.

---

### Examples:

#### Input:
```
mat = [
  [1, 2, 0],
  [4, 5, 6],
  [7, 8, 9]
]
```

#### Output:
```
[
  [0, 0, 0],
  [4, 5, 0],
  [7, 8, 0]
]
```

#### Explanation:
- `mat[0][2]` is `0`, so all elements in row `0` and column `2` are updated to zeroes.

---

### Constraints:
- `1 ≤ n, m ≤ 500`
- `-2^31 ≤ mat[i][j] ≤ 2^31 - 1`

---

### C++ Solution (Optimized O(1) Space):

```cpp
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool firstRow = false, firstCol = false;

        // Step 1: Mark rows and columns to be zeroed
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 0) firstCol = true;
        }

        for (int j = 0; j < m; ++j) {
            if (mat[0][j] == 0) firstRow = true;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // Step 2: Set matrix cells to 0 using marks
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // Step 3: Update first row if needed
        if (firstRow) {
            for (int j = 0; j < m; ++j) {
                mat[0][j] = 0;
            }
        }

        // Step 4: Update first column if needed
        if (firstCol) {
            for (int i = 0; i < n; ++i) {
                mat[i][0] = 0;
            }
        }
    }
};
```

---

### Time & Space Complexity:
- **Time Complexity:** `O(n * m)`
- **Space Complexity:** `O(1)` (in-place using matrix's first row and column as markers)

---

Let me know if you want Python or Java versions too!
