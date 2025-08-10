class Solution {
public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        // Function to expand around center and count palindromes
        auto expand = [&](int left, int right) {
            int cnt = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) cnt++; // length >= 2
                left--;
                right++;
            }
            return cnt;
        };

        // Try all possible centers
        for (int i = 0; i < n; i++) {
            count += expand(i, i);     // Odd length center
            count += expand(i, i + 1); // Even length center
        }

        return count;
    }
};
