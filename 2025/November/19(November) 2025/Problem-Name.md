# Path With Minimum Effort

## Problem Statement

You are given a 2D array `mat[][]` of size `n * m`. Your task is to find the **minimum possible path cost** from the top-left cell `(0, 0)` to the bottom-right cell `(n-1, m-1)`.

You may move **up, down, left, or right** to adjacent cells.

### Path Cost Definition

The cost of a path is defined as:

> The **maximum absolute difference** between the values of any two consecutive cells along the path.

Your goal is to **minimize this maximum difference**.

---

## Examples

### Example 1

**Input:**

```
mat = [
  [7, 2, 6, 5],
  [3, 1, 10, 8]
]
```

**Output:** `4`

**Explanation:** A valid route is:

```
7 → 3 → 1 → 2 → 6 → 5 → 8
```

The maximum absolute difference between any two consecutive cells is `4`.

---

### Example 2

**Input:**

```
mat = [
  [2, 2, 2, 1],
  [8, 1, 2, 7],
  [2, 2, 2, 8],
  [2, 1, 4, 7],
  [2, 2, 2, 2]
]
```

**Output:** `0`

**Explanation:** A path exists containing only cells with value `2`, giving a maximum difference of `0`.

---

## Constraints

* `1 ≤ n, m ≤ 100`
* `0 ≤ mat[i][j] ≤ 10^6`

---

# Solution Approach

We use **Binary Search on the effort** combined with **BFS**.

### Why Binary Search?

The answer (minimum possible maximum difference) lies within:

```
0 to 1,000,000
```

For a given value `mid`, we check whether it's possible to reach the target under the constraint:

```
|mat[nx][ny] - mat[x][y]| ≤ mid
```

This can be checked using BFS.

If a path exists, we try a smaller `mid`.
If not, we try larger.

This yields an efficient solution:

```
Time: O(log(1e6) * n * m)
```

---

# C++ Code Implementation

```cpp
class Solution {
public:
    int n, m;
    
    bool canReach(vector<vector<int>>& mat, int limit) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if(x == n-1 && y == m-1) return true;
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    if(abs(mat[nx][ny] - mat[x][y]) <= limit) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return false;
    }
    
    int minCostPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        
        int low = 0, high = 1e6, ans = 0;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(canReach(mat, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
```

---

# Summary

* Binary search on the minimum effort.
* BFS validates whether the path is possible under a given threshold.
* Efficient and clean solution.

If you want, I can also add:

* Dijkstra-based version
* Visual explanation
* Dry run with diagrams
