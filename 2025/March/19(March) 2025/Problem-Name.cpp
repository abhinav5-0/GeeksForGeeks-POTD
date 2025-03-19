class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0) return 0;

        // If k >= n/2, it's the unlimited transaction case
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }

        // DP table
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0]; // Max profit possible with buying on day 0
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};
