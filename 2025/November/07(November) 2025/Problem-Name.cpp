#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // Sort jobs by their end time
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int n = jobs.size();
        vector<int> dp(n);
        
        // Extract end times for binary search
        vector<int> endTimes;
        for (auto &job : jobs) endTimes.push_back(job[1]);
        
        dp[0] = jobs[0][2]; // Base case
        
        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i][2];
            
            // Find last non-overlapping job
            int idx = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][0]) - endTimes.begin() - 1;
            
            if (idx >= 0)
                includeProfit += dp[idx];
            
            dp[i] = max(dp[i-1], includeProfit);
        }
        
        return dp[n-1];
    }
};
