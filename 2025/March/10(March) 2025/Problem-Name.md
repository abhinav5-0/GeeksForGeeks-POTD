# Edit Distance Problem

## Problem Statement
Given two strings `s1` and `s2`, return the minimum number of operations required to convert `s1` to `s2`.

### Allowed Operations:
1. **Insert** a character.
2. **Remove** a character.
3. **Replace** a character.

## Examples:

### Example 1:
**Input:**
```cpp
s1 = "geek", s2 = "gesek"
```
**Output:**
```cpp
1
```
**Explanation:** Insert 's' between two 'e' in `s1`.

### Example 2:
**Input:**
```cpp
s1 = "abcd", s2 = "bcfe"
```
**Output:**
```cpp
3
```
**Explanation:** Remove ‘a’, replace ‘d’ with ‘f’, and insert ‘e’.

## Constraints:
- `1 ≤ s1.length(), s2.length() ≤ 1000`
- Both strings consist of lowercase letters.

---

## Solution Approach
We use **Dynamic Programming (Bottom-Up Approach)**:
- Define `dp[i][j]` as the minimum operations needed to convert `s1[0..i-1]` to `s2[0..j-1]`.
- **Transition:**
  - If `s1[i-1] == s2[j-1]`, no operation needed: `dp[i][j] = dp[i-1][j-1]`
  - Otherwise:
    1. Insert `s2[j-1]` → `dp[i][j] = 1 + dp[i][j-1]`
    2. Remove `s1[i-1]` → `dp[i][j] = 1 + dp[i-1][j]`
    3. Replace `s1[i-1]` with `s2[j-1]` → `dp[i][j] = 1 + dp[i-1][j-1]`
  - Take the **minimum** of these operations.

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
    }
    return 0;
}
```

---

## Complexity Analysis:
- **Time Complexity:** \( O(m \times n) \)
- **Space Complexity:** \( O(m \times n) \)

This solution efficiently computes the minimum operations required to convert one string into another. 🚀
