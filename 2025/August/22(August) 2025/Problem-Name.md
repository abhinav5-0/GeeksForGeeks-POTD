# Median in a Row-wise Sorted Matrix

**Difficulty:** Hard  
**Accuracy:** 55.05%  
**Points:** 8

---

## Problem Statement
Given a row-wise sorted matrix `mat[][]` of size `n*m`, where the number of rows and columns is always odd. Return the median of the matrix.

---

## Examples

### Example 1
**Input:**
```text
mat = [[1, 3, 5],
       [2, 6, 9],
       [3, 6, 9]]
```
**Output:**
```text
5
```
**Explanation:**
Sorting matrix elements gives `[1, 2, 3, 3, 5, 6, 6, 9, 9]`. Hence, median is **5**.

---

### Example 2
**Input:**
```text
mat = [[2, 4, 9],
       [3, 6, 7],
       [4, 7, 10]]
```
**Output:**
```text
6
```
**Explanation:**
Sorting matrix elements gives `[2, 3, 4, 4, 6, 7, 7, 9, 10]`. Hence, median is **6**.

---

### Example 3
**Input:**
```text
mat = [[3],
       [4],
       [8]]
```
**Output:**
```text
4
```
**Explanation:**
Sorting matrix elements gives `[3, 4, 8]`. Hence, median is **4**.

---

## Constraints
- `1 ≤ n, m ≤ 400`
- `1 ≤ mat[i][j] ≤ 2000`

---

## Approach
We use **Binary Search on the Answer**:
1. Median is the `((n*m) + 1) / 2`-th smallest element.
2. Use binary search on the value range (`1` to `2000`).
3. For each mid value, count how many elements are `<= mid` using `upper_bound` in each row.
4. Adjust search range until the median is found.

---

## Complexity
- `upper_bound` on each row: **O(log m)**
- For `n` rows: **O(n log m)**
- Binary search on range (max 2000): **O(log 2000) ≈ 11**
- **Total:** `O(n log m log(maxVal))`, efficient for up to 400x400 matrices.

---

## C++ Solution
```cpp
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 1, high = 2000; // given constraint
        
        int desired = (n * m + 1) / 2;
        
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            
            // count numbers <= mid in each row
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if (count < desired) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};
