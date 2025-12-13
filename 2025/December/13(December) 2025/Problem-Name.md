# Swap Diagonals of a Matrix

## Problem Statement

Given a square matrix `mat[][]` of size `n x n`, the task is to **swap the elements of the major and minor diagonals**.

### Definitions

* **Major Diagonal**: Elements from top-left to bottom-right (`row == column`)
* **Minor Diagonal**: Elements from top-right to bottom-left (`row + column == n - 1`)

The swap is done **row-wise**, meaning for each row `i`, we swap:

* `mat[i][i]` with `mat[i][n - 1 - i]`

---

## Examples

### Example 1

**Input:**

```
[[0, 1, 2],
 [3, 4, 5],
 [6, 7, 8]]
```

**Output:**

```
[[2, 1, 0],
 [3, 4, 5],
 [8, 7, 6]]
```

### Example 2

**Input:**

```
[[2, 3],
 [5, 4]]
```

**Output:**

```
[[3, 2],
 [4, 5]]
```

---

## Approach

1. Get the size of the matrix `n`.
2. Traverse each row `i` from `0` to `n-1`.
3. Swap the elements at positions:

   * Major diagonal: `(i, i)`
   * Minor diagonal: `(i, n - 1 - i)`

The operation is performed **in-place**, requiring no extra space.

---

## C++ Implementation

```cpp
class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            swap(mat[i][i], mat[i][n - 1 - i]);
        }
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` (in-place)

---

## Notes

* Works for both even and odd-sized matrices.
* For odd `n`, the center element lies on both diagonals and swapping it has no effect.

---

✔️ Simple, efficient, and optimal solution.
