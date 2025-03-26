class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> u(d.begin(), d.end());
        int n = s.size(), m = 0;
        for(auto &w : d) m = max(m, (int)w.size());
        vector<bool> dp(n + 1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(!dp[i]) continue;
            for(int j = 1; j <= m && i + j <= n; j++)
                if(u.count(s.substr(i, j))) dp[i + j] = 1;
        }
        return dp[n];
    }
};
