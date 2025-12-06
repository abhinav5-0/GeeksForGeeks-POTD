# Optimal Strategy for a Game

You are given an integer array `arr[]` of size `n` (even). The elements represent coin values arranged in a row. Two players play alternately, and in each turn, a player picks either the first or last coin from the remaining row.

Both players play optimally.

Your task is to determine the **maximum amount of money you can collect if you go first**.

---

## **Example 1**

**Input:** `arr = [5, 3, 7, 10]`
**Output:** `15`
**Explanation:** Best play is picking 10 and 5.

## **Example 2**

**Input:** `arr = [8, 15, 3, 7]`
**Output:** `22`
**Explanation:** Best play is picking 7 and 15.

---

# 🧠 DP Logic (Interval DP)

Let `dp[i][j]` represent the **maximum amount you can collect** from subarray `arr[i..j]`.

If you pick `arr[i]`:

* Opponent chooses optimally from `(i+1, j)` → leaves you the **minimum** of two cases.

If you pick `arr[j]`:

* Same logic as above.

Thus:

```
dp[i][j] = max(
    arr[i] + min(dp[i+2][j], dp[i+1][j-1]),
    arr[j] + min(dp[i][j-2], dp[i+1][j-1])
)
```

---

# ✅ Final C++ Code

```cpp
class Solution {
public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Base case: one coin
        for (int i = 0; i < n; i++)
            dp[i][i] = arr[i];

        // Fill by increasing interval length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                long long pickLeft  = arr[i] + min(
                    (i+2 <= j ? dp[i+2][j] : 0),
                    (i+1 <= j-1 ? dp[i+1][j-1] : 0)
                );

                long long pickRight = arr[j] + min(
                    (i <= j-2 ? dp[i][j-2] : 0),
                    (i+1 <= j-1 ? dp[i+1][j-1] : 0)
                );

                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        return dp[0][n-1];
    }
};
```

---

If you want, I can also add:

* Recurrence explanation diagrams
* Memoized recursion version
* Space optimization
* Sample dry run
  Just tell me!
