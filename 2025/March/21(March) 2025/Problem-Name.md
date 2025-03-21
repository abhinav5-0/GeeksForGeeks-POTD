# Stickler Thief

## Problem Statement
Stickler the thief wants to loot money from houses arranged in a line. However, he cannot loot two consecutive houses and aims to maximize his total loot.

Given an array `arr[]` where `arr[i]` represents the amount of money in the `i-th` house, determine the maximum amount he can loot.

## Examples
### Example 1:
**Input:**  
```
arr[] = [6, 5, 5, 7, 4]
```
**Output:**  
```
15
```
**Explanation:** Maximum amount he can get by looting the 1st, 3rd, and 5th house: `6 + 5 + 4 = 15`.

### Example 2:
**Input:**  
```
arr[] = [1, 5, 3]
```
**Output:**  
```
5
```
**Explanation:** Loot only the 2nd house to get the maximum amount of `5`.

### Example 3:
**Input:**  
```
arr[] = [4, 4, 4, 4]
```
**Output:**  
```
8
```
**Explanation:** The optimal choice is to loot every alternate house. Either loot the 1st and 3rd houses or the 2nd and 4th. Both yield `4 + 4 = 8`.

## Constraints
- \(1 \leq \text{arr.size()} \leq 10^5\)
- \(1 \leq arr[i] \leq 10^4\)

## Approach
The problem follows the **Dynamic Programming (DP)** paradigm. We use a **bottom-up** approach:

1. Define `dp[i]` as the maximum loot possible up to the `i`-th house.
2. The recurrence relation:
   
   \[
   dp[i] = \max(dp[i-1], arr[i] + dp[i-2])
   \]
   
   - **Skip** the current house → `dp[i-1]`
   - **Loot** the current house → `arr[i] + dp[i-2]`

3. Optimize space by maintaining only two variables (`prev1` and `prev2`).

## Optimized C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev2 = 0, prev1 = 0, curr = 0;
        
        for (int i = 0; i < n; i++) {
            curr = max(prev1, arr[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {6, 5, 5, 7, 4};
    cout << sol.findMaxSum(arr) << endl; // Output: 15
    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** \(O(n)\) (Single pass through the array)
- **Space Complexity:** \(O(1)\) (Only three variables used)

This optimized approach efficiently determines the maximum amount the thief can loot! 🚀

