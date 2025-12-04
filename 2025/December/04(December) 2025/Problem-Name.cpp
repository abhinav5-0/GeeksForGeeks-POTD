class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        if (n == 0) return 0;

        // dp[i][j] = min cost of optimal BST using keys from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // prefix sum of frequencies for O(1) range sum
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + freq[i];
        }
        auto rangeSum = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };

        // length = 1: cost is just its own frequency (depth = 1)
        for (int i = 0; i < n; ++i) {
            dp[i][i] = freq[i];
        }

        // consider chains of length 2..n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                int fsum = rangeSum(i, j);

                for (int r = i; r <= j; ++r) {
                    int left  = (r > i) ? dp[i][r - 1] : 0;
                    int right = (r < j) ? dp[r + 1][j] : 0;
                    int cost = left + right + fsum;
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};
