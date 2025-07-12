class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();         // Number of rows
        int m = mat[0].size();      // Number of columns

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the first column with the same values as mat
        for (int i = 0; i < n; i++) {
            dp[i][0] = mat[i][0];
        }

        // Build the DP table
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int upLeft = (i > 0) ? dp[i - 1][j - 1] : 0;
                int left = dp[i][j - 1];
                int downLeft = (i < n - 1) ? dp[i + 1][j - 1] : 0;

                dp[i][j] = mat[i][j] + max({upLeft, left, downLeft});
            }
        }

        // Find the maximum gold collected in the last column
        int maxGold = 0;
        for (int i = 0; i < n; i++) {
            maxGold = max(maxGold, dp[i][m - 1]);
        }

        return maxGold;
    }
};
