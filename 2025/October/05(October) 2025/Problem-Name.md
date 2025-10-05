# 🐀 Rat in a Maze

### 🧩 Problem Description
Consider a rat placed at position `(0, 0)` in an `n x n` square matrix `maze[][]`. The rat's goal is to reach the destination at position `(n-1, n-1)`. The rat can move in four possible directions:
- **U** (Up)
- **D** (Down)
- **L** (Left)
- **R** (Right)

The matrix contains:
- `0`: A blocked cell.
- `1`: A free cell.

Find all possible paths for the rat to reach the destination. The rat cannot revisit a cell in the same path and can only move to adjacent, valid, and unblocked cells. If no path exists, return an empty list. The result should be in **lexicographically sorted order**.

---

### 📘 Examples

#### Example 1
**Input:**  
```
maze = [
 [1, 0, 0, 0],
 [1, 1, 0, 1],
 [1, 1, 0, 0],
 [0, 1, 1, 1]
]
```
**Output:**  
```
["DDRDRR", "DRDDRR"]
```

**Explanation:**  
Two paths lead to destination `(3,3)` — `DDRDRR` and `DRDDRR`.

---

#### Example 2
**Input:**  
```
maze = [
 [1, 0],
 [1, 0]
]
```
**Output:**  
```
[]
```

**Explanation:**  
Destination `(1,1)` is blocked.

---

#### Example 3
**Input:**  
```
maze = [
 [1, 1, 1],
 [1, 0, 1],
 [1, 1, 1]
]
```
**Output:**  
```
["DDRR", "RRDD"]
```

---

### ⚙️ Constraints
- `2 ≤ n ≤ 5`
- `maze[i][j]` is either `0` or `1`

---

### 💡 Approach
1. Use **Backtracking** to explore all possible moves from `(0,0)`.
2. Move only to unvisited and unblocked cells.
3. If destination `(n-1,n-1)` is reached, store the path.
4. Use direction order **D, L, R, U** to generate lexicographically sorted paths.
5. Backtrack after exploring each path.

---

### 🧠 C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string path, vector<vector<int>> &vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        int di[] = {1, 0, 0, -1}; // Down, Left, Right, Up
        int dj[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};

        for (int k = 0; k < 4; k++) {
            int nexti = i + di[k];
            int nextj = j + dj[k];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && 
                !vis[nexti][nextj] && maze[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, maze, n, ans, path + dir[k], vis);
                vis[i][j] = 0; // Backtrack
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        solve(0, 0, maze, n, ans, "", vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> res = obj.ratInMaze(maze);
    for (auto &path : res) cout << path << " ";
    return 0;
}
```

---

### 🧩 Dry Run Example
For maze:
```
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
```
- Start at (0,0): only down possible → `D`
- Continue exploring recursively until `(3,3)`.
- Backtrack after each completed path.
- Output: `DDRDRR`, `DRDDRR`

---

### ⏱️ Time & Space Complexity
- **Time Complexity:** O(4^(n²)) — each cell has 4 choices.
- **Space Complexity:** O(n²) — recursion stack + visited matrix.

---

### 🏁 Final Output
```
["DDRDRR", "DRDDRR"]
