## LCM Triplet Problem

**Difficulty:** Medium  
**Accuracy:** 50.13%  
**Points:** 4

### Problem Statement
Given a number `n`, find the maximum possible **LCM** (Lowest Common Multiple) that can be obtained by selecting any three numbers less than or equal to `n`.

### Input:
- A single integer `n`

### Output:
- An integer representing the maximum LCM among all possible triplets with values ≤ `n`

### Constraints:
- 1 ≤ `n` ≤ 10^3

### Examples:
```
Input: 9
Output: 504
Explanation: Triplet {7, 8, 9} gives the LCM 504

Input: 7
Output: 210
Explanation: Triplet {5, 6, 7} gives the LCM 210
```

---

### Optimized C++ Solution
```cpp
class Solution {
public:
    int lcmTriplets(int n) {
        return n < 3 ? n :
               n & 1 ? n * (n - 1) * (n - 2) :             // n is odd
               n % 3 ? n * (n - 1) * (n - 3) :             // n is even and not divisible by 3
               (n - 1) * (n - 2) * (n - 3);                // n is even and divisible by 3
    }
};
```

### Explanation:
- If `n < 3`: Not enough numbers for a triplet.
- If `n` is odd: The triplet `{n, n-1, n-2}` are consecutive and usually coprime.
- If `n` is even:
  - If `n % 3 != 0`: Use `{n, n-1, n-3}` to avoid multiple common factors.
  - If `n % 3 == 0`: Use `{n-1, n-2, n-3}` to avoid common factors from both 2 and 3.

This approach ensures the maximum LCM in **constant time**.

---

### Time Complexity:
- **O(1)** — constant time operations only.

### Space Complexity:
- **O(1)** — no extra space used.
