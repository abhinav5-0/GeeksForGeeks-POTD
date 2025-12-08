# Matrix Chain Multiplication – Bracket Construction (MD File)

## 📘 Problem Summary

Given an array `arr[]` of length `n`, representing matrix dimensions, where matrix `i` has dimension:

```
arr[i] x arr[i+1]
```

There are **n-1 matrices**.
Your task: construct the **parenthesization string** (using A, B, C, ... for matrices) that yields the **minimum scalar multiplication cost**.

### Example

For `arr = [40,20,30,10,30]`:
Optimal ordering:

```
((A(BC))D)
```

---

## 🧠 Approach

We use **Matrix Chain Multiplication DP**:

* `dp[i][j]` → minimum cost to multiply matrices `i` to `j`.
* `split[i][j]` → position `k` where optimal split occurs.
  After filling the DP table, we reconstruct the string with recursion.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();                // number of dimensions
        int m = n - 1;                     // number of matrices

        // dp[i][j] = min cost to multiply matrices i..j
        vector<vector<long long>> dp(m, vector<long long>(m, 0));

        // to store split index
        vector<vector<int>> split(m, vector<int>(m, -1));

        // L = chain length
        for (int L = 2; L <= m; L++) {
            for (int i = 0; i + L - 1 < m; i++) {
                int j = i + L - 1;
                dp[i][j] = LLONG_MAX;

                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] +
                        1LL * arr[i] * arr[k+1] * arr[j+1];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        // build the parenthesization string
        function<string(int,int)> build = [&](int i, int j) {
            if (i == j) return string(1, 'A' + i);
            int k = split[i][j];
            return "(" + build(i, k) + build(k + 1, j) + ")";
        };

        return build(0, m - 1);
    }
};
```

---

## 📝 Output Format

The function returns a string like:

```
((A(BC))D)
```

This ensures **minimum multiplications**.

---

## 📎 Notes

* Matrices are named sequentially: A, B, C, ...
* Parentheses determine multiplication order.
* Optimal structure minimizes cost, not depth.

---

If you want, I can also add:

* DP table visualization
* Step-by-step dry run
* Java / Python versions
