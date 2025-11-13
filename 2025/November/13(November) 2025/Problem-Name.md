## Interleaved Strings

**Difficulty:** Medium
**Accuracy:** 24.33%
**Submissions:** 106K+
**Points:** 4
**Average Time:** 30m

### Problem Statement

Given strings `s1`, `s2`, and `s3`, determine whether `s3` is formed by an interleaving of `s1` and `s2`.

**Interleaving Definition:**
An interleaving of two strings `s1` and `s2` is a combination of their characters to form a new string `s3`, while maintaining the relative order of characters from both `s1` and `s2`.

**Conditions:**

1. Characters from `s1` must appear in `s3` in the same order as in `s1`.
2. Characters from `s2` must appear in `s3` in the same order as in `s2`.
3. The length of `s3` must be equal to the combined length of `s1` and `s2`.

### Examples

#### Example 1:

**Input:**
`s1 = "AAB"`, `s2 = "AAC"`, `s3 = "AAAABC"`
**Output:**
`true`
**Explanation:** The string "AAAABC" has all characters of the other two strings and in the same order.

#### Example 2:

**Input:**
`s1 = "AB"`, `s2 = "C"`, `s3 = "ACB"`
**Output:**
`true`
**Explanation:** s3 contains all characters of s1 and s2 and retains their relative order.

#### Example 3:

**Input:**
`s1 = "YX"`, `s2 = "X"`, `s3 = "XXY"`
**Output:**
`false`
**Explanation:** "XXY" cannot be formed while maintaining the order of characters in s1 and s2.

### Constraints

```
1 ≤ s1.length, s2.length ≤ 300
1 ≤ s3.length ≤ 600
```

---

### Approach

We can use **Dynamic Programming** to solve this efficiently.

Let `dp[i][j]` represent whether `s3[0...(i+j-1)]` can be formed by interleaving `s1[0...(i-1)]` and `s2[0...(j-1)]`.

**Recurrence Relation:**

```
dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
           (dp[i][j-1] && s2[j-1] == s3[i+j-1])
```

**Base Case:**

```
dp[0][0] = true
```

If both strings are empty, s3 must also be empty.

---

### C++ Implementation

```cpp
class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        
        if (n1 + n2 != n3) return false;

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;

        // Fill first row (only s2 used)
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // Fill first column (only s1 used)
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // Fill the rest of the table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                bool takeS1 = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                bool takeS2 = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                dp[i][j] = takeS1 || takeS2;
            }
        }

        return dp[n1][n2];
    }
};
```

---

### Complexity Analysis

* **Time Complexity:** O(n1 × n2)
* **Space Complexity:** O(n1 × n2)
  (Can be optimized to O(n2) using a 1D DP array)

---

### Example Walkthrough

**Input:**
`s1 = "AAB"`, `s2 = "AAC"`, `s3 = "AAAABC"`

**DP table progression:**

```
     A  A  C
   T  T  T  F
A  T  T  T  F
A  F  T  T  F
B  F  F  T  T
```

**Result:** dp[3][3] = true → `s3` is an interleaving of `s1` and `s2`.
