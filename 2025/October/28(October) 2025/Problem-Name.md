## Distance of Nearest Cell Having 1

**Difficulty:** Medium
**Accuracy:** 47.7%
**Points:** 4
**Average Time:** 20m

---

### 🧩 Problem Statement

Given a binary `grid[][]`, where each cell contains either `0` or `1`, find the distance of the nearest `1` for every cell in the grid.

The distance between two cells `(i1, j1)` and `(i2, j2)` is calculated as:
(|i1 - i2| + |j1 - j2|)

You need to return a matrix of the same size, where each cell `(i, j)` contains the minimum distance from `grid[i][j]` to the nearest cell having value `1`.

It is guaranteed that there is at least one cell with value `1` in the grid.

---

### 🧠 Approach

We can solve this efficiently using **multi-source BFS**:

1. Push all cells containing `1` into a queue (as sources).
2. Set their distances to `0` in the `dist` matrix.
3. For every cell popped from the queue, explore its 4 neighbors (up, down, left, right).
4. If a neighbor hasn't been visited, set its distance as `dist[current] + 1` and push it into the queue.
5. Continue until the queue is empty.

This ensures that the shortest distance is calculated in **O(N × M)** time.

---

### ⏱️ Complexity

* **Time Complexity:** O(N × M)
* **Space Complexity:** O(N × M)

---

### 💻 C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Push all cells having 1 into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Step 2: Define directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Step 3: Multi-source BFS
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return dist;
    }
};
```

---

### 🧮 Example

**Input:**

```cpp
grid = {{0, 1, 1, 0}, 
        {1, 1, 0, 0}, 
        {0, 0, 1, 1}};
```

**Output:**

```cpp
{{1, 0, 0, 1}, 
 {0, 0, 1, 1}, 
 {1, 1, 0, 0}};
```

**Explanation:**

* Cells with `0` at (0,0), (0,3), (1,2), etc., have the nearest `1` at a distance of 1.

---

### 🧾 Notes

* The approach works for any grid up to `200 × 200`.
* Using multi-source BFS ensures optimal performance compared to brute-force methods.

