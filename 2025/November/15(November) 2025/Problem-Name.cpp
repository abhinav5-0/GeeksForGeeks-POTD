class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int k = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(k+2, vector<int>(k+2, 0));

        // len = interval length in terms of index (min gap=2 because gap=1 = no cut)
        for(int len = 2; len < k + 2; len++){
            for(int i = 0; i + len < k + 2; i++){
                int j = i + len;
                dp[i][j] = INT_MAX;

                for(int cut = i + 1; cut < j; cut++){
                    dp[i][j] = min(dp[i][j],
                                   dp[i][cut] + dp[cut][j] + cuts[j] - cuts[i]);
                }
            }
        }

        return dp[0][k+1];
    }
};
