class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        int FULL = (1 << n) - 1;
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        dp[1][0] = 0;
        for (int mask = 1; mask <= FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) || dp[mask][i] == INT_MAX) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            if (dp[FULL][i] != INT_MAX)
                ans = min(ans, dp[FULL][i] + cost[i][0]);
        return ans;
    }
};
