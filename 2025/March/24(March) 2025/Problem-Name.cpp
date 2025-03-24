class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return matrixChainMemo(arr, 1, n - 1, dp);
    }

  private:
    int matrixChainMemo(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return 0; // Base case: No multiplication needed
        if (dp[i][j] != -1) return dp[i][j];
        
        int minCost = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost = matrixChainMemo(arr, i, k, dp) +
                       matrixChainMemo(arr, k + 1, j, dp) +
                       (arr[i - 1] * arr[k] * arr[j]);
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }
};
