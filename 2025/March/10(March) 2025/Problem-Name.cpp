class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // If s1 is empty, insert all characters of s2
                if (i == 0) dp[i][j] = j;
                // If s2 is empty, remove all characters of s1
                else if (j == 0) dp[i][j] = i;
                // If last characters are the same, no operation needed
                else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Minimum of Insert, Remove, Replace
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};
