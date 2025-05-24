class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.length();
        long long totalSum = 0;
        long long prevSum = 0;
        int mod = 1000000007; // optional, if large numbers expected

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            prevSum = (prevSum * 10 + (digit * 1LL * (i + 1))) % mod;
            totalSum = (totalSum + prevSum) % mod;
        }

        return (int)totalSum;
    }
};
