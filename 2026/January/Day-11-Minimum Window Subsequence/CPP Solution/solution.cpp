class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX, start = -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[0]) continue;

            int p1 = i, p2 = 0;

            // forward match
            while (p1 < n && p2 < m) {
                if (s1[p1] == s2[p2]) p2++;
                p1++;
            }

            if (p2 < m) continue; // s2 not matched fully

            // backward shrink
            int end = p1 - 1;
            p2 = m - 1;
            while (p1 >= i) {
                if (s1[p1] == s2[p2]) p2--;
                if (p2 < 0) break;
                p1--;
            }

            int len = end - p1 + 1;
            if (len < minLen) {
                minLen = len;
                start = p1;
            }
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
