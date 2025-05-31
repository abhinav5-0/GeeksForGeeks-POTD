# Kth Element in Matrix

## Problem Statement

Given a matrix `mat[][]` of size `n x n`, where each row and each column is sorted in non-decreasing order, find the `k`th smallest element in the matrix.

### Input

* `n`: Integer, the size of the matrix (1 <= n <= 500)
* `mat[][]`: A 2D vector of integers where `1 <= mat[i][j] <= 10000` and each row and column is sorted.
* `k`: Integer such that `1 <= k <= n*n`

### Output

* The `k`th smallest element in the matrix.

### Examples

#### Example 1:

```
Input:
n = 4
mat = [[16, 28, 60, 64],
       [22, 41, 63, 91],
       [27, 50, 87, 93],
       [36, 78, 87, 94]]
k = 3

Output:
27
```

#### Example 2:

```
Input:
n = 4
mat = [[10, 20, 30, 40],
       [15, 25, 35, 45],
       [24, 29, 37, 48],
       [32, 33, 39, 50]]
k = 7

Output:
30
```

## Constraints

* `1 <= n <= 500`
* `1 <= mat[i][j] <= 10000`
* `1 <= k <= n*n`

## Solution Approach

We use a binary search approach on the value range:

1. Set `low = mat[0][0]`, `high = mat[n-1][n-1]`.
2. Perform binary search:

   * For `mid = (low + high)/2`, count elements less than or equal to `mid`.
   * If count < k, search the right half; else search the left half.
3. Stop when `low == high`, and return `low`.

### C++ Code

```cpp
class Solution {
  public:
    int countLessEqual(vector<vector<int>> &matrix, int mid, int n) {
        int count = 0;
        int row = n - 1, col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid, n);

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
```

### Time Complexity

* `O(n * log(max - min))`

### Space Complexity

* `O(1)`
