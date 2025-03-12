## Min Cost Climbing Stairs

### Problem Statement
Given an array of integers `cost[]` where `cost[i]` is the cost of the `i-th` step on a staircase. Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.

Assume **0-based indexing**. You can either start from the step with index `0`, or the step with index `1`.

### Examples

#### Example 1
**Input:**
```cpp
cost[] = [10, 15, 20]
```
**Output:**
```cpp
15
```
**Explanation:**
The cheapest option is to start at `cost[1]`, pay that cost, and go to the top.

#### Example 2
**Input:**
```cpp
cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
```
**Output:**
```cpp
6
```
**Explanation:**
The cheapest option is to start on `cost[0]`, and only step on `1s`, skipping `cost[3]`.

---

### Constraints
- `2 ≤ cost.size() ≤ 10^5`
- `0 ≤ cost[i] ≤ 999`

---

### Solution Approach
We solve this problem using **Dynamic Programming**:
- Define `dp[i]` as the minimum cost to reach the `i-th` step.
- The base cases:
  - `dp[0] = 0` (starting before step 0)
  - `dp[1] = 0` (starting before step 1)
- Recurrence relation:
  ```cpp
  dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
  ```
- The final result is stored in `dp[n]`, which represents the minimum cost to reach the top.

---

### Code Implementation
```cpp
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        return dp[n];
    }
};
```

---

### Time Complexity
- **O(n)** because we iterate through the array once.
- **O(n) space** due to storing the `dp` array.

#### Optimization:
- We can reduce space complexity to **O(1)** using two variables instead of a full `dp` array.

Let me know if you want a space-optimized version! 🚀

