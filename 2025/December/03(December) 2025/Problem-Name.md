# Travelling Salesman Problem (TSP)

## Problem Statement

You are given a 2D matrix `cost[][]` of size `n` where `cost[i][j]` denotes the cost of traveling from city `i` to city `j`. You must start at city `0`, visit all cities exactly once, and then return back to city `0` with the **minimum possible travel cost**.

### Constraints

* `1 ≤ n ≤ 15`
* `0 ≤ cost[i][j] ≤ 10^4`

---

## Approach: Dynamic Programming with Bitmasking

This is the classical **NP-hard Travelling Salesman Problem**, but with `n ≤ 15`, we can efficiently solve it using **DP + Bitmask**.

### DP Definition

We use:

```
dp[mask][i]
```

Where:

* `mask` (bitmask) represents the set of cities already visited.
* `i` is the **last visited city** in the current path.
* `dp[mask][i]` stores the **minimum cost** to start from city `0`, visit all cities in `mask`, and end at city `i`.

### Transition

For each unvisited city `j`:

```
dp[mask | (1 << j)][j] = min(
    dp[mask | (1 << j)][j],
    dp[mask][i] + cost[i][j]
)
```

### Final Answer

After visiting all cities, we complete the loop by returning to city `0`:

```
answer = min(dp[(1<<n) - 1][i] + cost[i][0]) for all i > 0
```

---

## Time and Space Complexity

* **Time:** (O(n^2 \cdot 2^n))
* **Space:** (O(n \cdot 2^n))

Efficient for `n ≤ 15`.

---

## C++ Implementation

```cpp
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int FULL = (1 << n);
        const int INF = 1e9;

        vector<vector<int>> dp(FULL, vector<int>(n, INF));
        dp[1][0] = 0;  // start from city 0

        for (int mask = 1; mask < FULL; mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u))) continue;
                if (dp[mask][u] == INF) continue;

                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue;

                    int newMask = mask | (1 << v);
                    dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + cost[u][v]);
                }
            }
        }

        int ans = INF;
        for (int u = 1; u < n; u++) {
            ans = min(ans, dp[FULL - 1][u] + cost[u][0]);
        }
        return ans;
    }
};
```

---

## Example

### Input:

```
cost = [
  [0, 1000, 5000],
  [5000, 0, 1000],
  [1000, 5000, 0]
]
```

### Output:

```
3000
```

### Explanation:

Optimal path:

```
0 → 1 → 2 → 0
Cost = 1000 + 1000 + 1000
```

---

## Summary

* Uses **DP with bitmasking**.
* Ensures minimal cost to complete a full cycle.
* Optimal for `n ≤ 15`.

This covers the complete explanation + code for the TSP problem.
