class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();                 // n = dimensions count → matrices are n-1
        int m = n - 1;                      // number of matrices

        // dp[i][j] = min cost to multiply matrices i...j
        vector<vector<long long>> dp(m, vector<long long>(m, 0));

        // bracket split points
        vector<vector<int>> split(m, vector<int>(m, -1));

        // L = chain length
        for (int L = 2; L <= m; L++) {
            for (int i = 0; i + L - 1 < m; i++) {
                int j = i + L - 1;
                dp[i][j] = LLONG_MAX;

                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] + 
                        1LL * arr[i] * arr[k+1] * arr[j+1];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        // Function to construct parentheses string
        function<string(int,int)> build = [&](int i, int j) {
            if (i == j) {
                return string(1, 'A' + i);   // single matrix → A, B, C...
            }
            int k = split[i][j];
            return "(" + build(i, k) + build(k + 1, j) + ")";
        };

        return build(0, m - 1);
    }
};
