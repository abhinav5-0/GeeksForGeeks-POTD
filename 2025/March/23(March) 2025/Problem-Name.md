# Total Decoding Messages

## Problem Statement
A message containing letters **A-Z** is encoded using the following mapping:

```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

You are given a string `digits` containing only numeric characters (`0-9`). Your task is to determine the total number of ways that the message can be decoded.

### Constraints:
- **1 ≤ digits.length() ≤ 1003**
- The input string will not be empty.

---

## Example Cases

### Example 1:
**Input:**
```
digits = "123"
```
**Output:**
```
3
```
**Explanation:**
```
"123" can be decoded as "ABC" (1,2,3), "LC" (12,3), and "AW" (1,23).
```

### Example 2:
**Input:**
```
digits = "90"
```
**Output:**
```
0
```
**Explanation:**
```
"90" cannot be decoded, as '0' alone is not valid.
```

### Example 3:
**Input:**
```
digits = "05"
```
**Output:**
```
0
```
**Explanation:**
```
"05" is not valid due to the leading zero.
```

---

## Approach
We use **Dynamic Programming (DP)** to solve this problem efficiently.

### Steps:
1. **Base Cases**:
   - If the string starts with '0', return `0` (invalid encoding).
   - If the length is `1` and not '0', return `1`.
2. **Define a `dp` array**, where `dp[i]` represents the number of ways to decode the first `i` characters.
3. **Transition:**
   - If `digits[i-1]` is non-zero, add `dp[i-1]` (single-digit decode).
   - If `digits[i-2]` and `digits[i-1]` form a valid two-digit number (between `10-26`), add `dp[i-2]`.
4. **Return `dp[n]`**, where `n = digits.length()`.

---

## Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int oneDigit = digits[i - 1] - '0';
            int twoDigits = (digits[i - 2] - '0') * 10 + oneDigit;
            
            if (oneDigit >= 1) {
                dp[i] += dp[i - 1];
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

// Driver Code
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";
    }
    return 0;
}
```

---

## Complexity Analysis
- **Time Complexity**: `O(n)`, since we traverse the string once.
- **Space Complexity**: `O(n)`, due to the `dp` array.

---

## Setup and Execution
### Prerequisites
- C++ compiler (`g++` recommended)

### Compilation & Execution
```sh
g++ -o decode decode.cpp  # Compile
./decode                   # Run
```

### Running with Input
```sh
Input:
123
Output:
3
```

---

---

## Author
Abhinav Kumar

