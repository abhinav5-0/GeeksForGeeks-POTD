# Postfix Expression Evaluation

This repository contains a solution for evaluating arithmetic expressions written in Reverse Polish Notation (Postfix notation). The problem involves evaluating an expression and returning the result as an integer. The solution is implemented in C++.

## Problem Statement

Given an array of strings `arr` that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation), the task is to evaluate the expression and return an integer representing its value.

### Supported Operators
- `+` (Addition)
- `-` (Subtraction)
- `*` (Multiplication)
- `/` (Integer Division, rounding towards zero)

### Constraints
- The input is guaranteed to be a valid arithmetic expression in Reverse Polish Notation.
- The operands are integers in the range [-10^4, 10^4].
- No division by zero will occur.
- The result of the expression will fit within a 32-bit signed integer.

### Code Implementation

```
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                if (token == "+") {
                    st.push(a + b);
                } else if (token == "-") {
                    st.push(a - b);
                } else if (token == "*") {
                    st.push(a * b);
                } else if (token == "/") {
                    st.push(a / b);
                }
            } else {
                st.push(stoi(token));  // Convert string to integer and push to stack
            }
        }
        
        return st.top();  // The result is the only element left in the stack
    }
};

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
```
