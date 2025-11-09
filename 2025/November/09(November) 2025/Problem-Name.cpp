class Solution {
public:
    int n;
    int dp[51][51][51];

    int solve(vector<vector<int>>& mat, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) return -1e9;
        if (mat[r1][c1] == -1 || mat[r2][c2] == -1) return -1e9;
        if (r1 == n - 1 && c1 == n - 1) return mat[r1][c1];

        if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];

        int ans = mat[r1][c1];
        if (c1 != c2) ans += mat[r2][c2];

        int temp = max({
            solve(mat, r1 + 1, c1, c2),       // down, down
            solve(mat, r1, c1 + 1, c2),       // right, down
            solve(mat, r1 + 1, c1, c2 + 1),   // down, right
            solve(mat, r1, c1 + 1, c2 + 1)    // right, right
        });

        ans += temp;
        return dp[r1][c1][c2] = ans;
    }

    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size();
        memset(dp, -1, sizeof(dp));
        int res = solve(mat, 0, 0, 0);
        return max(0, res);
    }
};
