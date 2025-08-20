# Search in Fully Rotated Sorted 2D Matrix

**Difficulty:** Medium  
**Accuracy:** 56.77%  
**Submissions:** 11K+  
**Points:** 4  
**Average Time:** 20m

---

## Problem Statement
You are given a 2D matrix `mat[][]` of size `n x m` that was initially filled in the following manner:

1. Each row is sorted in increasing order from left to right.
2. The first element of every row is greater than the last element of the previous row.

This implies that if the matrix is flattened row-wise, it forms a strictly sorted 1D array.

Later, this sorted 1D array was rotated at some unknown pivot. The rotated array was then written back into the matrix row-wise to form the current matrix.

You are given such a matrix `mat[][]` and an integer `x`, determine whether `x` exists in the matrix.

---

## Examples

### Example 1
**Input:**  
```
x = 3
mat = [[7, 8, 9, 10],
       [11, 12, 13, 1],
       [2, 3, 4, 5]]
```
**Output:**
```
true
```
**Explanation:** 3 is located at the 3rd row and 2nd column.

---

### Example 2
**Input:**  
```
x = 10
mat = [[6, 7, 8],
       [9, 1, 2],
       [3, 4, 5]]
```
**Output:**
```
false
```
**Explanation:** The value 10 does not exist in the matrix.

---

## Constraints
- `1 ≤ n × m ≤ 10^5`
- `1 ≤ mat[i][j], x ≤ 10^6`

---

## Approach
This problem is a variation of **Search in Rotated Sorted Array**, extended to a 2D matrix.

### Key Idea:
- Treat the matrix as a flattened rotated sorted 1D array of size `n*m`.
- Use **binary search** with index mapping:
  - Row index: `mid / m`
  - Column index: `mid % m`
- Check sorted halves as in rotated array search.

### Steps:
1. Initialize `left = 0`, `right = n*m - 1`.
2. While `left <= right`, calculate `mid`.
3. Get value at `mid`: `mat[mid/m][mid%m]`.
4. If it matches `x`, return true.
5. Otherwise, decide which half is sorted and adjust search space.

---

## C++ Solution
```cpp
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int left = 0, right = n * m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mat[mid / m][mid % m];

            if (midVal == x) return true;

            int leftVal = mat[left / m][left % m];
            int rightVal = mat[right / m][right % m];

            // Left half is sorted
            if (leftVal <= midVal) {
                if (x >= leftVal && x < midVal)
                    right = mid - 1;
                else
                    left = mid + 1;
            } 
            // Right half is sorted
            else {
                if (x > midVal && x <= rightVal)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** `O(log(n*m))` (binary search)
- **Space Complexity:** `O(1)` (constant extra space)

---

✅ Efficient solution using binary search on a virtually flattened rotated array.
