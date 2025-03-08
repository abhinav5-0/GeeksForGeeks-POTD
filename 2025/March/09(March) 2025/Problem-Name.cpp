class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) count++;
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     // Odd-length palindrome
            expandAroundCenter(i, i + 1); // Even-length palindrome
        }
        
        return count;
    }
};
