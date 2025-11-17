# Max Sum Increasing Subsequence (MSIS)

## 🧩 Problem Summary

Given an array of **positive integers**, find the **maximum sum** of a subsequence such that:

* The subsequence is **strictly increasing**.
* Among all such subsequences, you must return the **maximum possible sum**.

### 🔹 Example 1

**Input:** `[1, 101, 2, 3, 100]`
**Output:** `106`
**Explanation:** Increasing subsequence is `[1, 2, 3, 100]`.

### 🔹 Example 2

**Input:** `[4, 1, 2, 3]`
**Output:** `6` → `[1, 2, 3]`

### 🔹 Example 3

**Input:** `[4, 1, 2, 4]`
**Output:** `7` → `[1, 2, 4]`

---

## 🧠 Approach (Dynamic Programming)

We use a DP array `dp[i]` that stores:

> **Maximum sum of an increasing subsequence ending at index `i`.**

### Steps:

1. Initialize `dp[i] = arr[i]` for all `i`.
2. For each `i`, check all previous indices `j < i`.
3. If `arr[j] < arr[i]`, we can extend the subsequence:

   ```cpp
   dp[i] = max(dp[i], dp[j] + arr[i]);
   ```
4. The answer is the **maximum value in the dp array**.

### Time Complexity: **O(n²)**

### Space Complexity: **O(n)**

---

## ✅ C++ Code Implementation

```cpp
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);

        // Initialize dp with the array values
        for(int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }

        // Compute MSIS
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        // The answer is the maximum value in dp
        return *max_element(dp.begin(), dp.end());
    }
};
```

---

## 🎯 Key Insight

This is similar to LIS (Longest Increasing Subsequence), but instead of counting **length**, we accumulate **sum**.

---

If you'd like the code + explanation in another format (PDF, PPT, etc.), just let me know! 🚀
