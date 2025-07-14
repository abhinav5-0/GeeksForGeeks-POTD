class Solution {
  public:
    bool isPowerOfFive(string &s) {
        if (s[0] == '0') return false; // No leading zeros allowed
        long long num = 0;
        for (char c : s) {
            num = num * 2 + (c - '0');
        }
        if (num == 0) return false;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }

    int cuts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);
                if (isPowerOfFive(sub)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] >= 1e9 ? -1 : dp[n];
    }
};
