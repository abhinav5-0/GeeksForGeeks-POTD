# LCS of Three Strings

**Difficulty:** Medium
**Accuracy:** 48.52%
**Submissions:** 80K+
**Points:** 4

## Problem Statement

Given three strings `s1`, `s2`, and `s3` containing uppercase letters, lowercase letters, and digits, find the length of the longest common subsequence (LCS) present in all three given strings.

### Examples

**Input:**
s1 = "geeks"
s2 = "geeksfor"
s3 = "geeksforgeeks"
**Output:**
5
**Explanation:**
"geeks" is the longest common subsequence with length 5.

**Input:**
s1 = "abcd1e2"
s2 = "bc12ea"
s3 = "bd1ea"
**Output:**
3
**Explanation:**
Longest common subsequence is "b1e", hence length = 3.

### Constraints

* 1 ≤ `s1.size()`, `s2.size()`, `s3.size()` ≤ 100

## C++ Function Signature

```cpp
class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3);
};
```

## Approach

Use **3D Dynamic Programming** to store results of subproblems:

* Define a 3D array `dp[i][j][k]` where `dp[i][j][k]` stores the LCS of prefixes `s1[0..i-1]`, `s2[0..j-1]`, `s3[0..k-1]`
* **Recurrence Relation**:

  * If characters match: `dp[i][j][k] = 1 + dp[i-1][j-1][k-1]`
  * Else: `dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])`

## Full Implementation

```cpp
class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int dp[n1 + 1][n2 + 1][n3 + 1];

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                for (int k = 0; k <= n3; k++) {
                    if (i == 0 || j == 0 || k == 0)
                        dp[i][j][k] = 0;
                    else if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    else
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }

        return dp[n1][n2][n3];
    }
};
```

## Time Complexity

* **O(n1 × n2 × n3)** where n1, n2, n3 are the lengths of the input strings.

## Space Complexity

* **O(n1 × n2 × n3)** (can be optimized using 2 layers of DP with rolling arrays)

## Tags

* Dynamic Programming
* Strings
* 3D DP
