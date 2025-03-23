class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;  // If string starts with '0', it's invalid
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Empty string has 1 way to decode
        dp[1] = 1; // A single non-zero digit has 1 way to decode
        
        for (int i = 2; i <= n; i++) {
            int oneDigit = digits[i - 1] - '0';  // Last digit
            int twoDigits = (digits[i - 2] - '0') * 10 + oneDigit; // Last two digits
            
            if (oneDigit >= 1) { 
                dp[i] += dp[i - 1];  // Single-digit decode
            }
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];  // Two-digit decode
            }
        }
        return dp[n];
    }
};
