class Solution {
  public:
    int getCount(int n) {
        if (n == 1) return 10;

        vector<vector<int>> moves = {
            {0, 8},    // 0
            {1, 2, 4}, // 1
            {2, 1, 3, 5},
            {3, 2, 6},
            {4, 1, 5, 7},
            {5, 2, 4, 6, 8},
            {6, 3, 5, 9},
            {7, 4, 8},
            {8, 5, 7, 9, 0},
            {9, 6, 8}
        };

        vector<vector<long long>> dp(10, vector<long long>(n + 1, 0));

        // Base case: sequences of length 1
        for (int i = 0; i <= 9; i++) {
            dp[i][1] = 1;
        }

        // Build the DP table
        for (int len = 2; len <= n; len++) {
            for (int digit = 0; digit <= 9; digit++) {
                for (int next : moves[digit]) {
                    dp[digit][len] += dp[next][len - 1];
                }
            }
        }

        // Sum all sequences of length n starting from any digit
        long long total = 0;
        for (int i = 0; i <= 9; i++) {
            total += dp[i][n];
        }

        return total;
    }
};
