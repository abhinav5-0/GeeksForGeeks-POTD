class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // If the total sum is odd, partition is not possible
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        
        // Create a DP array where dp[i] will be true if a subset with sum i is possible
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // Sum 0 is always possible (empty set)
        
        // Iterate through each element in the array
        for (int num : arr) {
            // Traverse the dp array backward
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        // The answer is true if dp[target] is true
        return dp[target];
    }
};
