# 🍫 Chocolate Pickup II

**Difficulty:** Hard  
**Accuracy:** 74.69%  
**Submissions:** 2K+  
**Points:** 8  

---

## 🧩 Problem Statement

You are given a square matrix `mat[][]` of size `n × n`, where each cell represents either a blocked cell or a cell containing some chocolates.  

- If `mat[i][j] == -1`, then the cell is blocked and cannot be visited.  
- Otherwise, `mat[i][j]` represents the number of chocolates present in that cell.

The task is to determine the **maximum number of chocolates** a robot can collect by:

1. Starting from the **top-left cell** `(0, 0)`, moving to the **bottom-right cell** `(n-1, n-1)`, and  
2. Then returning back to `(0, 0)`.

---

### 🧭 Movement Rules

- While **going forward**, the robot can move only **right** `(i, j+1)` or **down** `(i+1, j)`.
- While **coming back**, it can move only **left** `(i, j-1)` or **up** `(i-1, j)`.

After collecting chocolates from a cell `(i, j)`, that cell becomes empty (`mat[i][j] = 0`) for the next visit.  
If there is **no valid path** in either direction, the result should be **0**.

---

### 🧮 Example 1

**Input:**
```cpp
mat = [
  [0, 1, -1],
  [1, 1, -1],
  [1, 1,  2]
]
