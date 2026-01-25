# Number of Valid Parentheses

**Difficulty:** Medium  
**Accuracy:** 66.08%  
**Points:** 4  

---

## Problem Statement

You are given a number **n**, your task is to find the number of all the **valid parentheses expressions** of that length using only `"("` and `")"` brackets.

A parentheses string is **valid** if:

- Open brackets must be closed in the correct order.
- Every closing bracket has a corresponding opening bracket.

### Examples

| Input | Output | Explanation |
|------|--------|-------------|
| n = 2 | 1 | `()` |
| n = 4 | 2 | `(())`, `()()` |
| n = 6 | 5 | `((()))`, `(())()`, `()(())`, `()()()`, `(()())` |

---

## Key Insight

- A valid parentheses string always has **even length**.
- Let `n = 2 * k`
- The number of valid parentheses strings of length `n` is the **k-th Catalan Number**.

### Catalan Number Formula

\[
C_k = \frac{1}{k+1} \binom{2k}{k}
\]

---

## Approach

1. If `n` is odd → return `0`
2. Compute the Catalan number for `k = n / 2`
3. Use **Dynamic Programming** to avoid overflow and improve efficiency

---

## C++ Implementation

```cpp
class Solution {
  public:
    int findWays(int n) {
        if (n % 2 != 0) return 0;

        int k = n / 2;
        vector<long long> dp(k + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[k];
    }
};
