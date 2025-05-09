class Solution {
  public:
    // Helper function for backtracking
    void findMaximum(string s, int k, string &maxStr, int idx) {
        // Base condition
        if (k == 0)
            return;

        char maxDigit = s[idx];
        // Find the maximum digit from idx to end
        for (int i = idx + 1; i < s.length(); i++) {
            if (s[i] > maxDigit)
                maxDigit = s[i];
        }

        // If maxDigit is not greater than current digit, no useful swap
        if (maxDigit != s[idx])
            k--; // We will use a swap

        for (int i = s.length() - 1; i >= idx; i--) {
            if (s[i] == maxDigit) {
                // Swap if it's not the current index
                swap(s[idx], s[i]);
                if (s.compare(maxStr) > 0)
                    maxStr = s;

                findMaximum(s, k, maxStr, idx + 1); // recurse

                // backtrack
                swap(s[idx], s[i]);
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        string maxStr = s;
        findMaximum(s, k, maxStr, 0);
        return maxStr;
    }
};
