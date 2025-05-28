# Problem: Find Rectangle with Corners as 1

**Difficulty:** Medium
**Accuracy:** 61.11%
**Submissions:** 10K+
**Points:** 4

## Problem Statement

Given an `n x m` binary matrix `mat[][]` containing only 0s and 1s, determine if there exists a rectangle within the matrix such that all four corners of the rectangle are 1. If such a rectangle exists, return `true`; otherwise, return `false`.

## Example 1

**Input:**

```cpp
mat[][] =
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
```

**Output:**

```
true
```

**Explanation:**
Valid corners are at index (1,2), (1,4), (3,2), (3,4).

## Example 2

**Input:**

```cpp
mat[][] =
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
```

**Output:**

```
false
```

**Explanation:**
There are no valid corners with value 1.

## Constraints

* 1 <= n, m <= 200
* 0 <= mat\[i]\[j] <= 1

## C++ Function Signature

```cpp
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat);
};
```

## Approach

* Iterate over all pairs of rows.
* For each pair of rows, check the columns where both rows have 1s.
* If there are at least two such columns, then a rectangle is formed using those columns and these two rows.

## Time Complexity

* O(n^2 \* m), where `n` is the number of rows and `m` is the number of columns.

## Efficient C++ Implementation

```cpp
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();

        // Iterate over all pairs of rows
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int count = 0;
                for (int col = 0; col < m; ++col) {
                    // Check if both rows have 1s at the same column
                    if (mat[i][col] == 1 && mat[j][col] == 1) {
                        count++;
                        if (count >= 2) return true;
                    }
                }
            }
        }
        return false;
    }
};
```
