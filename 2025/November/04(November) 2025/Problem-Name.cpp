class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0); // dp[i] = minimum cost to reach stair i
        
        dp[0] = 0; // Starting point, no cost
        
        for (int i = 1; i < n; ++i) {
            int oneStep = dp[i-1] + abs(height[i] - height[i-1]);
            int twoStep = (i > 1) ? dp[i-2] + abs(height[i] - height[i-2]) : INT_MAX;
            dp[i] = min(oneStep, twoStep);
        }
        
        return dp[n-1];
    }
};
