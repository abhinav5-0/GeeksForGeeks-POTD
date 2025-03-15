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
