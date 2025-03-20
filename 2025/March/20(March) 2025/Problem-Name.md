# Stock Buy and Sell - Max 2 Transactions Allowed

## Problem Statement
In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

You are given an array `prices[]` representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy -> sell -> buy -> sell).

### Examples
#### Example 1:
**Input:**
```plaintext
prices[] = [10, 22, 5, 75, 65, 80]
```
**Output:**
```plaintext
87
```
**Explanation:**
- Buy at 10, sell at 22 → Profit = 22 - 10 = 12
- Buy at 5, sell at 80 → Profit = 80 - 5 = 75
- Total profit = 12 + 75 = 87

#### Example 2:
**Input:**
```plaintext
prices[] = [2, 30, 15, 10, 8, 25, 80]
```
**Output:**
```plaintext
100
```
**Explanation:**
- Buy at 2, sell at 30 → Profit = 30 - 2 = 28
- Buy at 8, sell at 80 → Profit = 80 - 8 = 72
- Total profit = 28 + 72 = 100

## Constraints
- `1 <= prices.size() <= 10^5`
- `1 <= prices[i] <= 10^5`

## Solution Approach
This problem can be solved using **Dynamic Programming** with an **O(n)** time complexity.

### Algorithm
1. **Left to Right Pass:** Compute the maximum profit from the first transaction.
2. **Right to Left Pass:** Compute the maximum profit from the second transaction.
3. **Combine Both Transactions:** Find the maximum sum of both profits.

## Code Implementation (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        vector<int> leftProfit(n, 0), rightProfit(n, 0);
        
        // First transaction (Left to Right)
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }
        
        // Second transaction (Right to Left)
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }
        
        // Calculate the maximum profit by combining two transactions
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }
        
        return maxProfit;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** `O(n)` (Single pass for both left and right computations)
- **Space Complexity:** `O(n)` (Used for storing left and right profit arrays, can be optimized to `O(1)`).

## Conclusion
This approach efficiently computes the maximum profit from at most two transactions while ensuring an optimal solution using dynamic programming techniques. 🚀
