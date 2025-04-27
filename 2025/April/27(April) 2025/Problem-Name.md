# Multiply Two Strings

**Difficulty:** Medium  
**Accuracy:** 20.06%  
**Submissions:** 224K+  
**Points:** 4  
**Average Time:** 20 minutes

---

## Problem Statement

Given two numbers as strings `s1` and `s2`, calculate their product.

**Note:**
- The numbers can be negative.
- You are not allowed to use any built-in function to convert the strings directly to integers.
- There can be zeros at the beginning of the numbers.
- You don't need to specify the '+' sign in the beginning of positive numbers.

---

## Examples

### Example 1
**Input:**
```plaintext
s1 = "0033", s2 = "2"
```
**Output:**
```plaintext
66
```
**Explanation:**
```plaintext
33 * 2 = 66
```

### Example 2
**Input:**
```plaintext
s1 = "11", s2 = "23"
```
**Output:**
```plaintext
253
```
**Explanation:**
```plaintext
11 * 23 = 253
```

### Example 3
**Input:**
```plaintext
s1 = "123", s2 = "0"
```
**Output:**
```plaintext
0
```
**Explanation:**
```plaintext
Anything multiplied by 0 is equal to 0.
```

---

## Constraints
- 1 ≤ `s1.size()` ≤ 10³
- 1 ≤ `s2.size()` ≤ 10³

---

## Function Signature
```cpp
class Solution {
  public:
    string multiplyStrings(string& s1, string& s2);
};
```

---

## Approach

- Remove any leading zeros from both strings.
- Handle negative signs separately.
- Multiply each digit manually as per traditional multiplication.
- Manage carrying during the process.
- Construct the result string, taking care of leading zeros.
- Add a negative sign to the final result if needed.

---

## Template Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
        cout << "~" << "\n";
    }
    return 0;
}
```

