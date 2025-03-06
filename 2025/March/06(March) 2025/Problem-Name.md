# Longest Common Subsequence (LCS)

## Problem Statement
Given two strings `s1` and `s2`, return the length of their longest common subsequence (LCS). If there is no common subsequence, return `0`.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements.

## Examples
**Input 1:**
```
s1 = "ABCDGH"
s2 = "AEDFHR"
```
**Output:** `3`
**Explanation:** The longest common subsequence is "ADH".

**Input 2:**
```
s1 = "ABC"
s2 = "AC"
```
**Output:** `2`
**Explanation:** The longest common subsequence is "AC".

**Input 3:**
```
s1 = "XYZW"
s2 = "XYWZ"
```
**Output:** `3`
**Explanation:** The longest common subsequences are "XYZ" and "XYW".

---

## Constraints
- `1 ≤ s1.size(), s2.size() ≤ 1000`
- Both strings `s1` and `s2` contain only uppercase English letters.

## Solution Approach
We use **Dynamic Programming** (Bottom-Up Approach) to solve the problem efficiently.

### **Algorithm:**
1. Create a `2D DP table dp[n+1][m+1]`, where `dp[i][j]` stores the length of LCS of `s1[0...i-1]` and `s2[0...j-1]`.
2. Initialize `dp[i][0] = 0` and `dp[0][j] = 0` since LCS with an empty string is 0.
3. Traverse both strings and fill the DP table:
   - If `s1[i-1] == s2[j-1]`, then `dp[i][j] = 1 + dp[i-1][j-1]`.
   - Otherwise, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
4. The final answer is `dp[n][m]`.

---

## **C++ Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.lcs(s1, s2) << endl;
    }
    return 0;
}
```

---

## **Complexity Analysis**
- **Time Complexity:** `O(n * m)`, where `n` and `m` are the lengths of `s1` and `s2`.
- **Space Complexity:** `O(n * m)` (Can be optimized to `O(min(n, m))` using space-efficient DP).

## **Optimizations**
- We can use **memoization (top-down)** to improve space efficiency.
- Using **rolling arrays** can reduce space complexity to `O(min(n, m))`.

Let me know if you need further optimizations! 🚀
