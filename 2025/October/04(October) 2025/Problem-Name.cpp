class Solution {
public:
    vector<string> findExpr(string &s, int target) {
        vector<string> res;
        string path;
        backtrack(s, target, 0, 0, 0, path, res);
        sort(res.begin(), res.end());
        return res;
    }

private:
    void backtrack(string &s, long long target, int pos, long long eval,
                   long long prevNum, string path, vector<string> &res) {

        // If we reached end of string
        if (pos == s.size()) {
            if (eval == target)
                res.push_back(path);
            return;
        }

        for (int i = pos; i < s.size(); ++i) {
            // Prevent numbers with leading zeros
            if (i != pos && s[pos] == '0') break;

            string curStr = s.substr(pos, i - pos + 1);
            long long curNum = stoll(curStr);

            // If starting number (no operator before)
            if (pos == 0) {
                backtrack(s, target, i + 1, curNum, curNum, curStr, res);
            } else {
                // Try addition
                backtrack(s, target, i + 1, eval + curNum, curNum,
                          path + "+" + curStr, res);
                // Try subtraction
                backtrack(s, target, i + 1, eval - curNum, -curNum,
                          path + "-" + curStr, res);
                // Try multiplication
                backtrack(s, target, i + 1, eval - prevNum + prevNum * curNum,
                          prevNum * curNum, path + "*" + curStr, res);
            }
        }
    }
};

