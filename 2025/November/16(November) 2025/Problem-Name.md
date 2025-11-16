# Longest Common Increasing Subsequence (LCIS)

## **Problem Statement**

Given two arrays **a[]** and **b[]**, find the **length of the longest common increasing subsequence (LCIS)**.

A LCIS is:

* A subsequence present in **both** arrays
* **Strictly increasing**

### **Examples**

#### Example 1

```
Input: a = [3, 4, 9, 1]
       b = [5, 3, 8, 9, 10, 2, 1]
Output: 2
Explanation: LCIS = [3, 9]
```

#### Example 2

```
Input: a = [1, 1, 4, 3]
       b = [1, 1, 3, 4]
Output: 2
Explanation: LCIS = [1, 4] or [1, 3]
```

---

# ✅ **Approach: Dynamic Programming (O(n × m))**

We maintain a DP array on **b[]**:

* `dp[j]` = length of LCIS ending at `b[j]`
* For every element in `a[]`, update dp by scanning `b[]`

Key concepts:

* Maintain `current_max` = best LCIS value for all `b[j] < a[i]`
* If `a[i] == b[j]`: we extend LCIS → `dp[j] = current_max + 1`
* If `b[j] < a[i]`: update `current_max`

Final answer = `max(dp[])`

---

# ✅ **C++ Code**

```cpp
class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        vector<int> dp(m, 0);

        for (int i = 0; i < n; i++) {
            int current_max = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], current_max + 1);
                }
                if (b[j] < a[i]) {
                    current_max = max(current_max, dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
```

---

# 🧠 **Time & Space Complexity**

* **Time:** O(n × m)
* **Space:** O(m)

---

# ✔ Summary

LCIS is similar to LCS + LIS combined, but the optimal solution uses a 1D DP array on `b[]` and processes each `a[i]` while maintaining increasing-order constraints.

Fully optimized and suitable for constraints up to **1000 × 1000**.

---

Let me know if you want a **visual dry run** or **graphical explanation** added!

