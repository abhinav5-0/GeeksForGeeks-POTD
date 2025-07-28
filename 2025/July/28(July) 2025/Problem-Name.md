## Problem: Make Matrix Beautiful

**Difficulty:** Medium  
**Accuracy:** 64.75%  
**Points:** 4  
**Average Time:** 20m

---

### Problem Statement
A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. 

Given a square matrix `mat[][]`, your task is to determine the minimum number of operations required to make the matrix beautiful.

In one operation, you are allowed to increment the value of any single cell by 1.

---

### Examples

#### Example 1:
**Input:**
```cpp
mat[][] = [[1, 2], 
           [3, 4]]
```
**Output:**
```
4
```
**Explanation:**
Increment value of cell(0, 0) by 3,  
Increment value of cell(0, 1) by 1.  

Matrix after operations:
```
[[4, 3], 
 [3, 4]]
```
Sum of each row and column is 7. Hence, 4 operations required.

#### Example 2:
**Input:**
```cpp
mat[][] = [[1, 2, 3],
           [4, 2, 3],
           [3, 2, 1]]
```
**Output:**
```
6
```
**Explanation:**
Increment cell(0, 0) by 1, cell(0, 1) by 2, cell(2, 1) by 1, and cell(2, 2) by 2.  
Final matrix:
```
[[2, 4, 3], 
 [4, 2, 3], 
 [3, 3, 3]]
```
All rows and columns sum to 9.

---

### Constraints
- 1 ≤ mat.size() ≤ 900
- 0 ≤ mat[i][j] ≤ 10^6

---

### Approach
1. Compute the sum of each row and each column.
2. Determine the target sum: the maximum among all row and column sums.
3. Traverse the matrix and increment cells such that both row and column sums approach the target.

---

### C++ Code
```cpp
class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);

        // Step 1: Calculate row and column sums
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }

        // Step 2: Find target sum
        int target = 0;
        for (int i = 0; i < n; ++i)
            target = max({target, rowSum[i], colSum[i]});

        // Step 3: Increment cells to balance
        int operations = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            int diff = min(target - rowSum[i], target - colSum[j]);
            mat[i][j] += diff;
            rowSum[i] += diff;
            colSum[j] += diff;
            operations += diff;

            if (rowSum[i] == target) i++;
            if (colSum[j] == target) j++;
        }

        return operations;
    }
};
```

---

### Complexity Analysis
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(n)
