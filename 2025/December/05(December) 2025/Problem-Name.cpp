class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        
        if (k == 0) return -1;
        if (k == 1) return n == 1 ? costs[0][0] : -1;

        vector<long long> dp(k, 0);

        // initialize dp for first row
        for (int j = 0; j < k; j++) dp[j] = costs[0][j];

        for (int i = 1; i < n; i++) {
            long long min1 = LLONG_MAX, min2 = LLONG_MAX;
            int idx1 = -1;

            // find min1, min2 in previous dp row
            for (int j = 0; j < k; j++) {
                if (dp[j] < min1) {
                    min2 = min1;
                    min1 = dp[j];
                    idx1 = j;
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                }
            }

            vector<long long> newdp(k, 0);

            for (int j = 0; j < k; j++) {
                if (j == idx1) 
                    newdp[j] = min2 + costs[i][j];
                else 
                    newdp[j] = min1 + costs[i][j];
            }

            dp = newdp;
        }

        long long ans = *min_element(dp.begin(), dp.end());
        return ans >= 1e18 ? -1 : ans;
    }
};
