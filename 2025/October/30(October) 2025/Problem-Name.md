## Replace O's with X's

**Difficulty:** Medium
**Accuracy:** 34.0%
**Points:** 4
**Average Time:** 20m

---

### 🧩 Problem Statement

You are given a grid[][] of size n*m, where every element is either `'O'` or `'X'`. You have to replace all `'O'` or a group of `'O'` with `'X'` that are surrounded by `'X'`.

A `'O'` (or a set of `'O'`) is considered to be surrounded by `'X'` if there are `'X'` at locations just below, just above, just left and just right of it.

---

### 🔍 Examples

**Input:**

```cpp
grid[][] = {{'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
            {'X', 'X', 'O', 'O'}}
```

**Output:**

```cpp
{{'X', 'X', 'X', 'X'},
 {'X', 'X', 'X', 'X'},
 {'X', 'X', 'X', 'X'},
 {'X', 'X', 'X', 'X'},
 {'X', 'X', 'O', 'O'}}
```

**Explanation:** Only the 'O's that are fully surrounded by 'X' are replaced.

---

**Input:**

```cpp
grid[][] = {{'X', 'O', 'X', 'X'},
            {'X', 'O', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
            {'X', 'X', 'O', 'O'}}
```

**Output:**

```cpp
{{'X', 'O', 'X', 'X'},
 {'X', 'O', 'X', 'X'},
 {'X', 'O', 'O', 'X'},
 {'X', 'O', 'X', 'X'},
 {'X', 'X', 'O', 'O'}}
```

**Explanation:** There is no 'O' that is completely surrounded by 'X'.

---

### ⚙️ Constraints

* 1 ≤ grid.size() ≤ 100
* 1 ≤ grid[0].size() ≤ 100

---

### 💡 Approach

1. Any `'O'` **connected to the boundary** should **not be replaced**.
2. Traverse the **boundary cells** and mark all connected `'O'`s (temporarily as `'#'`).
3. After marking, replace all remaining `'O'`s with `'X'` (these are surrounded ones).
4. Finally, revert all `'#'` back to `'O'` (safe ones).

---

### 🧠 Algorithm

1. Iterate over the boundary rows and columns.
2. For each `'O'` on the boundary, perform DFS/BFS to mark connected `'O'`s as `'#'`.
3. Traverse the grid:

   * Replace `'O'` → `'X'`.
   * Replace `'#'` → `'O'`.

---

### ✅ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O')
            return;
        grid[i][j] = '#'; // mark safe
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }

    void fill(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Step 1: Mark boundary-connected 'O's
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') dfs(i, 0, grid);
            if (grid[i][m-1] == 'O') dfs(i, m-1, grid);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') dfs(0, j, grid);
            if (grid[n-1][j] == 'O') dfs(n-1, j, grid);
        }

        // Step 2: Replace surrounded 'O's with 'X' and restore safe ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
    }
};
```

---

### 🧾 Summary

* **Concept Used:** DFS / Flood Fill
* **Time Complexity:** O(N*M)
* **Space Complexity:** O(N*M) (for recursion stack or BFS queue)

Efficient, clean, and widely used approach for surrounded region problems!
