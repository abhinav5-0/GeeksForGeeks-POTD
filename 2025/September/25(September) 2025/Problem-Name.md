# Generate Binary Numbers

**Difficulty:** Easy  
**Accuracy:** 67.48%  
**Submissions:** 60K+  
**Points:** 2  

---

## Problem Statement
Given a number `n`. The task is to generate all binary numbers with decimal values from 1 to `n`.

### Examples

**Input:**  
n = 4  
**Output:**  
["1", "10", "11", "100"]  
**Explanation:** Binary numbers from 1 to 4 are 1, 10, 11 and 100.

**Input:**  
n = 6  
**Output:**  
["1", "10", "11", "100", "101", "110"]  
**Explanation:** Binary numbers from 1 to 6 are 1, 10, 11, 100, 101 and 110.

### Constraints
- 1 ≤ n ≤ 10^6

---

## Approach
We can generate binary numbers sequentially using a queue (BFS-style approach):
1. Start with `"1"` in the queue.
2. Pop the front string, add it to the result.
3. Push two new strings by appending `"0"` and `"1"` to the current string.
4. Repeat until `n` binary numbers are generated.

This ensures numbers are generated in increasing decimal order.

---

## Complexity Analysis
- **Time Complexity:** O(n * log n) → Each binary number is about O(log n) length.
- **Space Complexity:** O(n * log n) → For storing results and queue.

---

## C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        if (n <= 0) return res;
        res.reserve(n);

        queue<string> q;
        q.push("1");

        while ((int)res.size() < n) {
            string s = q.front(); q.pop();
            res.push_back(s);

            // generate next two binary numbers
            q.push(s + "0");
            q.push(s + "1");
        }

        return res;
    }
};

// Example usage (for local testing):
// int main() {
//     Solution sol;
//     int n = 6;
//     vector<string> ans = sol.generateBinary(n);
//     for (auto &b : ans) cout << b << '\n';
// }
