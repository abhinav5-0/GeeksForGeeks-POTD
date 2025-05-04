## Problem: Smallest Distinct Window

**Difficulty:** Medium  
**Accuracy:** 31.85%  
**Points:** 4

### Problem Statement
Given a string `str`, find the length of the smallest window that contains **all the distinct characters** of the given string at least once.

### Examples
#### Example 1:
**Input:**
```
str = "aabcbcdbca"
```
**Output:**
```
4
```
**Explanation:**
Substring "dbca" has the smallest length that contains all the characters of str.

#### Example 2:
**Input:**
```
str = "aaab"
```
**Output:**
```
2
```
**Explanation:**
Substring "ab" has the smallest length that contains all the characters of str.

#### Example 3:
**Input:**
```
str = "geeksforgeeks"
```
**Output:**
```
8
```
**Explanation:**
There are multiple substrings with smallest length that contains all characters of str, such as "geeksfor" and "forgeeks".

### Constraints
- 1 ≤ `str.length()` ≤ 10⁵
- The string contains only lowercase English alphabets.

### Function Signature
```cpp
class Solution {
  public:
    int findSubString(string& str);
};
```

### Expected Time Complexity
- O(N), where N is the length of the string.

### Expected Auxiliary Space
- O(K), where K is the number of distinct characters in the string.
