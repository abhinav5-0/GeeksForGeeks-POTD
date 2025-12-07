# Number of Distinct Subsequences

## Problem

Given a string `str` consisting of lowercase English alphabets, find the **number of distinct subsequences** of the string.

Since the answer can be very large, return it modulo **1e9 + 7**.

### Examples

**Input:** `str = "gfg"`
**Output:** `7`

Distinct subsequences:

```
"", "g", "f", "gf", "fg", "gg", "gfg"
```

**Input:** `str = "ggg"`
**Output:** `4`

Distinct subsequences:

```
"", "g", "gg", "ggg"
```

### Constraints

```
1 ≤ |str| ≤ 100000
str contains lowercase English letters
```

---

## Approach

Use dynamic programming with last-appearance tracking.

Let `dp[i]` = number of distinct subsequences of prefix `str[0..i-1]`.

Base case:

```
dp[0] = 1   // empty subsequence
```

Transition:

```
dp[i] = 2 * dp[i - 1]
```

If current character has appeared before at position `j`:

```
dp[i] -= dp[j - 1]
```

This removes duplicate subsequences.

Track last appearance using an array of size 26.

---

## Code

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int distinctSubseq(string &str) {
        int n = str.size();
        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;   // empty subsequence

        for (int i = 1; i <= n; i++) {
            int ch = str[i - 1] - 'a';

            // double the number of subsequences
            dp[i] = (2 * dp[i - 1]) % MOD;

            // if character appeared before, subtract old duplicates
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + MOD) % MOD;
            }

            last[ch] = i;  // store last occurrence (1-indexed)
        }

        return dp[n];
    }
};
```
