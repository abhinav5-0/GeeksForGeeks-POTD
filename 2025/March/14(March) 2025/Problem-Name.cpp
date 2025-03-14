class Solution {
public:
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;  // Base case: One way to make sum = 0 (by taking nothing)

        for (int coin : coins) {  // Iterate over each coin
            for (int j = coin; j <= sum; j++) {
                dp[j] += dp[j - coin];  // Include current coin
            }
        }

        return dp[sum];
    }
};
