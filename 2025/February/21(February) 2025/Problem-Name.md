# Parenthesis Checker

## Problem Description

Given a string `s` composed of different combinations of '(', ')', '{', '}', '[', ']', verify the validity of the arrangement.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

## Difficulty
Easy

## Problem Statement

Implement the `isBalanced` function that takes a string `s` as input and returns a boolean indicating whether the parentheses in the string are balanced.

### Function Signature

```cpp
class Solution {
public:
    bool isBalanced(string& s);
};
```

### Input
- A string `s` containing characters '(', ')', '{', '}', '[', ']'

### Output
- Return `true` if the parentheses are balanced, `false` otherwise.

## Constraints
- 1 ≤ s.size() ≤ 10^6
- s[i] ∈ {'{', '}', '(', ')', '[', ']'}

## Examples

### Example 1
```
Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.
```

### Example 2
```
Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.
```

### Example 3
```
Input: s = "([]"
Output: false
Explanation: The expression is not balanced as there is a missing ')' at the end.
```

### Example 4
```
Input: s = "([{]})"
Output: false
Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.
```

## Solution

```cpp
class Solution {
public:
    bool isBalanced(string& s) {
        stack st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                st.pop();
                
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
```

## Explanation

The solution uses a stack to keep track of opening brackets. It iterates through each character in the input string:

1. If it's an opening bracket, push it onto the stack.
2. If it's a closing bracket:
   - If the stack is empty, return false (unmatched closing bracket).
   - Pop the top element from the stack.
   - If the current closing bracket doesn't match the popped opening bracket, return false.
3. After processing all characters, return true if the stack is empty (all brackets matched), false otherwise.

## Complexity Analysis

- Time Complexity: O(n), where n is the length of the input string.
- Space Complexity: O(n) in the worst case, where all characters are opening brackets.

