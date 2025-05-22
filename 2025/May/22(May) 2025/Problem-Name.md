# Minimum Deletions to Make a String Palindrome

## Problem Statement

Given a string `s`, write a program to delete the **minimum number of characters** from the string so that the resultant string is a **palindrome**, while maintaining the **original order of characters**.

### Input:

* A single string `s` of length `n`.

### Output:

* An integer representing the **minimum number of deletions** required to make the string a palindrome.

### Constraints:

* `1 ≤ s.length ≤ 10^3`

## Examples

### Example 1:

**Input:**

```
s = "aebcbda"
```

**Output:**

```
2
```

**Explanation:**
Removing characters 'e' and 'd' gives "abcba", which is a palindrome.

### Example 2:

**Input:**

```
s = "geeksforgeeks"
```

**Output:**

```
8
```

**Explanation:**
The longest palindromic subsequence is "eegee" or similar (length 5).
Minimum deletions = 13 (original length) - 5 = 8.

## Approach

To solve this problem, we find the **Longest Palindromic Subsequence (LPS)** in the string. The minimum deletions required will be:

```
Minimum Deletions = Length of s - Length of LPS
```

This can be efficiently computed using **Dynamic Programming** by finding the **Longest Common Subsequence (LCS)** between the string `s` and its reverse.

## C++ Implementation

```cpp
class Solution {
  public:
    int minDeletions(string s) {
        int n = s.length();
        string rev = string(s.rbegin(), s.rend());

        // dp[i][j] = LCS of s[0..i-1] and rev[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lps = dp[n][n];
        return n - lps; // Minimum deletions
    }
};
```

## Tags

* Dynamic Programming
* String
* Palindrome
* Longest Palindromic Subsequence
