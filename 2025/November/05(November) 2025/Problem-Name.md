# Get Minimum Squares

**Difficulty:** Medium
**Accuracy:** 45.22%
**Points:** 4

---

## 🧩 Problem Statement

Given a positive integer `n`, find the **minimum number of perfect squares** (square of an integer) that sum up to `n`.

> Note: Every positive integer can be expressed as a sum of square numbers since 1 is a perfect square, and any number can be represented as 1×1 + 1×1 + 1×1 + ....

---

## 🧠 Examples

**Example 1:**
Input: `n = 100`
Output: `1`
Explanation: 10 × 10 = 100

**Example 2:**
Input: `n = 6`
Output: `3`
Explanation: 1×1 + 1×1 + 2×2 = 6

---

## ⚙️ Constraints

* 1 ≤ n ≤ 10⁴

---

## 💡 Approach

This is a **Dynamic Programming** problem, similar to the *Minimum Coin Change* problem.

### Idea

For each integer `i` from `1` to `n`, determine the minimum number of perfect squares needed to sum up to `i`.

We try all square numbers `j*j` such that `j*j ≤ i`, and take the minimum result.

### Recurrence Relation

[
dp[i] = 1 + \min(dp[i - j*j]) \text{ for all } j ,\text{such that}, j*j \leq i
]

### Base Case

* `dp[0] = 0`  (zero can be represented with 0 numbers)

---

## 🧮 Example Walkthrough (n = 6)

| i | Calculation        | dp[i] |
| - | ------------------ | ----- |
| 1 | 1² → dp[0]+1       | 1     |
| 2 | 1²+1² → dp[1]+1    | 2     |
| 3 | 1²+1²+1² → dp[2]+1 | 3     |
| 4 | 2² → dp[0]+1       | 1     |
| 5 | 2²+1² → dp[1]+1    | 2     |
| 6 | 2²+1²+1² → dp[2]+1 | 3     |

✅ Final answer: **3**

---

## 💻 C++ Code

```cpp
class Solution {
  public:
    int minSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // base case

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};
```

---

## ⏱️ Time Complexity

O(n × √n)

## 💾 Space Complexity

O(n)

---

### ✅ Summary

* Use **Dynamic Programming** to compute results efficiently.
* Each state considers all smaller square numbers.
* Optimal solution obtained by minimizing over all possibilities.
