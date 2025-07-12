# Gold Mine Problem

**Difficulty:** Medium
**Accuracy:** 29.73%
**Submissions:** 132K+
**Points:** 4

## Problem Statement

Given a gold mine represented by a 2D matrix `mat[][]` where each cell contains a positive integer indicating the amount of gold in tons. A miner can start from any row in the first column and move to the following positions:

* Right (`→`)
* Diagonally up-right (`↗`)
* Diagonally down-right (`↘`)

The miner continues to move until he can no longer proceed to the next column. Your task is to find the **maximum amount of gold** the miner can collect.

## Input

* `mat[][]`: 2D matrix where `1 ≤ mat.size(), mat[0].size() ≤ 500`
* `0 ≤ mat[i][j] ≤ 100`

## Output

* Return a single integer - the maximum amount of gold that can be collected.

## Examples

### Example 1:

**Input:**

```
mat = [[1, 3, 3],
       [2, 1, 4],
       [0, 6, 4]]
```

**Output:** `12`
**Explanation:** The path is (1,0) → (2,1) → (2,2) → total gold = 2 + 6 + 4 = 12

### Example 2:

**Input:**

```
mat = [[1, 3, 1, 5],
       [2, 2, 4, 1],
       [5, 0, 2, 3],
       [0, 6, 1, 2]]
```

**Output:** `16`
**Explanation:** One possible path: (2,0) → (3,1) → (2,2) → (2,3) → 5 + 6 + 2 + 3 = 16

## Constraints

* Matrix dimensions up to 500 x 500
* Each cell's value ranges from 0 to 100

## Approach

We use **Dynamic Programming** to solve the problem:

1. Create a `dp` table of the same size as `mat`.
2. Traverse column by column from left to right.
3. For each cell `(i,j)`, compute:

   * Up-left: `dp[i-1][j-1]` if `i > 0`
   * Left: `dp[i][j-1]`
   * Down-left: `dp[i+1][j-1]` if `i < n - 1`
4. Take the maximum of the three and add `mat[i][j]`
5. Return the maximum value from the last column.

## Time and Space Complexity

* **Time Complexity:** O(n × m)
* **Space Complexity:** O(n × m) (can be optimized to O(n) with 2 arrays)
