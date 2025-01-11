# Longest Substring with Distinct Characters

This repository contains the implementation of a solution to find the length of the longest substring with all distinct characters. The problem uses an efficient **sliding window technique** and a hashmap to achieve optimal time complexity.

---

## Problem Statement

Given a string `s`, find the length of the longest substring that contains only distinct characters.

### Examples:

**Input:**  
`s = "geeksforgeeks"`  
**Output:**  
`7`  
**Explanation:**  
The substring `"eksforg"` is the longest substring with all distinct characters.

**Input:**  
`s = "aaa"`  
**Output:**  
`1`  
**Explanation:**  
The substring `"a"` is the longest substring with all distinct characters.

---

## Constraints

- \(1 \leq \text{s.size()} \leq 3 \times 10^4\)
- The string contains only lowercase English letters.

---

## Solution Logic

### Approach:
1. Use the **sliding window technique** with two pointers (`start` and `end`).
2. Maintain a **hashmap** to store the last seen index of each character.
3. If a character is repeated within the current window, move the `start` pointer to one position after the last occurrence of the character.
4. Update the length of the substring dynamically.
5. Return the maximum length found.

### Complexity:
- **Time Complexity:** \(O(n)\), where \(n\) is the length of the string.
- **Space Complexity:** \(O(k)\), where \(k\) is the size of the character set (constant for lowercase English letters).

---

## Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> last_seen;
        int max_len = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (last_seen.find(s[end]) != last_seen.end() && last_seen[s[end]] >= start) {
                start = last_seen[s[end]] + 1;
            }
            last_seen[s[end]] = end;
            max_len = max(max_len, end - start + 1);
        }

        return max_len;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
    }
    return 0;
}
