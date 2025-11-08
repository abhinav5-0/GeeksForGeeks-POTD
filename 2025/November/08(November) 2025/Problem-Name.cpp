class Solution {
public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        // 3D DP: dp[i][j][s] = number of ways to reach (i, j) with sum s
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
        
        // Base case
        if (mat[0][0] <= k)
            dp[0][0][mat[0][0]] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int s = 0; s <= k; s++) {
                    if (s - mat[i][j] >= 0) {
                        if (i > 0)
                            dp[i][j][s] += dp[i - 1][j][s - mat[i][j]];
                        if (j > 0)
                            dp[i][j][s] += dp[i][j - 1][s - mat[i][j]];
                    }
                }
            }
        }
        
        return dp[n - 1][m - 1][k];
    }
};
