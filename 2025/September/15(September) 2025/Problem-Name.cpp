class Solution {
public:
    bool stringStack(string &pat, string &tar) {
        string s = "";
        int j = 0;

        for (char c : pat) {
            if (j < tar.size() && c == tar[j]) {
                // Append to build tar
                s.push_back(c);
                j++;
            } else {
                // Delete operation (if not empty)
                if (!s.empty()) {
                    s.pop_back();
                    // But we can't re-use c anymore
                }
                else {
                    // Stack empty, ignore this c (delete does nothing)
                }
            }
        }

        return s == tar;
    }
};
