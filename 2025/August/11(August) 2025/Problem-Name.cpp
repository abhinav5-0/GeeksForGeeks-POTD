class Solution {
public:
    int maxSum(string &s) {
        int n = s.size();
        vector<int> bestLeft(n, 0), bestRight(n, 0);

        // Step 1: Find all odd palindromes
        for (int center = 0; center < n; center++) {
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                bestLeft[r] = max(bestLeft[r], len);   // largest ending here
                bestRight[l] = max(bestRight[l], len); // largest starting here
                l--;
                r++;
            }
        }

        // Step 2: Prefix max for bestLeft
        for (int i = 1; i < n; i++) {
            bestLeft[i] = max(bestLeft[i], bestLeft[i-1]);
        }

        // Step 3: Suffix max for bestRight
        for (int i = n-2; i >= 0; i--) {
            bestRight[i] = max(bestRight[i], bestRight[i+1]);
        }

        // Step 4: Combine results
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            ans = max(ans, bestLeft[i] + bestRight[i+1]);
        }

        return ans;
    }
};
