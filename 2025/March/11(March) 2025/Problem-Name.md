# Ways to Reach the N'th Stair

## Problem Statement
There are `n` stairs, and a person standing at the bottom wants to reach the top. The person can climb either `1` stair or `2` stairs at a time. Your task is to count the number of ways the person can reach the top (order matters).

## Examples
### Example 1:
**Input:**
```cpp
n = 1
```
**Output:**
```cpp
1
```
**Explanation:** There is only one way to climb 1 stair: `{1}`.

### Example 2:
**Input:**
```cpp
n = 2
```
**Output:**
```cpp
2
```
**Explanation:** There are two ways to reach the 2nd stair: `{1, 1}` and `{2}`.

### Example 3:
**Input:**
```cpp
n = 4
```
**Output:**
```cpp
5
```
**Explanation:** There are five ways to reach the 4th stair:
- `{1, 1, 1, 1}`
- `{1, 1, 2}`
- `{2, 1, 1}`
- `{1, 2, 1}`
- `{2, 2}`

## Constraints
- `1 ≤ n ≤ 44`

## Approach
This problem follows the Fibonacci sequence because the person can reach the `n`th stair from either `(n-1)`th or `(n-2)`th stair.

### Recursive Formula
```
f(n) = f(n-1) + f(n-2)
```

### Optimized Dynamic Programming Solution (O(n) Time, O(1) Space)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countWays(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int prev2 = 1, prev1 = 2, curr;
        
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return curr;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl;
    }
    return 0;
}
```

## Explanation
1. **Base Cases:**
   - `f(1) = 1` (One way: `{1}`)
   - `f(2) = 2` (Two ways: `{1,1}` and `{2}`)
2. **Iterative DP Approach:**
   - Start with `prev2 = 1`, `prev1 = 2`
   - Loop from `3` to `n`, updating `curr = prev1 + prev2`
   - Update `prev2 = prev1` and `prev1 = curr`
3. **Final Output:** `curr` holds `f(n)`.

## Complexity Analysis
- **Time Complexity:** `O(n)`, since we iterate once.
- **Space Complexity:** `O(1)`, using only three integer variables.

## Example Walkthrough
**Input:** `n = 4`

**Steps:**
```
prev2 = 1, prev1 = 2
Iteration 3: curr = 1 + 2 = 3
Iteration 4: curr = 2 + 3 = 5
```

**Output:** `5`

