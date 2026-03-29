class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        
        for (int x : arr) totalSum += x;
        
        // Edge cases
        if (totalSum < diff || (totalSum + diff) % 2 != 0)
            return 0;
        
        int target = (totalSum + diff) / 2;
        
        // DP array
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[target];
    }
};
