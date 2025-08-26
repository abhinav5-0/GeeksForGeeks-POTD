# Check if a String is Subsequence of Other

**Difficulty:** Easy
**Accuracy:** 51.68%
**Submissions:** 29K+
**Points:** 2

---

## Problem Statement

Given two strings `s1` and `s2`. You have to check whether `s1` is a subsequence of `s2` or not.

**Note:** A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

---

## Examples

**Input:**
s1 = "AXY", s2 = "YADXCP"
**Output:**
false
**Explanation:**
s1 is not a subsequence of s2 as 'Y' appears before 'A'.

---

**Input:**
s1 = "gksrek", s2 = "geeksforgeeks"
**Output:**
true
**Explanation:**
If we combine the bold characters of "geeksforgeeks", it equals s1. So s1 is a subsequence of s2.

---

## Constraints

* 1 ≤ s1.size(), s2.size() ≤ 10^6

---

## Solution Approach

We can solve this problem using the **two-pointer technique**:

1. Initialize two pointers `i = 0` for `s1` and `j = 0` for `s2`.
2. Traverse through `s2`:

   * If `s1[i] == s2[j]`, move both `i` and `j` forward.
   * Otherwise, move only `j`.
3. If after traversal, `i == s1.size()`, then all characters of `s1` are found in sequence inside `s2`.

**Time Complexity:** O(n) where n = length of s2
**Space Complexity:** O(1)

---

## C++ Implementation

```cpp
class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0, j = 0;
        int n1 = s1.size(), n2 = s2.size();

        while (i < n1 && j < n2) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }

        return (i == n1); // true if all characters of s1 are matched
    }
};
```

---

## Dry Run Example

**s1 = "gksrek", s2 = "geeksforgeeks"**

* Matches: g → k → s → r → e → k ✅
* All characters found → return **true**

**s1 = "AXY", s2 = "YADXCP"**

* Only matches 'A', but 'Y' comes before 'A' in s2 → return **false**
