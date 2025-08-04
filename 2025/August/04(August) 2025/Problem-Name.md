### Maximum Sum Rectangle in a 2D Matrix

**Problem Statement:**
Given a 2D matrix `mat[][]` of size `n x m`, find the maximum possible sum of any submatrix within the given matrix.

---

**Examples:**

Input:
```cpp
mat = {
    { 1,  2, -1, -4, -20},
    {-8, -3,  4,  2,   1},
    { 3,  8, 10,  1,   3},
    {-4, -1,  1,  7,  -6}
};
```
Output:
```
29
```
Explanation:
The rectangle from (1,2) to (3,3) gives the maximum sum = 29.

---

**Constraints:**
- 1 ≤ n, m ≤ 300
- -1000 ≤ mat[i][j] ≤ 1000

---

**Approach:**
- Use **Kadane’s Algorithm** to find maximum subarray sum for a 1D array.
- Extend it to 2D by:
  1. Fixing `left` and `right` column boundaries.
  2. Creating a temporary row-sum array.
  3. Applying Kadane’s algorithm on this array.

---

**Time Complexity:** `O(m^2 * n)`

---

**C++ Code:**
```cpp
class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < m; ++left) {
            vector<int> temp(n, 0);

            for (int right = left; right < m; ++right) {
                for (int i = 0; i < n; ++i)
                    temp[i] += mat[i][right];

                int currSum = temp[0], maxTempSum = temp[0];
                for (int i = 1; i < n; ++i) {
                    currSum = max(temp[i], currSum + temp[i]);
                    maxTempSum = max(maxTempSum, currSum);
                }

                maxSum = max(maxSum, maxTempSum);
            }
        }
        return maxSum;
    }
};
```

---

**Notes:**
- This technique can be extended to track the top, bottom, left, and right coordinates of the submatrix as well.
- Efficient for competitive programming and real-world applications like image processing or data mining.
