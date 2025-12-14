# 2D Submatrix Sum Queries

## Problem Statement

Given a 2D integer matrix `mat[][]` and a list of queries `queries[][]`, answer submatrix sum queries.

Each query is of the form:

```
[r1, c1, r2, c2]
```

Where:

* `(r1, c1)` is the **top-left** corner
* `(r2, c2)` is the **bottom-right** corner (inclusive)

For every query, return the sum of elements inside the selected submatrix.

---

## Key Idea: 2D Prefix Sum

To efficiently handle up to `10^5` queries, we use a **2D prefix sum array**.

### Prefix Sum Definition

`pref[i][j]` stores the sum of elements from `(0,0)` to `(i,j)`.

### Prefix Sum Formula

```
pref[i][j] = mat[i][j]
           + (i > 0 ? pref[i-1][j] : 0)
           + (j > 0 ? pref[i][j-1] : 0)
           - (i > 0 && j > 0 ? pref[i-1][j-1] : 0)
```

---

## Query Calculation

For a query `(r1, c1)` to `(r2, c2)`:

```
sum = pref[r2][c2]
    - (r1 > 0 ? pref[r1-1][c2] : 0)
    - (c1 > 0 ? pref[r2][c1-1] : 0)
    + (r1 > 0 && c1 > 0 ? pref[r1-1][c1-1] : 0)
```

Each query is answered in **O(1)** time.

---

## C++ Implementation

```cpp
class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat,
                            vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();

        // Build prefix sum matrix
        vector<vector<int>> pref(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] = mat[i][j];
                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
            }
        }

        // Answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

            int sum = pref[r2][c2];
            if (r1 > 0) sum -= pref[r1 - 1][c2];
            if (c1 > 0) sum -= pref[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += pref[r1 - 1][c1 - 1];

            ans.push_back(sum);
        }

        return ans;
    }
};
```

---

## Complexity Analysis

* **Preprocessing Time:** `O(n × m)`
* **Query Time:** `O(1)` per query
* **Total Time:** `O(n × m + q)`
* **Space Complexity:** `O(n × m)`

---

## Summary

* Use **2D prefix sums** for fast submatrix queries
* Handles large constraints efficiently
* Standard and interview-friendly solution
