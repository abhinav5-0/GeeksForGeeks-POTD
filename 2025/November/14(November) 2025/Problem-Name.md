# Minimum Cost to Merge Stones (DP)

## Problem Summary

You are given an array `stones[]` of size `n`, where each element represents the number of stones in that pile. In one move, you can merge **exactly `k` consecutive piles** into **one pile**, and the **cost = sum of stones in those `k` piles**.

Your goal is to **merge all piles into one** with **minimum total cost**. If not possible, return **-1**.

---

## Key Observations

### **1. Feasibility Check**

To end up with **1 pile**, after repeatedly merging groups of `k`, the number of piles can only reduce in increments of `(k - 1)`.

Thus a necessary condition:

```
(n - 1) % (k - 1) == 0
```

Otherwise, return `-1` immediately.

---

## DP Approach

This is a classic **interval DP** problem similar to "Burst Balloons" or "Matrix Chain Multiplication".

We use:

```
dp[i][j][m] = minimum cost to merge stones[i..j] into m piles
```

Where:

* `m` can be from `1` to `k`
* Final answer is `dp[0][n-1][1]`

### Prefix Sum

To compute range sums efficiently:

```
prefix[i] = sum of stones[0..i]
range_sum(l, r) = prefix[r] - (l? prefix[l-1] : 0)
```

---

## DP Transitions

### If we want to merge interval `[i..j]` into `m > 1` piles:

We break interval at positions `t` with step `(k - 1)`:

```
dp[i][j][m] = min over t { dp[i][t][1] + dp[t+1][j][m-1] }
```

Because only when merging exactly `k` piles we reduce pile count by `k-1`.

### If we want to merge `[i..j]` into **1** pile:

We must first merge into **exactly `k` piles**, then merge those:

```
dp[i][j][1] = dp[i][j][k] + range_sum(i, j)
```

Since final merge cost = sum of stones in that interval.

---

## C++ Implementation

```cpp
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;  // not feasible

        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];

        auto sum = [&](int l, int r) { return prefix[r + 1] - prefix[l]; };

        const int INF = 1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, INF)));

        for (int i = 0; i < n; i++) dp[i][i][1] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                // compute dp[i][j][m]
                for (int m = 2; m <= k; m++) {
                    for (int t = i; t < j; t += (k - 1)) {
                        dp[i][j][m] = min(dp[i][j][m], dp[i][t][1] + dp[t+1][j][m-1]);
                    }
                }
                // merge into 1 pile if possible
                if (dp[i][j][k] < INF) {
                    dp[i][j][1] = dp[i][j][k] + sum(i, j);
                }
            }
        }

        return dp[0][n-1][1];
    }
};
```

---

## Time Complexity

```
O(n³ / (k-1))
```

Since:

* DP for each interval involves splitting at increments of `(k - 1)`
* n ≤ 30 → feasible

---

## Example Walkthrough

### Input:

```
stones = [1, 2, 3], k = 2
```

Feasible because `(3−1) % 1 == 0`.

Steps:

* Merge (1,2) → cost 3 → [3,3]
* Merge (3,3) → cost 6 → [6]
  Total = **9**

---

## Final Notes

This problem is a classic example of **interval DP with multi-state merging**. Keep in mind:

* `dp[i][j][1]` always depends on `dp[i][j][k]`
* Merging reduces piles by `(k − 1)`

This DP is tricky but manageable with the above formulation.
