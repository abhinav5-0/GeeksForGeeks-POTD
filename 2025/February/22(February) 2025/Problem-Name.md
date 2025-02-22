## Longest Valid Parentheses

### Problem Statement
Given a string `s` consisting of opening and closing parenthesis `(` and `)`, find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:
- For every opening parenthesis, there is a closing parenthesis.
- The closing parenthesis must be after its opening parenthesis.

### Examples:
#### Input:
```cpp
s = "((()"
```
#### Output:
```cpp
2
```
**Explanation:** The longest valid parenthesis substring is `"()"`.

#### Input:
```cpp
s = ")()())"
```
#### Output:
```cpp
4
```
**Explanation:** The longest valid parenthesis substring is `"()()"`.

#### Input:
```cpp
s = "())()"
```
#### Output:
```cpp
2
```
**Explanation:** The longest valid parenthesis substring is `"()"`.

---

### Constraints:
- `1 ≤ s.size() ≤ 10^6`
- `s` consists of `(` and `)` only.

### Solution Approach
We use a **stack-based approach** to efficiently track valid parentheses pairs.

### C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        st.push(-1); // Base index to calculate length
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // Update base index for next valid substring
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
```

### Explanation:
1. **Stack-based Approach:**
   - A stack is used to store indices of unmatched parentheses.
   - The base case `st.push(-1)` helps in calculating the length of valid substrings.
   - If `s[i] == '('`, push the index onto the stack.
   - If `s[i] == ')'`, pop the top of the stack:
     - If the stack is empty, push `i` as the new base index.
     - Otherwise, update `maxLen` as `i - st.top()`.

2. **Time Complexity:** \(O(N)\), since each character is processed once.

3. **Space Complexity:** \(O(N)\) in the worst case when all elements are pushed onto the stack.

This method ensures an optimal solution to the problem with minimal extra space. 🚀
