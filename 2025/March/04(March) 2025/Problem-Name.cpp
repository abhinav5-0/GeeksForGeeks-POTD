class Solution {
  public:
    // Function to find length of LIS using Dynamic Programming O(n^2)
    int lis(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1); // dp[i] stores the LIS ending at index i
        
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
    
    // Optimized LIS using Binary Search + DP O(n log n)
    int lisOptimized(vector<int>& arr) {
        vector<int> temp;
        for (int num : arr) {
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if (it == temp.end()) {
                temp.push_back(num);
            } else {
                *it = num;
            }
        }
        return temp.size();
    }
};
