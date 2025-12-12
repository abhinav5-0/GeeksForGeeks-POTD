# Transpose of Matrix

**Difficulty:** Easy
**Accuracy:** 66.5%
**Submissions:** 122K+
**Points:** 2
**Average Time:** 20m

---

## 📝 Problem Statement

You are given a **square matrix** of size `n x n`. Your task is to find the **transpose** of the matrix.

The **transpose** of a matrix is obtained by converting all the **rows to columns** and all the **columns to rows**.

---

## 🔍 Examples

### Example 1

**Input:**

```
mat = [[1, 1, 1, 1],
       [2, 2, 2, 2],
       [3, 3, 3, 3],
       [4, 4, 4, 4]]
```

**Output:**

```
[[1, 2, 3, 4],
 [1, 2, 3, 4],
 [1, 2, 3, 4],
 [1, 2, 3, 4]]
```

**Explanation:** Rows are converted into columns.

---

### Example 2

**Input:**

```
mat = [[1, 2],
       [9, -2]]
```

**Output:**

```
[[1, 9],
 [2, -2]]
```

**Explanation:** Rows are converted into columns.

---

## ✅ Constraints

* `1 ≤ n ≤ 10^3`
* `-10^9 ≤ mat[i][j] ≤ 10^9`

---

## 💡 Optimal Approach

For a square matrix, you can transpose **in-place** by swapping elements across the diagonal.

* Swap `mat[i][j]` with `mat[j][i]` for all `i < j`.
* Time Complexity: **O(n²)**
* Space Complexity: **O(1)** (in-place)

---

## ✔️ C++ Code

```cpp
class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size();

        // Transpose in-place
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        return mat;
    }
};
```

---

## 🎯 Summary

* Transpose is achieved by swapping elements across the diagonal.
* Efficient **O(1)** space solution.
* Works within constraints up to `n = 1000`.

---
