class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        
        // Map char -> list of indices
        vector<vector<int>> pos(256);
        for (int i = 0; i < n; i++)
            pos[(unsigned char)s[i]].push_back(i);
        
        // Build allowed jumps
        vector<vector<bool>> allow(256, vector<bool>(256, false));
        for (auto &v : jumps)
            allow[(unsigned char)v[0]][(unsigned char)v[1]] = true;
        
        // Same char always allowed
        for (int c = 0; c < 256; c++)
            allow[c][c] = true;

        // Prefix sums of ascii
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (int)s[i];

        // Prefix char sums
        vector<vector<long long>> pc(256, vector<long long>(n + 1, 0));
        for (int c = 0; c < 256; c++) {
            for (int i = 0; i < n; i++) {
                pc[c][i + 1] = pc[c][i] + (s[i] == c ? (int)c : 0);
            }
        }

        auto getScore = [&](int i, int j) -> long long {
            char c = s[j];
            long long total = pref[j] - pref[i];
            long long sub = pc[(unsigned char)c][j] - pc[(unsigned char)c][i];
            return total - sub;
