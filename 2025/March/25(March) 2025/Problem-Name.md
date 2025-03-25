# Boolean Parenthesization Problem

## Problem Statement
You are given a boolean expression `s` containing:
- 'T' → True
- 'F' → False

With the following operators:
- `&` (AND)
- `|` (OR)
- `^` (XOR)

Count the number of ways we can parenthesize the expression such that it evaluates to `True`.

### Constraints:
- `1 ≤ |s| ≤ 100`
- The answer is guaranteed to fit within a 32-bit integer.

## Examples

### Example 1:
**Input:**
```cpp
s = "T|T&F^T"
```
**Output:**
```
4
```
**Explanation:** The expression evaluates to true in 4 ways:
1. `((T|T)&(F^T))`
2. `(T|(T&(F^T)))`
3. `(((T|T)&F)^T)`
4. `(T|((T&F)^T))`

### Example 2:
**Input:**
```cpp
s = "T^F|F"
```
**Output:**
```
2
```
**Explanation:** The expression evaluates to true in 2 ways:
1. `((T^F)|F)`
2. `(T^(F|F))`

---

## Approach
We solve this problem using **Dynamic Programming with Memoization**.

### **Steps to Solve**
1. **Recursive Breakdown**
   - Each operator (`&`, `|`, `^`) partitions the string into left and right subexpressions.
   - Recursively compute the number of ways for `True` and `False` evaluations.

2. **Memoization (DP)**
   - Use a `unordered_map` to store computed results and avoid recomputation.
   
3. **Transition Relation**
   - Use the truth table for `AND`, `OR`, and `XOR` to compute possible outcomes.

---

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unordered_map<string, int> dp; // Memoization map

    int countWaysUtil(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0; // Invalid range
        if (i == j) { // Base case: single character
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];

        int ways = 0, MOD = 1000000007;

        for (int k = i + 1; k < j; k += 2) { // Operators are at odd indices
            int leftTrue = countWaysUtil(s, i, k - 1, true);
            int leftFalse = countWaysUtil(s, i, k - 1, false);
            int rightTrue = countWaysUtil(s, k + 1, j, true);
            int rightFalse = countWaysUtil(s, k + 1, j, false);

            if (s[k] == '&') {
                ways = (ways + (leftTrue * rightTrue) % MOD) % MOD;
            } else if (s[k] == '|') {
                ways = (ways + (leftTrue * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftFalse * rightTrue) % MOD) % MOD;
            } else if (s[k] == '^') {
                ways = (ways + (leftTrue * rightFalse) % MOD + (leftFalse * rightTrue) % MOD) % MOD;
            }
        }
        return dp[key] = ways;
    }

    int countWays(string &s) {
        dp.clear();
        return countWaysUtil(s, 0, s
