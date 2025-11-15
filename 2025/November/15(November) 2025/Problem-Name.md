# Minimum Cost to Cut a Stick

## 📝 Problem Overview

You are given a wooden stick of length **n**, labeled from 0 to n. You are also given an integer array **cuts[]**, where each element represents a position along the stick where you can make a cut.

Each cut costs an amount equal to the **length of the stick being cut at that moment**. After making a cut, the stick splits into two smaller sticks, and you can then cut those independently.

Your task is to determine the **minimum total cost** required to perform **all** the cuts.

---

## 🧠 Key Insight

This is a classic **Interval Dynamic Programming** problem.

To compute the minimum cost:

1. **Add boundaries**: Insert `0` and `n` into the cuts array.
2. **Sort** the cuts.
3. Use **dp[i][j]** to represent the minimum cost to cut the section from `cuts[i]` to `cuts[j]`.
4. For every interval `[i, j]`, try making every possible cut between them.

The recurrence:

```
dp[i][j] = min(dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]))
```

for all `k` such that `i < k < j`.

---

## 🧾 C++ Code (Bottom-Up DP)

```cpp
class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int k = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(k+2, vector<int>(k+2, 0));

        for(int len = 2; len < k + 2; len++){
            for(int i = 0; i + len < k + 2; i++){
                int j = i + len;
                dp[i][j] = INT_MAX;

                for(int cut = i + 1; cut < j; cut++){
                    dp[i][j] = min(dp[i][j],
                                   dp[i][cut] + dp[cut][j] + cuts[j] - cuts[i]);
                }
            }
        }

        return dp[0][k+1];
    }
};
```

---

## 📌 Example

### Input:

```
n = 10
cuts = [2, 4, 7]
```

### Output:

```
20
```

### Explanation:

Optimal cut order = `[4, 2, 7]`
Cost = `10 + 4 + 6 = 20`

---

## ⏱️ Complexity

* **Time Complexity:** `O(k^3)` where `k = cuts.size() + 2`
* **Space Complexity:** `O(k^2)`

---

## ✅ Summary

This problem is solved optimally using **Interval DP**, similar to Matrix Chain Multiplication. We minimize cost by trying all intermediate cuts within each segment.

If you'd like, I can also add:

* A memoization version
* Visual diagram for DP intervals
* More examples
