class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        vector<vector<int>> nxt(n, vector<int>(26, -1));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = last;
            last[s[i] - 'a'] = i;
        }
        vector<vector<int>> ch(26);
        for (auto &j : jumps) ch[j[0] - 'a'].push_back(j[1]);
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + s[i];
        vector<int> dp(n);
        for (int i = n - 2; i >= 0; i--) {
            for (int c : ch[s[i] - 'a']) {
                int j = nxt[i][c - 'a'];
                if (j != -1) dp[i] = max(dp[i], pre[j] - pre[i + (c == s[i])] + dp[j]);
            }
        }
        return dp[0];
    }
};
