# Number of Islands

## Difficulty
**Medium**

---

## Problem Statement

Given a grid of size `n x m` (where `n` is the number of rows and `m` is the number of columns), consisting of:

- `'L'` representing **Land**
- `'W'` representing **Water**

Your task is to **find the number of islands** in the grid.

---

## Definition of an Island

An island is a group of `'L'` (land) cells connected **horizontally, vertically, or diagonally** (i.e., in all 8 directions). Islands are either surrounded by water (`'W'`) or the boundary of the grid.

---

## Input

- A 2D grid `grid[][]` of characters, where each element is either `'L'` or `'W'`.
- Grid dimensions: `n` rows and `m` columns.

### Constraints

- `1 ≤ n, m ≤ 500`
- `grid[i][j]` ∈ `{ 'L', 'W' }`

---

## Output

- Return a single integer: the number of islands present in the grid.

---

## Examples

### Example 1
**Input:**
```
grid = [
    ['L', 'L', 'W', 'W', 'W'],
    ['W', 'L', 'W', 'W', 'L'],
    ['L', 'W', 'W', 'L', 'L'],
    ['W', 'W', 'W', 'W', 'W'],
    ['L', 'W', 'L', 'L', 'W']
]
```

**Output:**
```
4
```

**Explanation:**  
There are 4 distinct islands in the grid.

---

### Example 2
**Input:**
```
grid = [
    ['W', 'L', 'L', 'L', 'W', 'W', 'W'],
    ['W', 'W', 'L', 'L', 'W', 'L', 'W']
]
```

**Output:**
```
2
```

---

## Approach

- Traverse the entire grid.
- Every time you find an unvisited `'L'` cell, initiate a **DFS** or **BFS** to mark all connected `'L'` cells.
- Increment the island count on each new traversal.

---

## Algorithm Used

- **Depth-First Search (DFS)** for exploring connected land cells.
- 8-directional movement is supported to identify diagonally connected land.

---

## Tags

- Graph
- DFS
- BFS
- Matrix Traversal
- Connected Components

---

## Author
Abhinav Kumar

