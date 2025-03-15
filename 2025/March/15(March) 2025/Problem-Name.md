# Coin Change (Minimum Coins)

## Problem Description

You are given an array `coins[]`, where each element represents a coin of a different denomination, and a target value `sum`. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}. 

Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return `-1`.

### Examples:

#### Example 1:
**Input**:
```cpp
coins[] = [25, 10, 5], sum = 30
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // Create a dp array to store the minimum coins for each sum from 0 to sum
        vector<int> dp(sum + 1, INT_MAX);
        
        // Base case: 0 coins needed to make sum 0
        dp[0] = 0;
        
        // Iterate through each coin
        for (int coin : coins) {
            // Update dp values for all sums from coin to sum
            for (int i = coin; i <= sum; i++) {
                if (dp[i - coin] != INT_MAX) { // If the previous sum can be made
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[sum] is still INT_MAX, return -1 (not possible to form the sum)
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
