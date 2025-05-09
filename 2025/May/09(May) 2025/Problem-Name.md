# Problem: Largest Number in K Swaps

## Difficulty: Medium  
**Accuracy:** 18.84%  
**Submissions:** 117K+  
**Points:** 4  
**Average Time:** 30m

## Problem Statement
Given a number `k` and a string `s` of digits denoting a positive integer, build the **largest number** possible by performing **at most `k` swap operations** on the digits of `s`.

## Constraints
- 1 ≤ s.size() ≤ 15
- 1 ≤ k ≤ 7

## Input Format
- An integer `k`
- A string `s` representing the number

## Output Format
- A string representing the largest number possible after at most `k` swaps

## Examples

### Example 1
**Input:**  
s = "1234567", k = 4

**Output:**  
7654321

**Explanation:**  
Three swaps can make the input `1234567` into `7654321`:
- Swap 1 and 7
- Swap 2 and 6
- Swap 3 and 5

### Example 2
**Input:**  
s = "3435335", k = 3

**Output:**  
5543333

**Explanation:**  
Three swaps can make the input `3435335` into `5543333`:
- Swap 3 and 5
- Swap 4 and 5
- Swap 3 and 4

### Example 3
**Input:**  
s = "1034", k = 2

**Output:**  
4301

**Explanation:**  
Two swaps can make the input `1034` into `4301`:
- Swap 1 and 4
- Swap 0 and 3

## Approach
- Use backtracking to try all swap combinations up to `k` times.
- At each position `i`, find the largest digit from the subarray `s[i:]`.
- If a larger digit is found, swap it with `s[i]` and recurse with `k-1`.
- Keep track of the maximum string formed so far.

## Code (C++)
```cpp
class Solution {
  public:
    void findMaximum(string s, int k, string &maxStr, int idx) {
        if (k == 0) return;

        char maxDigit = s[idx];
        for (int i = idx + 1; i < s.length(); i++) {
            if (s[i] > maxDigit)
                maxDigit = s[i];
        }

        if (maxDigit != s[idx])
            k--;

        for (int i = s.length() - 1; i >= idx; i--) {
            if (s[i] == maxDigit) {
                swap(s[idx], s[i]);
                if (s.compare(maxStr) > 0)
                    maxStr = s;
                findMaximum(s, k, maxStr, idx + 1);
                swap(s[idx], s[i]);
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        string maxStr = s;
        findMaximum(s, k, maxStr, 0);
        return maxStr;
    }
};
```

---

Would you like Python or Java versions as well?
