class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);
        
        // Step 1: Calculate row and column sums
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }

        // Step 2: Find target sum
        int target = 0;
        for (int i = 0; i < n; ++i)
            target = max({target, rowSum[i], colSum[i]});
        
        // Step 3: Increment cells to balance
        int operations = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            int diff = min(target - rowSum[i], target - colSum[j]);
            mat[i][j] += diff;
            rowSum[i] += diff;
            colSum[j] += diff;
            operations += diff;
            
            if (rowSum[i] == target) i++;
            if (colSum[j] == target) j++;
        }

        return operations;
    }
};
