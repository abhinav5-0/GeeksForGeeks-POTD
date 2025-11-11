## Shortest Common Supersequence

**Difficulty:** Medium
**Accuracy:** 55.62%
**Submissions:** 138K+
**Points:** 4

### Problem Statement

Given two strings `s1` and `s2`, find the **length of the smallest string** which has both `s1` and `s2` as its subsequences.

**Note:** `s1` and `s2` can have both uppercase and lowercase English letters.

---

### Examples

**Input:**
`s1 = "geek"`, `s2 = "eke"`
**Output:** `5`
**Explanation:** String `"geeke"` has both `"geek"` and `"eke"` as subsequences.

**Input:**
`s1 = "AGGTAB"`, `s2 = "GXTXAYB"`
**Output:** `9`
**Explanation:** String `"AGXGTXAYB"` has both `"AGGTAB"` and `"GXTXAYB"` as subsequences.

**Input:**
`s1 = "geek"`, `s2 = "ek"`
**Output:** `4`
**Explanation:** String `"geek"` has both `"geek"` and `"ek"` as subsequences.

---

### Constraints

`1 ≤ s1.size(), s2.size() ≤ 500`

---

### Approach

The problem can be efficiently solved using **Dynamic Programming**. The core idea is based on the **Longest Common Subsequence (LCS)** concept.

If we know the length of the LCS of `s1` and `s2`, the length of the **Shortest Common Supersequence (SCS)** is given by:

[ SCS = s1.length() + s2.length() - LCS(s1, s2) ]

This formula works because the common subsequence is counted twice (once in each string), so we subtract its length once.

---

### Steps

1. Compute the **LCS** using a DP table.
2. Use the formula above to calculate the **SCS length**.

---

### Code Implementation

```cpp
class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build LCS table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int lcsLen = dp[n][m];

        // Length of Shortest Common Supersequence
        return n + m - lcsLen;
    }
};
```

---

### Example Walkthrough

For `s1 = "geek"`, `s2 = "eke"`:

* **LCS = "ek"**, length = 2
* **SCS length = 4 + 3 - 2 = 5** ✅

Output → **5**

---

### Complexity Analysis

* **Time Complexity:** O(n × m)
* **Space Complexity:** O(n × m)

---

### Key Insight

The **Shortest Common Supersequence** problem is an extension of the **Longest Common Subsequence** problem.
Understanding LCS helps solve this problem efficiently using a bottom-up DP approach.
