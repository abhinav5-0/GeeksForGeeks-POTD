class Solution {
public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.size() - 1;
        int j = tar.size() - 1;

        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                // Match found, move both
                i--;
                j--;
            } else {
                // Skip this pat char (as it would be pushed & popped)
                i--;
            }
        }

        // If we consumed all of tar, it's possible
        return (j < 0);
    }
};
