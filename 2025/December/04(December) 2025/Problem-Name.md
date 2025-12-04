# Optimal Binary Search Tree (OBST)

## **Problem Overview**

You are given:

* A sorted array of distinct keys: `keys[]`
* A frequency array: `freq[]` where `freq[i]` is the number of searches for `keys[i]`

You must build a Binary Search Tree (BST) such that:

* Each key appears exactly once
* The root is at **level 1**
* The cost of searching key `i` is:

  **cost = freq[i] × level(i)**

The goal is to **minimize the total search cost**.

---

## **Dynamic Programming Approach**

Let:

* `dp[i][j]` = minimum cost of an optimal BST containing keys from index `i` to `j`.
* The total frequency sum for a segment `[i..j]` is needed because when a root is chosen, all other nodes become deeper by 1.

### **Key DP Transition**

```
dp[i][j] = min(
    dp[i][r-1] + dp[r+1][j] + sum(freq[i..j])
) for all r in [i..j]
```

### **Why add sum(freq[i..j])?**

Because when a key `r` becomes root, all nodes except `r` move one level deeper.
This increases the cost of every frequency in the range by exactly `sum(freq[i..j])`.

---

## **Prefix Sum Optimization**

We use a prefix sum array for fast calculation of frequency range sum:

```
pref[i+1] = pref[i] + freq[i]
```

Then:

```
rangeSum(i, j) = pref[j+1] - pref[i]
```

---

## **Final Time Complexity**

* DP computation: `O(n³)`
* Memory usage: `O(n²)`

This is optimal for the classical OBST DP solution.

---

## **C++ Code Implementation**

```cpp
class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        if (n == 0) return 0;

        // dp[i][j] = min cost of optimal BST using keys from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // prefix sum of frequencies for O(1) range sum
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + freq[i];
        }
        auto rangeSum = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };

        // length = 1: cost is just its own frequency (depth = 1)
        for (int i = 0; i < n; ++i) {
            dp[i][i] = freq[i];
        }

        // consider chains of length 2..n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                int fsum = rangeSum(i, j);

                for (int r = i; r <= j; ++r) {
                    int left  = (r > i) ? dp[i][r - 1] : 0;
                    int right = (r < j) ? dp[r + 1][j] : 0;
                    int cost = left + right + fsum;
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};
```

---

## **Example**

**Input:**

```
keys = [10, 12]
freq = [34, 50]
```

**Output:** `118`

The optimal BST places `12` at root.

---

## **Conclusion**

This classic DP solution correctly computes the minimum search cost for an Optimal Binary Search Tree using prefix sums and a cubic DP.

If you'd like, I can also add:

* A visualization of recursion tree
* A table of DP computation
* An optimized `O(n²)` version using Knuth Optimization
