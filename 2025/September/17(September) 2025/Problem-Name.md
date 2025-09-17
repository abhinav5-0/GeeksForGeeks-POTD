# Decode the String

**Difficulty:** Medium  
**Accuracy:** 44.28%  
**Submissions:** 67K+  
**Points:** 4  
**Average Time:** 10m

---

## Problem Statement
Given an encoded string `s`, decode it by expanding the pattern `k[substring]`, where the substring inside brackets is written `k` times. `k` is guaranteed to be a positive integer, and `encodedString` contains only lowercase English alphabets. Return the final decoded string.

**Note:** The test cases are generated so that the length of the output string will never exceed `10^5`.

---

## Examples

### Example 1
**Input:**  
s = "3[b2[ca]]"

**Output:**  
"bcacabcacabcaca"

**Explanation:**  
- Inner substring `2[ca]` expands to `caca`.  
- Now, new string becomes `3[bcaca]`.  
- Finally, `3[bcaca]` expands to `bcacabcacabcaca`.

---

### Example 2
**Input:**  
s = "3[ab]"

**Output:**  
"ababab"

**Explanation:**  
Substring `ab` repeated 3 times gives `ababab`.

---

## Constraints
- 1 ≤ |s| ≤ 10^5  
- 1 ≤ k ≤ 100  

---

## Approach
We solve this using **two stacks**:
- `countStack` → stores multipliers (`k`)
- `stringStack` → stores partial decoded strings before encountering `]`

### Steps:
1. Traverse the string character by character.  
2. If the character is a **digit**, compute the full number `k`.  
3. If `[` is found, push the current string into `stringStack` and reset it. Also push `k` into `countStack`.  
4. If `]` is found, pop from stacks, expand the substring `k` times, and append to the previous string.  
5. Otherwise, append alphabets directly to the current string.  
6. At the end, `currentString` will contain the decoded string.

---

## C++ Implementation
```cpp
class Solution {
public:
    string decodedString(string &s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); // build the number
            }
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                k = 0;
                currentString = "";
            }
            else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string prevString = stringStack.top(); stringStack.pop();
                string expanded = "";
                for (int i = 0; i < repeat; i++) {
                    expanded += currentString;
                }
                currentString = prevString + expanded;
            }
            else {
                currentString += c;
            }
        }
        return currentString;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** O(n), where n = length of the string (each character processed once).
- **Space Complexity:** O(n), for stacks storing partial results.

---
