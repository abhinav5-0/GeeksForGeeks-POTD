class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        // Left and right boundaries of the rectangle
        for (int left = 0; left < m; ++left) {
            vector<int> temp(n, 0); // Collapse columns into a 1D array
            for (int right = left; right < m; ++right) {
                // Add current column to each row
                for (int i = 0; i < n; ++i)
                    temp[i] += mat[i][right];

                // Apply Kadane's Algorithm on this row-compressed 1D array
                int currSum = temp[0], maxTempSum = temp[0];
                for (int i = 1; i < n; ++i) {
                    currSum = max(temp[i], currSum + temp[i]);
                    maxTempSum = max(maxTempSum, currSum);
                }

                maxSum = max(maxSum, maxTempSum);
            }
        }
        return maxSum;
    }
};
