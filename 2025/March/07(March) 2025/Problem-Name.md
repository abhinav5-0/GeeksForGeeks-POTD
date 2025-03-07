class Solution {
public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[n - j]) 
                    curr[j] = 1 + prev[j - 1];
                else 
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};
