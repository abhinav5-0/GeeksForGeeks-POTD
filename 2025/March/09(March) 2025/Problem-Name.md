# Palindrome Substrings

## Problem Statement
Given a string `s`, count all palindromic substrings present in the string. The length of the palindromic substring must be greater than or equal to 2.

### Examples:
**Input:** `s = "abaab"`  
**Output:** `3`  
**Explanation:** Palindromic substrings: `"aba"`, `"aa"`, `"baab"`.

**Input:** `s = "aaa"`  
**Output:** `3`  
**Explanation:** Palindromic substrings: `"aa"`, `"aa"`, `"aaa"`.

**Input:** `s = "abbaeae"`  
**Output:** `4`  
**Explanation:** Palindromic substrings: `"bb"`, `"abba"`, `"aea"`, `"eae"`.

### Constraints:
- `2 ≤ s.size() ≤ 10^3`
- `s` consists of only lowercase English letters.

## Solution Approach
We use the **expand around center** approach to find all palindromic substrings efficiently. The idea is to expand outward from each character and each pair of consecutive characters, counting palindromes that meet the length condition.

### C++ Implementation:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) count++;
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     // Odd-length palindrome
            expandAroundCenter(i, i + 1); // Even-length palindrome
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
```

### Complexity Analysis
- **Time Complexity:** `O(n^2)`, as we expand around each character.
- **Space Complexity:** `O(1)`, since we only use a few integer variables.

### Explanation
1. We iterate through each character in the string.
2. We expand outward from each character (odd-length palindromes) and each pair of consecutive characters (even-length palindromes).
3. If a valid palindrome (length ≥ 2) is found, we increase the count.
4. The function finally returns the total count of such palindromic substrings.

This method ensures we efficiently find all palindromic substrings with minimal computational overhead. 🚀

