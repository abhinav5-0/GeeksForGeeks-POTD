# Flood Fill Algorithm

## Problem Statement
You are given a 2D grid `image[][]` of size `n x m`, where each `image[i][j]` represents the color of a pixel in the image. Also provided is a coordinate `(sr, sc)` representing the starting pixel (row and column) and a new color value `newColor`.

Your task is to perform a flood fill starting from the pixel `(sr, sc)`, changing its color to `newColor` and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

## Examples

### Example 1:
**Input:**
```cpp
image = [[1, 1, 1, 0],
         [0, 1, 1, 1],
         [1, 0, 1, 1]]
sr = 1, sc = 2, newColor = 2
```
**Output:**
```cpp
[[2, 2, 2, 0],
 [0, 2, 2, 2],
 [1, 0, 2, 2]]
```
**Explanation:** Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2.

### Example 2:
**Input:**
```cpp
image = [[1, 1, 1],
         [1, 1, 0],
         [1, 0, 1]]
sr = 1, sc = 1, newColor = 2
```
**Output:**
```cpp
[[2, 2, 2],
 [2, 2, 0],
 [2, 0, 1]]
```
**Explanation:** From (1, 1), flood fill fills all 1s that are 4-connected with 2.

### Example 3:
**Input:**
```cpp
image = [[0, 1, 0],
         [0, 1, 0]]
sr = 0, sc = 1, newColor = 0
```
**Output:**
```cpp
[[0, 0, 0],
 [0, 0, 0]]
```
**Explanation:** All 1s connected to (0,1) become 0.

## Constraints
- `1 <= n, m <= 500`
- `0 <= image[i][j] <= 10`
- `0 <= newColor <= 10`
- `0 <= sr < n`
- `0 <= sc < m`

## Approach
The problem can be solved using either DFS (Depth First Search) or BFS (Breadth First Search). DFS is a recursive solution where we keep visiting neighboring cells that match the original color and update them to the new color.

### Steps:
1. Store the original color at `(sr, sc)`.
2. If `newColor == original color`, return the image as it is.
3. Call DFS on `(sr, sc)` and for each valid neighbor, if it has the same color as original, recursively call DFS on it.

## DFS C++ Implementation
```cpp
class Solution {
  public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        int n = image.size();
        int m = image[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m || image[r][c] != color)
            return;

        image[r][c] = newColor;

        dfs(image, r + 1, c, color, newColor); // down
        dfs(image, r - 1, c, color, newColor); // up
        dfs(image, r, c + 1, color, newColor); // right
        dfs(image, r, c - 1, color, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
};
```

## Usage
This algorithm can be used in graphics editors, path-finding visualizations, and region detection in matrices.

---
**Time Complexity:** O(N*M) where N and M are the number of rows and columns.
**Space Complexity:** O(N*M) for the recursion stack in the worst case.

