# Stock Buy and Sell - Max K Transactions Allowed

## Problem Statement
In the stock market, a person buys a stock and sells it on some future date. Given an array `prices[]` representing stock prices on different days and a positive integer `k`, find the maximum profit a person can make with at most `k` transactions.

A transaction consists of buying and subsequently selling a stock. A new transaction can only start after the previous transaction has been completed.

### Example
#### **Input 1:**
```plaintext
prices[] = [10, 22, 5, 80], k = 2
```
#### **Output 1:**
```plaintext
87
```
#### **Explanation:**
1st transaction: Buy at 10 and sell at 22. 
2nd transaction: Buy at 5 and sell at 80. 
Total Profit = 12 + 75 = **87**.

#### **Input 2:**
```plaintext
prices[] = [20, 580, 420, 900], k = 3
```
#### **Output 2:**
```plaintext
1040
```
#### **Explanation:**
1st transaction: Buy at 20 and sell at 580.
2nd transaction: Buy at 420 and sell at 900. 
Total Profit = 560 + 480 = **1040**.

## Approach
We use **Dynamic Programming (DP)** to solve this problem efficiently. The DP table `dp[i][j]` stores the maximum profit achievable with at most `i` transactions up to the `j`-th day.

### **State Transition Formula:**
```cpp
dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
```
where
```cpp
maxDiff = max(maxDiff, dp[i-1][m] - prices[m]);
```
maintains the best day to buy.

### **Optimized Approach:**
- If `k >= n/2`, we treat it as an **unlimited transactions** problem.
- Otherwise, use **DP with optimized space** to compute results in `O(k * n)` time complexity.

## Installation & Usage
### **1. Clone the Repository**
```sh
git clone https://github.com/yourusername/stock-buy-sell-k.git
cd stock-buy-sell-k
```

### **2. Compile & Run**
#### **Using g++ Compiler**
```sh
g++ -o stock stock_buy_sell_k.cpp
./stock
```
#### **Example Execution**
```sh
Input:
1
4
10 22 5 80
2

Output:
87
```

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0) return 0;

        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        cin >> k;

        Solution ob;
        cout << ob.maxProfit(prices, k) << endl;
    }
    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** `O(k * n)`
- **Space Complexity:** `O(k * n)`, can be optimized to `O(n)`

## Contribution
Contributions are welcome! To contribute:
1. Fork the repos
