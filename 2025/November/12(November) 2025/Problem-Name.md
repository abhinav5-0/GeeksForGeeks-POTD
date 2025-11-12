## Wildcard Pattern Matching

**Difficulty:** Medium
**Accuracy:** 31.13%
**Points:** 4

### Problem Statement

Given two strings `pat` and `txt` which may be of different sizes, return `true` if the wildcard pattern `pat` matches with `txt`, else return `false`.

The wildcard pattern `pat` can include the characters `?` and `*`.

* `?` – matches any single character.
* `*` – matches any sequence of characters (including the empty sequence).

**Note:** The matching should cover the entire `txt` (not partial `txt`).

---

### Examples

#### Example 1

**Input:**
`txt = "abcde"`, `pat = "a?c*"`

**Output:**
`true`

**Explanation:**
`?` matches with `'b'` and `*` matches with `'de'`.

---

#### Example 2

**Input:**
`txt = "baaabab"`, `pat = "a*ab"`

**Output:**
`false`

**Explanation:**
The pattern starts with `'a'`, but the text starts with `'b'`, so it does not match.

---

#### Example 3

**Input:**
`txt = "abc"`, `pat = "*"`

**Output:**
`true`

**Explanation:**
`*` matches the whole text `'abc'`.

---

### Constraints

* `1 ≤ txt.size(), pat.size() ≤ 100`

---

### Approach

We use **Dynamic Programming (DP)** to solve this problem efficiently.

Let `dp[i][j]` represent whether the first `i` characters of `pat` match the first `j` characters of `txt`.

#### Steps:

1. Initialize a 2D DP table `dp[n+1][m+1]` where `n = pat.size()` and `m = txt.size()`.
2. `dp[0][0] = true` since empty pattern matches empty text.
3. For patterns starting with `*`, set `dp[i][0] = dp[i-1][0]` because `*` can match an empty string.
4. Fill the table:

   * If `pat[i-1] == txt[j-1]` or `pat[i-1] == '?'` → `dp[i][j] = dp[i-1][j-1]`
   * If `pat[i-1] == '*'` → `dp[i][j] = dp[i-1][j] || dp[i][j-1]`
   * Else → `dp[i][j] = false`

Finally, return `dp[n][m]`.

---

### Code Implementation

```cpp
class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        int n = pat.size();
        int m = txt.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        dp[0][0] = true; // Empty pattern matches empty text

        // Handle patterns starting with '*'
        for (int i = 1; i <= n; i++) {
            if (pat[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[i - 1] == txt[j - 1] || pat[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
```

---

### Example Walkthrough

**Input:**

```
txt = "abcde"
pat = "a?c*"
```

| Pattern | Text | Match Explanation               |
| ------- | ---- | ------------------------------- |
| a       | a    | Matches                         |
| ?       | b    | '?' matches any single char     |
| c       | c    | Matches                         |
| *       | de   | '*' matches any sequence ('de') |

✅ Final Result: `true`

---

### Complexity Analysis

* **Time Complexity:** O(n × m)
* **Space Complexity:** O(n × m)

---

### Optimization

We can optimize space to O(m) using two 1D arrays since each state only depends on the previous row.
