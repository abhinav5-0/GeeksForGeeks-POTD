class Solution {
  public:
    vector<vector<string>> res;

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string> &current) {
        if (start == s.size()) {
            res.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current);
                current.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> palinParts(string &s) {
        vector<string> current;
        backtrack(s, 0, current);
        return res;
    }
};
