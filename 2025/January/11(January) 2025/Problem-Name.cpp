class Solution {
public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> last_seen;
        int max_len = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (last_seen.find(s[end]) != last_seen.end() && last_seen[s[end]] >= start) {
                start = last_seen[s[end]] + 1;
            }
            last_seen[s[end]] = end;
            max_len = max(max_len, end - start + 1);
        }

        return max_len;
    }
};
