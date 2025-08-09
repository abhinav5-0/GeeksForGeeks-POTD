class Solution {
public:
    int getLongestPrefix(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);
        
        // Build LPS array
        int len = 0;
        for (int i = 1; i < n; ) {
            if (s[i] == s[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }
        
        // Try longest prefix from LPS
        int ans = lps[n - 1];
        while (ans > 0) {
            string prefix = s.substr(0, ans);
            string repeated;
            while ((int)repeated.size() < n) repeated += prefix;
            if (repeated.substr(0, n) == s) return ans;
            ans = lps[ans - 1]; // move to smaller possible prefix
        }
        return -1;
    }
};
