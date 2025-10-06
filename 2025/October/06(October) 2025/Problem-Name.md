# The Knight's Tour Problem

**Difficulty:** Medium  
**Accuracy:** 60.38%  
**Submissions:** 8K+  
**Points:** 4

---

## 🧩 Problem Statement

You are given an integer `n`, representing an `n × n` chessboard with a Knight starting at the top-left corner `(0, 0)`.  
Your task is to determine a valid **Knight's Tour**, where the Knight visits every square exactly once following the standard rules of chess.

If a solution exists, return the **order** in which each cell is visited (0-indexed).  
If no solution exists, return an empty list `[]`.

### Knight's Move
If the knight is at `(x, y)`, it can move to one of the following cells:
```
(x+2, y+1), (x+2, y-1), (x-2, y+1), (x-2, y-1),
(x+1, y+2), (x+1, y-2), (x-1, y+2), (x-1, y-2)
```

---

## 🧠 Example

### Input:
```cpp
n = 5
```

### Output:
```cpp
true
```
A possible Knight's Tour is:
```
[[0, 11, 2, 17, 20],
 [3, 16, 19, 12, 7],
 [10, 1, 6, 21, 18],
 [15, 4, 23, 8, 13],
 [24, 9, 14, 5, 22]]
```

### Input:
```cpp
n = 4
```

### Output:
```cpp
[]
```

---

## ⚙️ Constraints
```
1 ≤ n ≤ 6
```

---

## 💡 Approach

1. Use **Backtracking** to try all possible knight moves from each position.
2. Mark the cell as visited with the current step number.
3. If all `n * n` cells are filled, we found a valid tour.
4. If a move leads to a dead-end, backtrack and try the next move.

---

## 🧾 Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool isSafe(int x, int y, int n, vector<vector<int>>& board) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }
    
    bool solve(int x, int y, int movei, int n, vector<vector<int>>& board) {
        if (movei == n * n) return true; // all cells visited
        
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isSafe(nx, ny, n, board)) {
                board[nx][ny] = movei;
                if (solve(nx, ny, movei + 1, n, board))
                    return true;
                else
                    board[nx][ny] = -1; // backtrack
            }
        }
        return false;
    }

    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0; // starting point

        if (!solve(0, 0, 1, n, board)) {
            return {}; // no solution exists
        }
        return board;
    }
};
```

---

## 🧮 Complexity Analysis
- **Time Complexity:** `O(8^(n^2))` (Exponential — Backtracking)
- **Space Complexity:** `O(n^2)` (for board storage)

---

## ✅ Summary
| Aspect | Description |
|--------|--------------|
| **Algorithm** | Backtracking |
| **Start Point** | (0, 0) |
| **Goal** | Visit all cells exactly once |
| **Output** | Order of moves / Empty list if impossible |

---
