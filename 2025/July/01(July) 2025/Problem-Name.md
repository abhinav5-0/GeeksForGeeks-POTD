## Problem: Substrings of Length `k` with `k-1` Distinct Elements

**Difficulty:** Medium  
**Accuracy:** 57.85%  
**Submissions:** 34K+  
**Points:** 4  
**Average Time:** 15m

---

### Problem Statement
Given a string `s` consisting of only lowercase alphabets and an integer `k`, find the count of all substrings of length `k` which have exactly `k-1` distinct characters.

---

### Input:
- A string `s` of lowercase English letters.  
- An integer `k`

### Output:
- An integer representing the number of substrings of length `k` with exactly `k-1` distinct characters.

---

### Constraints:
- $1 \leq s.length() \leq 10^5$
- $2 \leq k \leq 27$

---

### Examples:

#### Example 1:
**Input:**  
s = "abcc", k = 2  
**Output:**  
1  
**Explanation:**  
Possible substrings of length 2: "ab", "bc", "cc"
- "ab" has 2 distinct characters ❌
- "bc" has 2 distinct characters ❌
- "cc" has 1 distinct character ✅
Only one substring has exactly `k-1 = 1` distinct character.

#### Example 2:
**Input:**  
s = "aabab", k = 3  
**Output:**  
3  
**Explanation:**  
Possible substrings of length 3: "aab", "aba", "bab"
- All have exactly 2 distinct characters ✅
Answer = 3

---

### Function Signature
```cpp
class Solution {
  public:
    int substrCount(string &s, int k);
};
```

---

### Expected Time Complexity:
- **O(n)** where n is the length of the string

### Expected Space Complexity:
- **O(k)** for the frequency hashmap
