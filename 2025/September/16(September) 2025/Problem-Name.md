# Postfix Evaluation

## Problem Statement
You are given an array of strings `arr[]` that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

### Note:
- A postfix expression is of the form **operand1 operand2 operator** (e.g., `a b +`).
- Division between two integers always computes the **floor value**, i.e., `floor(5 / 3) = 1` and `floor(-5 / 3) = -2`.
- The result of the expression and all intermediate calculations fit in a 32-bit signed integer.

### Examples
**Input:**
```
arr[] = ["2", "3", "1", "*", "+", "9", "-"]
```
**Output:**
```
-4
```
**Explanation:**
Converted to infix: `2 + (3 * 1) – 9 = 5 – 9 = -4`

**Input:**
```
arr[] = ["2", "3", "^", "1", "+"]
```
**Output:**
```
9
```
**Explanation:**
Converted to infix: `2 ^ 3 + 1 = 8 + 1 = 9`

---

## Constraints
- 3 ≤ arr.size() ≤ 10^3
- `arr[i]` is either an operator: `+`, `-`, `*`, `/`, `^`, or an integer in the range [-10^4, 10^4].

---

## Approach
1. Use a **stack** to evaluate postfix expressions.
2. Traverse each element in `arr`:
   - If it’s a **number**, push it to the stack.
   - If it’s an **operator**:
     - Pop the top two numbers (`b`, then `a`).
     - Apply `a operator b`.
     - Push the result back to the stack.
3. At the end, the stack will contain the final result.

### Operator Handling
- `+ → a + b`
- `- → a - b`
- `* → a * b`
- `/ → floor division (handle negatives carefully)`
- `^ → pow(a, b)`

---

## C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        
        for (auto &token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;
                
                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = a * b;
                else if (token == "/") {
                    if ((a < 0) ^ (b < 0)) {
                        res = floor((double)a / b);
                    } else {
                        res = a / b;
                    }
                }
                else if (token == "^") res = pow(a, b);
                
                st.push(res);
            }
            else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};
```

---

## Example Walkthrough
Input:
```
arr = ["2", "3", "1", "*", "+", "9", "-"]
```
Steps:
- Push 2, 3, 1
- Operator `*` → (3*1)=3 → push 3
- Operator `+` → (2+3)=5 → push 5
- Push 9
- Operator `-` → (5-9)=-4 → push -4

✅ Final result = **-4**
