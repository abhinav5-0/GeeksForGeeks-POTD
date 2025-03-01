# Decode String

## Problem Statement
Given an encoded string `s`, decode it based on the following encoding rule:

```
k[encodedString]
```

where `encodedString` inside the square brackets is being repeated exactly `k` times. `k` is guaranteed to be a positive integer.

### Constraints:
- `1 ≤ |s| ≤ 10^5`
- The test cases ensure that the length of the output string will never exceed `10^5`.

## Examples

### Example 1
**Input:**
```
s = "1[b]"
```
**Output:**
```
b
```
**Explanation:** "b" is present only once.

### Example 2
**Input:**
```
s = "3[b2[ca]]"
```
**Output:**
```
bcacabcacabcaca
```
**Explanation:**
1. Inner substring `2[ca]` expands to `caca`.
2. Now the string becomes `3[bcaca]`.
3. Expanding `3[bcaca]` gives `bcacabcacabcaca`.

---

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int> numStack;
        string currStr = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // Constructing the number
            } else if (c == '[') {
                numStack.push(num);  // Store the repeat count
                strStack.push(currStr);  // Store the current string
                num = 0;
                currStr = "";
            } else if (c == ']') {
                int repeatCount = numStack.top(); numStack.pop();
                string temp = currStr;
                for (int i = 1; i < repeatCount; i++) {
                    currStr += temp;
                }
                currStr = strStack.top() + currStr;  // Concatenate with the previous stored string
                strStack.pop();
            } else {
                currStr += c;  // Build the current string
            }
        }
        return currStr;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
```

## Approach
1. **Use two stacks:**
   - `numStack` to store repeat counts.
   - `strStack` to store substrings before encountering `[`.
2. **Traverse the string:**
   - If the character is a digit, form the number.
   - If `[` is encountered, push `num` and `currStr` onto their respective stacks.
   - If `]` is encountered, pop values from stacks and construct the repeated substring.
   - Otherwise, keep adding characters to `currStr`.
3. **Return the final decoded string.**

## Complexity Analysis
- **Time Complexity:** `O(N)`, where `N` is the length of the string. Each character is processed at most twice (once pushed to stack and once popped).
- **Space Complexity:** `O(N)`, as we use stacks to store intermediate results.

---

## Summary
- The approach efficiently handles nested encodings using a stack-based method.
- It ensures correct expansion while keeping track of nested repetitions.

🚀 **Optimized and efficient!**
